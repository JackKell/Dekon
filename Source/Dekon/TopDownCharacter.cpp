// Fill out your copyright notice in the Description page of Project Settings.

#include "Dekon.h"
#include "TopDownCharacter.h"


// Sets default values
ATopDownCharacter::ATopDownCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));

	RootComponent = Sprite;

	TileSize = 16;
	WalkSpeed = 2;
	WalkTurnDelay = 0.075f;
	TargetThreshold = 1.0f;
	
	TargetLocation = GetActorLocation();
}

void ATopDownCharacter::BeginPlay() {
	Super::BeginPlay();
}

void ATopDownCharacter::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
}

void ATopDownCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);
}

void ATopDownCharacter::MoveUp(float AxisValue) {
	if (!IsMoving && !IsTurning) {
		if (AxisValue < 0) {
			if (GetOrientation() == Direction::DOWN) {
				// Move 1 tile down
				Move(Direction::DOWN);
			}
			else {
				// Face down
				Turn(Direction::DOWN);
			}
		}
		else if (AxisValue > 0) {
			if (GetOrientation() == Direction::UP) {
				// Move 1 tile up
				Move(Direction::UP);
			}
			else {
				// Face UP
				Turn(Direction::UP);
			}
		}
	}
}

void ATopDownCharacter::MoveRight(float AxisValue)
{
	if (!IsMoving && !IsTurning) {
		if (AxisValue < 0) {
			if (GetOrientation() == Direction::LEFT) {
				// Move 1 tile left
				Move(Direction::LEFT);
			}
			else {
				// Face left
				Turn(Direction::LEFT);
			}
		}
		else if (AxisValue > 0) {
			if (GetOrientation() == Direction::RIGHT) {
				// Move 1 tile right
				Move(Direction::RIGHT);
			}
			else {
				// Face right
				Turn(Direction::RIGHT);
			}
		}
	}
}

void ATopDownCharacter::Move(Direction Direction) {
	IsMoving = true;
	TargetLocation = GetActorLocation();
	DeltaTarget = FVector(0, 0, 0);
	switch (Direction)
	{
	case Direction::UP:
		DeltaTarget.Z += TileSize;
		break;
	case Direction::RIGHT:
		DeltaTarget.X += TileSize;
		break;
	case Direction::DOWN:
		DeltaTarget.Z -= TileSize;
		break;
	case Direction::LEFT:
		DeltaTarget.X -= TileSize;
		break;
	default:
		break;
	}
	TargetLocation += DeltaTarget;
}

void ATopDownCharacter::SetOrientation(Direction NewOrientation) {
	Orientation = NewOrientation;
}

Direction ATopDownCharacter::GetOrientation() {
	return Orientation;
}

bool ATopDownCharacter::IsAtTargetLocation() {
	return GetActorLocation().Equals(TargetLocation, TargetThreshold);
}

void ATopDownCharacter::Turn(Direction Direction) {
	SetOrientation(Direction);
	IsTurning = true;
	TurnDelayTimer = WalkTurnDelay;
}

void ATopDownCharacter::OnBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	SLOG("%s Entered overlap", *OtherActor->GetName());
	if (Cast<ATopDownCharacter>(OtherActor)) {
		SLOG("It's a top down character!");
	}
}

void ATopDownCharacter::OnEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	SLOG("%s Left overlap", *OtherActor->GetName());
	if (Cast<ATopDownCharacter>(OtherActor)) {
		SLOG("It's a top down character!");
	}
}