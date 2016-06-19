// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PaperFlipbookComponent.h"
#include "TopDownCharacter.generated.h"

// Direction enum
UENUM(BlueprintType)
enum class Direction : uint8 {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

UCLASS()
class DEKON_API ATopDownCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATopDownCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// COMPONENTS

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Components")
	UPaperFlipbookComponent* Sprite;

	// Dev Variables

	// The size of each grid tile in unreal units
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	int TileSize;

	// The walk speed in tiles per second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	float WalkSpeed;

	// The run speed in tiles per second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	float RunSpeed;

	// The distance at which the player will snap to the target location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	float TargetThreshold;

	// The amount of time it takes for the player to change orientation while walking
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	float WalkTurnDelay;

	// The amount of time it takes for the player to change orientation while running
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	float RunTurnDelay;

	// Internal Variables

	// The current direction the player trainer is facing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDC Variables")
	Direction Orientation = Direction::DOWN;

	// The location that the player is moving too
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Variables")
	FVector TargetLocation;

	// The amount the player will have to move to get from the current location to the target location
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Variables")
	FVector DeltaTarget;

	// If the player is moving
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Variables")
	bool IsMoving;

	// If the player is running
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Variables")
	bool IsRunning;

	// If the player is changing orientation
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Variables")
	bool IsTurning;

	// The amount of time the player will have to wait when turning
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TDC Variables")
	float TurnDelayTimer;

	// Functions

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void MoveUp(float AxisValue);

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void MoveRight(float AxisValue);

	UFUNCTION(BlueprintCallable, Category = "Trainer Functions")
	void Move(Direction Direction);

	UFUNCTION(BlueprintCallable, Category = "Trainer Functions")
	void Turn(Direction Direction);

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	bool IsAtTargetLocation();

	UFUNCTION(BlueprintCallable, Category = "Trainer Functions")
	void SetOrientation(Direction NewOrientation);

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void ActivateRun();

	UFUNCTION(meta = (BlueprintInternalUseOnly))
	void DeactivateRun();

	UFUNCTION(BlueprintCallable, Category = "Trainer Functions")
	Direction GetOrientation();
	
};
