// Fill out your copyright notice in the Description page of Project Settings.



#include "Combat/LockonComponent.h"

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

	// ...

}


// Called every frame
void ULockonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULockonComponent::StartLockon() // CONTINUE FROM THESE LINES!!!!!
{	
	FHitResult OutResult;
	FVector CurrentLocation{ GetOwner()->GetActorLocation() };
	FCollisionShape Sphere{ FCollisionShape::MakeSphere(750.0f) };
	FCollisionQueryParams IgnoreParams{
		FName { TEXT ("Ignore Collision Parameters")},
		false,
		GetOwner ()

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
	
	UE_LOG(
		LogTemp, Warning, TEXT("Actor Detected: %s"),
		*OutResult.GetActor()->GetName()
	);
}


