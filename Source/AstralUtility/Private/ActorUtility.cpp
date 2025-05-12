// Copyright Thomas SURBON. All rights reserved.

#include "ActorUtility.h"

#include "Kismet/KismetMathLibrary.h"

// I test if a pointer is null before testing if it is valid because I had occurencies where IsValid made the game crash

void UActorUtility::SetActorWorldForwardVector(AActor* const Actor, const FVector ForwardVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	Actor->SetActorRotation(
		UKismetMathLibrary::MakeRotFromXZ(ForwardVector, Actor->GetActorUpVector()),
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetActorWorldRightVector(AActor* const Actor, const FVector RightVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	Actor->SetActorRotation(
		UKismetMathLibrary::MakeRotFromYZ(RightVector, Actor->GetActorUpVector()),
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}

void UActorUtility::SetActorWorldUpVector(AActor* const Actor, const FVector UpVector, const bool Teleport)
{
	if (Actor == nullptr || !IsValid(Actor))
		return;

	Actor->SetActorRotation(
		UKismetMathLibrary::MakeRotFromZX(UpVector, Actor->GetActorForwardVector()),
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
		UKismetMathLibrary::MakeRotFromXZ(ForwardVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetUpVector())),
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
		UKismetMathLibrary::MakeRotFromYZ(RightVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetUpVector())),
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
		UKismetMathLibrary::MakeRotFromZX(UpVector, lWorldToLocalTransform.InverseTransformVector(lRootComponent->GetForwardVector())),
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
		UKismetMathLibrary::MakeRotFromXZ(ForwardVector, Component->GetUpVector()),
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
		UKismetMathLibrary::MakeRotFromYZ(RightVector, Component->GetUpVector()),
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
		UKismetMathLibrary::MakeRotFromZX(UpVector, Component->GetForwardVector()),
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
		UKismetMathLibrary::MakeRotFromXZ(ForwardVector, lWorldToLocal.InverseTransformVector(Component->GetUpVector())),
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
		UKismetMathLibrary::MakeRotFromYZ(RightVector, lWorldToLocal.InverseTransformVector(Component->GetUpVector())),
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
		UKismetMathLibrary::MakeRotFromZX(UpVector, lWorldToLocal.InverseTransformVector(Component->GetForwardVector())),
		false,
		nullptr,
		Teleport ? ETeleportType::TeleportPhysics : ETeleportType::None
	);
}
