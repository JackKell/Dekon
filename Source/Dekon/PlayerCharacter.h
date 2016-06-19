// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TopDownCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DEKON_API APlayerCharacter : public ATopDownCharacter
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trainer Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trainer Components")
	USpringArmComponent* CameraSpring;
	
	// The run speed in tiles per second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC Variables")
	float RunSpeed;

	// If the player is running
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Variables")
	bool IsRunning;

	// The amount of time it takes for the player to change orientation while running
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	float RunTurnDelay;

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void ActivateRun();

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void DeactivateRun();
};