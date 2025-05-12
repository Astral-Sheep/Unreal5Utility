// Copyright Thomas SURBON. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorUtility.generated.h"

/**
 * Function library containing utility functions for actors and components
 */
UCLASS()
class ASTRALUTILITY_API UActorUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetActorWorldForwardVector(AActor* const Actor, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetActorWorldRightVector(AActor* const Actor, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetActorWorldUpVector(AActor* const Actor, const FVector UpVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetActorLocalForwardVector(AActor* const Actor, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetActorLocalRightVector(AActor* const Actor, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetActorLocalUpVector(AActor* const Actor, const FVector UpVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentWorldForwardVector(USceneComponent* const Component, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentWorldRightVector(USceneComponent* const Component, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentWorldUpVector(USceneComponent* const Component, const FVector UpVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentLocalForwardVector(USceneComponent* const Component, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentLocalRightVector(USceneComponent* const Component, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentLocalUpVector(USceneComponent* const Component, const FVector UpVector, const bool Teleport = false);
};
