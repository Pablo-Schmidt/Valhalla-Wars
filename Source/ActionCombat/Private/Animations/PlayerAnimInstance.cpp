// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/PlayerAnimInstance.h"

void UPlayerAnimInstance::UpdateVelocity()
{
	APawn* PawnRef{ TryGetPawnOwner() };

	if (!IsValid(PawnRef)) { return; }

	FVector Velocity{ PawnRef->GetVelocity() };

	CurrentVelocity = static_cast<float> (Velocity.Length());

}