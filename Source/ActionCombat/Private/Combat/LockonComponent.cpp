// Fill out your copyright notice in the Description page of Project Settings.



#include "Combat/LockonComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
ULockonComponent::ULockonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULockonComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerRef = GetOwner<ACharacter>();
	Controller = GetWorld()->GetFirstPlayerController();
	MovementComp = OwnerRef->GetCharacterMovement();

}


// Called every frame
void ULockonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsValid(CurrentTargetActor))
	{
		return;
	}
	FVector CurrentLocation{ OwnerRef->GetActorLocation() };
	FVector TargetLocation{ CurrentTargetActor->GetActorLocation() };
	FRotator NewRotation {UKismetMathLibrary::FindLookAtRotation(
		CurrentLocation, TargetLocation
	)};

	Controller->SetControlRotation(NewRotation);
}

void ULockonComponent::StartLockon(float Radius) 
{	
	FHitResult OutResult;
	FVector CurrentLocation{ OwnerRef->GetActorLocation() };
	FCollisionShape Sphere{ FCollisionShape::MakeSphere(750.0f) };
	FCollisionQueryParams IgnoreParams{
		FName { TEXT ("Ignore Collision Parameters")},
		false,
		OwnerRef

	};
	Sphere;
	//detectes collision
	bool BHasFoundTarget { GetWorld()->SweepSingleByChannel(
		OutResult,

		CurrentLocation,
		CurrentLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		Sphere,
		IgnoreParams
	)};

	if (!BHasFoundTarget) { return;  }

	CurrentTargetActor = OutResult.GetActor();
	
	Controller->SetIgnoreLookInput(true);
	MovementComp->bOrientRotationToMovement = false;
	MovementComp->bUseControllerDesiredRotation = true;


	UE_LOG(
		LogTemp, Warning, TEXT("Actor Detected: %s"),
		*OutResult.GetActor()->GetName()
	);
}


