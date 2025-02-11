// Copyright Epic Games, Inc. All Rights Reserved.

#include "GravityBPLibrary.h"
#include "Gravity.h"

/*
UGravityBPLibrary::UGravityBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}
*/

FVector UGravityBPLibrary::CalculateGravityDirection(AActor* a, AActor* b)
{
	FVector c;
	c = (b->GetActorLocation() - a->GetActorLocation()).GetSafeNormal();

	return c;


}


