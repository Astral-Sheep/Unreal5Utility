// Copyright Thomas SURBON. All rights reserved.

#include "ActorUtility.h"

#include "Kismet/KismetMathLibrary.h"

// I test if a pointer is null before testing if it is valid because I had occurencies where IsValid made the game crash

void UActorUtility::SetActorWorldForwardVector(AActor* const Actor, const FVector ForwardVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	Actor->SetActorRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromXY(ForwardVector, Actor->GetActorRightVector()).Pitch,
			UKismetMathLibrary::MakeRotFromXZ(ForwardVector, Actor->GetActorUpVector()).Yaw,
			Actor->GetActorRotation().Roll
		),
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetActorWorldRightVector(AActor* const Actor, const FVector RightVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	Actor->SetActorRotation(
		FRotator(
			Actor->GetActorRotation().Pitch,
			UKismetMathLibrary::MakeRotFromYZ(RightVector, Actor->GetActorUpVector()).Yaw,
			UKismetMathLibrary::MakeRotFromYX(RightVector, Actor->GetActorForwardVector()).Roll
		),
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetActorWorldUpVector(AActor* const Actor, const FVector UpVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	Actor->SetActorRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromZY(UpVector, Actor->GetActorRightVector()).Pitch,
			Actor->GetActorRotation().Yaw,
			UKismetMathLibrary::MakeRotFromZX(UpVector, Actor->GetActorForwardVector()).Roll
		),
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetActorLocalForwardVector(AActor* const Actor, const FVector ForwardVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	if (Actor->GetAttachParentActor() == nullptr)
	{
		SetActorWorldForwardVector(Actor, ForwardVector, Teleport);
		return;
	}

	USceneComponent *const lRootComponent = Actor->GetRootComponent();
	const FTransform lWorldToLocalTransform = Actor->GetAttachParentActor()->GetActorTransform();

	lRootComponent->SetRelativeRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromXY(ForwardVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetRightVector())).Pitch,
			UKismetMathLibrary::MakeRotFromXZ(ForwardVector, lWorldToLocalTransform.InverseTransformVector(Actor->GetActorUpVector())).Yaw,
			lRootComponent->GetRelativeRotation().Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetActorLocalRightVector(AActor* const Actor, const FVector RightVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	if (Actor->GetAttachParentActor() == nullptr)
	{
		SetActorWorldRightVector(Actor, RightVector, Teleport);
		return;
	}

	USceneComponent *const lRootComponent = Actor->GetRootComponent();
	const FTransform lWorldToLocalTransform = Actor->GetAttachParentActor()->GetActorTransform();

	lRootComponent->SetRelativeRotation(
		FRotator(
			lRootComponent->GetRelativeRotation().Pitch,
			UKismetMathLibrary::MakeRotFromYZ(RightVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetUpVector())).Yaw,
			UKismetMathLibrary::MakeRotFromYX(RightVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetForwardVector())).Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetActorLocalUpVector(AActor* const Actor, const FVector UpVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	if (Actor->GetAttachParentActor() == nullptr)
	{
		SetActorWorldUpVector(Actor, UpVector, Teleport);
		return;
	}

	USceneComponent *const lRootComponent = Actor->GetRootComponent();
	const FTransform lWorldToLocalTransform = Actor->GetAttachParentActor()->GetActorTransform();

	lRootComponent->SetRelativeRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromZY(UpVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetRightVector())).Pitch,
			lRootComponent->GetRelativeRotation().Yaw,
			UKismetMathLibrary::MakeRotFromZX(UpVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetForwardVector())).Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetComponentWorldForwardVector(USceneComponent* const Component, const FVector ForwardVector, const bool Teleport)
{
	if (Component == nullptr || !IsValid(Component))
		return;

	Component->SetWorldRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromXY(ForwardVector, Component->GetRightVector()).Pitch,
			UKismetMathLibrary::MakeRotFromXZ(ForwardVector, Component->GetUpVector()).Yaw,
			Component->GetComponentRotation().Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetComponentWorldRightVector(USceneComponent* const Component, const FVector RightVector, const bool Teleport)
{
	if (Component == nullptr || !IsValid(Component))
		return;

	Component->SetWorldRotation(
		FRotator(
			Component->GetComponentRotation().Pitch,
			UKismetMathLibrary::MakeRotFromYZ(RightVector, Component->GetUpVector()).Yaw,
			UKismetMathLibrary::MakeRotFromYX(RightVector, Component->GetForwardVector()).Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetComponentWorldUpVector(USceneComponent* const Component, const FVector UpVector, const bool Teleport)
{
	if (Component == nullptr || !IsValid(Component))
		return;

	Component->SetWorldRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromZY(UpVector, Component->GetRightVector()).Pitch,
			Component->GetComponentRotation().Yaw,
			UKismetMathLibrary::MakeRotFromZX(UpVector, Component->GetForwardVector()).Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetComponentLocalForwardVector(USceneComponent* const Component, const FVector ForwardVector, const bool Teleport)
{
	if (Component == nullptr || !IsValid(Component))
		return;

	if (Component->GetAttachmentRoot() == Component)
	{
		SetComponentWorldForwardVector(Component, ForwardVector, Teleport);
		return;
	}

	const FTransform lWorldToLocal = Component->GetAttachParent()->GetComponentTransform();

	Component->SetRelativeRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromXY(ForwardVector, lWorldToLocal.InverseTransformVector(Component->GetRightVector())).Pitch,
			UKismetMathLibrary::MakeRotFromXZ(ForwardVector, lWorldToLocal.InverseTransformVector(Component->GetUpVector())).Yaw,
			Component->GetRelativeRotation().Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetComponentLocalRightVector(USceneComponent* const Component, const FVector RightVector, const bool Teleport)
{
	if (Component == nullptr || !IsValid(Component))
		return;

	if (Component->GetAttachmentRoot() == Component)
	{
		SetComponentWorldRightVector(Component, RightVector, Teleport);
		return;
	}

	const FTransform lWorldToLocal = Component->GetAttachParent()->GetComponentTransform();

	Component->SetRelativeRotation(
		FRotator(
			Component->GetRelativeRotation().Pitch,
			UKismetMathLibrary::MakeRotFromYZ(RightVector, lWorldToLocal.InverseTransformVector(Component->GetUpVector())).Yaw,
			UKismetMathLibrary::MakeRotFromYX(RightVector, lWorldToLocal.InverseTransformVector(Component->GetForwardVector())).Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetComponentLocalUpVector(USceneComponent* const Component, const FVector UpVector, const bool Teleport)
{
	if (Component == nullptr || !IsValid(Component))
		return;

	if (Component->GetAttachmentRoot() == Component)
	{
		SetComponentWorldUpVector(Component, UpVector, Teleport);
		return;
	}

	const FTransform lWorldToLocal = Component->GetAttachParent()->GetComponentTransform();

	Component->SetRelativeRotation(
		FRotator(
			UKismetMathLibrary::MakeRotFromZY(UpVector, lWorldToLocal.InverseTransformVector(Component->GetRightVector())).Pitch,
			Component->GetRelativeRotation().Yaw,
			UKismetMathLibrary::MakeRotFromZX(UpVector, lWorldToLocal.InverseTransformVector(Component->GetForwardVector())).Roll
		),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}
