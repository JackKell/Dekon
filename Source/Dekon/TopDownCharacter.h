// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Pawn.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "TopDownCharacter.generated.h"

UENUM(BlueprintType)
enum class Direction : uint8 {
	UP UMETA(DisplayName="Up"),
	RIGHT UMETA(DisplayName = "Right"),
	DOWN UMETA(DisplayName = "Down"),
	LEFT UMETA(DisplayName = "Left")
};

UCLASS()
class DEKON_API ATopDownCharacter : public APawn {
	GENERATED_BODY()

public:
	ATopDownCharacter();

	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(meta = (BlueprintInternalUseOnly), Category = "TDC Functions")
	void MoveUp(float AxisValue);

	UFUNCTION(meta = (BlueprintInternalUseOnly), Category = "TDC Functions")
	void MoveRight(float AxisValue);

	UFUNCTION(BlueprintCallable, Category = "TDC Functions")
	void Move(Direction Direction);

	UFUNCTION(BlueprintCallable, Category = "TDC Functions")
	virtual void Turn(Direction Direction);

	UFUNCTION(meta = (BlueprintInternalUseOnly), Category = "TDC Functions")
	bool IsAtTargetLocation();

	UFUNCTION(BlueprintCallable, Category = "TDC Functions")
	void SetOrientation(Direction NewOrientation);

	UFUNCTION(BlueprintCallable, Category = "TDC Functions")
	Direction GetOrientation();

	virtual void OnBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	virtual void OnEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC Components")
	UPaperFlipbookComponent* Sprite;

	// The walk speed in tiles per second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Movement")
	float WalkSpeed;

	// The amount of time it takes for the player to change orientation while walking
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Movement")
	float WalkTurnDelay;

	// The distance at which the player will snap to the target location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Movement")
	float TargetThreshold;

	// The size of each grid tile in unreal units
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Movement")
	int TileSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* IdleRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* IdleLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* IdleUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* IdleDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* WalkRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* WalkLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* WalkUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDC|Animation")
	UPaperFlipbook* WalkDown;

	// The current direction the player trainer is facing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDC|Movement")
	Direction Orientation = Direction::DOWN;

	// The location that the player is moving too
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC|Movement|Debug")
	FVector TargetLocation;

	// The amount the player will have to move to get from the current location to the target location
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC|Movement|Debug")
	FVector DeltaTarget;

	// If the player is moving
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC|Movement|Debug")
	bool IsMoving;

	// If the player is changing orientation
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TDC|Movement|Debug")
	bool IsTurning;

	// The amount of time the player will have to wait when turning
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TDC|Movement|Debug")
	float TurnDelayTimer;

	FAttachmentTransformRules rootAttachmentRule = FAttachmentTransformRules(EAttachmentRule::KeepRelative, false);
};
