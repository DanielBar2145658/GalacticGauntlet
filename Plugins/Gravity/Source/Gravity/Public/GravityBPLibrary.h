// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GravityBPLibrary.generated.h"


UCLASS()
class UGravityBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure)
	static FVector CalculateGravityDirection(AActor* a, AActor* b);

};
