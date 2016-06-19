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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Components")
	USpringArmComponent* CameraSpring;
	
	// The run speed in tiles per second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Movement")
	float RunSpeed;

	// The amount of time it takes for the player to change orientation while running
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Movement")
	float RunTurnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunDown;

	// If the player is running
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC|Movement")
	bool IsRunning;

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void ActivateRun();

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void DeactivateRun();
};
