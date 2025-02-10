// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Project/Tutorial/CPP/MyCharacter.h"

#include "Camera/CameraComponent.h"

// Sets default values when Unreal Engine Starts
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera-> bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input (Controller or Mouse)
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAxis("Move Forward/Backward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Left/Right", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Camera Movement", this, &AMyCharacter::CameraMovement);
	PlayerInputComponent->BindAxis("Look Up", this, &AMyCharacter::LookUp);
}

void AMyCharacter::MoveForward(float InputValue)
{
		FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void AMyCharacter::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void AMyCharacter::LookUp(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

void AMyCharacter::CameraMovement(float InputValue)
{
	AddControllerYawInput(InputValue);
}

