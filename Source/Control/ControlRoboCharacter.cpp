// Copyright Epic Games, Inc. All Rights Reserved.

#include "ControlRoboCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"

//////////////////////////////////////////////////////////////////////////
// AControlRoboCharacter

AControlRoboCharacter::AControlRoboCharacter()
	:AControlCharacter()
{
}


void AControlRoboCharacter::Move_Implementation(const FVector2D& Value)
{
	MoveInputVector = Value;

	if (Controller != nullptr)
	{
		// get forward vector
		FVector ForwardDirection = GetActorForwardVector();
		ForwardDirection.Normalize();

		// add movement 
		if (0 < FMath::Abs(MoveInputVector.Y))
		{
			AddMovementInput(ForwardDirection, MoveInputVector.Y);
		}

		if (0 < FMath::Abs(MoveInputVector.X))
		{
			FRotator Rotator = FRotator::MakeFromEuler(FVector(0, 0, MoveInputVector.X));
			AddActorLocalRotation(Rotator);
		}
	}
}