// Fill out your copyright notice in the Description page of Project Settings.

#include "Dekon.h"
#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	// The camera spring is created and initalized
	CameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpring->AttachToComponent(RootComponent, rootAttachmentRule);
	CameraSpring->SetRelativeRotation(FRotator(0, -90.0f, 0));
	CameraSpring->TargetArmLength = 200.0f;
	CameraSpring->bEnableCameraLag = false;
	CameraSpring->CameraLagSpeed = 0.0f;
	CameraSpring->SetRelativeLocation(FVector(8.0f, 0.0f, 8.0f));

	// Camera is created and initalized
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	Camera->OrthoWidth = 200;
	Camera->AttachToComponent(CameraSpring, rootAttachmentRule, USpringArmComponent::SocketName);
	Camera->SetRelativeScale3D(FVector(0.01f, 0.01f, 0.01f));

	RunSpeed = 6;
	RunTurnDelay = 0.06f;
	TargetLocation = GetActorLocation();
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlayerCharacter::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	if (IsTurning) {
		TurnDelayTimer -= DeltaSeconds;
		if (TurnDelayTimer <= 0) {
			IsTurning = false;
			TurnDelayTimer = 0;
		}
		return;
	}

	if (IsMoving) {
		FVector DeltaLocation = FVector(0, 0, 0);
		if (IsRunning) {
			DeltaLocation = DeltaTarget * RunSpeed * DeltaSeconds;
		}
		else {
			DeltaLocation = DeltaTarget * WalkSpeed * DeltaSeconds;
		}
		SetActorLocation(GetActorLocation() + DeltaLocation);

		if (IsAtTargetLocation()) {
			SetActorLocation(TargetLocation);
			IsMoving = false;
		}
	}
}

void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveUp", this, &APlayerCharacter::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	InputComponent->BindAction("Run", IE_Pressed, this, &APlayerCharacter::ActivateRun);
	InputComponent->BindAction("Run", IE_Released, this, &APlayerCharacter::DeactivateRun);
}

void APlayerCharacter::Turn(Direction Direction) {
	SetOrientation(Direction);
	IsTurning = true;
	if (IsRunning) {
		TurnDelayTimer = RunTurnDelay;
	}
	else {
		TurnDelayTimer = WalkTurnDelay;
	}
}

void APlayerCharacter::ActivateRun() {
	IsRunning = true;
}

void APlayerCharacter::DeactivateRun() {
	IsRunning = false;
}
