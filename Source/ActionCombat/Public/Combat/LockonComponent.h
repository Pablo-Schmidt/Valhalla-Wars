// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockonComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(
	FOnUpdatedTargetSignature,
	ULockonComponent, OnUpdatedTargetDelegate,
	AActor*, NewTargetActorRef
);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ACTIONCOMBAT_API ULockonComponent : public UActorComponent
{
	GENERATED_BODY()

	ACharacter* OwnerRef;

	APlayerController* Controller;

	class UCharacterMovementComponent* MovementComp;

	class USpringArmComponent* SpringArmComp;

public:
	// Sets default values for this component's properties
	ULockonComponent();

	AActor* CurrentTargetActor;

	UPROPERTY(BlueprintAssignable)
	FOnUpdatedTargetSignature OnUpdatedTargetDelegate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void StartLockon(float Radius = 750.0f);

	void EndLockon();

	UFUNCTION(BlueprintCallable)
	void ToggleLockon(float Radius = 750.0f);

	UPROPERTY(EditAnywhere)
	double BreakDistance{ 1000.0 };
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
