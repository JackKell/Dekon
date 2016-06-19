// Fill out your copyright notice in the Description page of Project Settings.

#include "Dekon.h"
#include "PlayerCharacter.h"


APlayerCharacter::APlayerCharacter() {
	RunTurnDelay = 0.06f;
	RunSpeed = 6;

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// The camera spring is created and initalized
	CameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpring->AttachTo(RootComponent);
	CameraSpring->SetRelativeRotation(FRotator(0, -90.0f, 0));
	CameraSpring->TargetArmLength = 200.0f;
	CameraSpring->bEnableCameraLag = false;
	CameraSpring->CameraLagSpeed = 0.0f;
	CameraSpring->SetRelativeLocation(FVector(8.0f, 0.0f, 8.0f));

	// Camera is created and initalized
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	Camera->OrthoWidth = 200;
	Camera->AttachTo(CameraSpring, USpringArmComponent::SocketName);
	Camera->SetRelativeScale3D(FVector(0.01f, 0.01f, 0.01f));

	TileSize = 16;

	WalkSpeed = 2;

	RunSpeed = 6;

	WalkTurnDelay = 0.075f;
	RunTurnDelay = 0.06f;

	TargetLocation = GetActorLocation();

	// Take control the default player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlayerCharacter::BeginPlay() {
	Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}

void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);
}

void APlayerCharacter::ActivateRun() {
	IsRunning = true;
}

void APlayerCharacter::DeactivateRun() {
	IsRunning = false;
}
