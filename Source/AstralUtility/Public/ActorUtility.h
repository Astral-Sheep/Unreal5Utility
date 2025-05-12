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
	// -- AXIS SETTERS --

#pragma region ACTOR

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport", DefaultToSelf="Actor"))
	static void SetActorWorldForwardVector(AActor *const Actor, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport", DefaultToSelf="Actor"))
	static void SetActorWorldRightVector(AActor *const Actor, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport", DefaultToSelf="Actor"))
	static void SetActorWorldUpVector(AActor *const Actor, const FVector UpVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport", DefaultToSelf="Actor"))
	static void SetActorLocalForwardVector(AActor *const Actor, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport", DefaultToSelf="Actor"))
	static void SetActorLocalRightVector(AActor *const Actor, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport", DefaultToSelf="Actor"))
	static void SetActorLocalUpVector(AActor *const Actor, const FVector UpVector, const bool Teleport = false);

#pragma endregion //ACTOR

#pragma region COMPONENT

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentWorldForwardVector(USceneComponent *const Component, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentWorldRightVector(USceneComponent *const Component, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentWorldUpVector(USceneComponent *const Component, const FVector UpVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentLocalForwardVector(USceneComponent *const Component, const FVector ForwardVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentLocalRightVector(USceneComponent *const Component, const FVector RightVector, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SetComponentLocalUpVector(USceneComponent *const Component, const FVector UpVector, const bool Teleport = false);

#pragma endregion //COMPONENT

	// -- MISCELLANEOUS --

#pragma region SNAPPING

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="SnapCollisionOnly, Teleport", DefaultToSelf="Actor"))
	static void SnapActorOnPoint(AActor *const Actor, const FVector PointLocation, const FVector PointNormal, const bool SnapCollisionOnly = false, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SnapComponentOnPoint(USceneComponent *const Component, const FVector PointLocation, const FVector PointNormal, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SnapPrimitiveOnPoint(UPrimitiveComponent *const Primitive, const FVector PointLocation, const FVector PointNormal, const bool Teleport = false);

	UFUNCTION(BlueprintCallable, Category="Transformation", meta=(AdvancedDisplay="Teleport"))
	static void SnapShapeOnPoint(UShapeComponent *const Shape, const FVector PointLocation, const FVector PointNormal, const bool Teleport = false);

#pragma endregion //SNAPPING
};
