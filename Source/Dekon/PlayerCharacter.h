// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TopDownCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class DEKON_API APlayerCharacter : public ATopDownCharacter
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void Turn(Direction Direction) override;

protected:
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

	// If the player is running
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC|Movement|Debug")
	bool IsRunning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* RunDown;

	// Sets is running to true
	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void ActivateRun();

	// Sets is running to false
	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void DeactivateRun();
};
