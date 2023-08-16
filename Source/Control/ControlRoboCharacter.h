// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ControlCharacter.h"
#include "ControlRoboCharacter.generated.h"


UCLASS(config=Game)
class AControlRoboCharacter : public AControlCharacter
{
	GENERATED_BODY()


public:
	AControlRoboCharacter();

protected:

	virtual void Move_Implementation(const FVector2D& Value) override;
};

