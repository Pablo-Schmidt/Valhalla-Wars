// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainCharacter.h"
#include "Animations/PlayerAnimInstance.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerAnim = Cast<UPlayerAnimInstance>(
		GetMesh()->GetAnimInstance()
	);
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//TEST
	if (PlayerAnim)
	{
				PlayerAnim->UpdateDirection(); // Ensure this is being called each frame
	}
	//TEST
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

