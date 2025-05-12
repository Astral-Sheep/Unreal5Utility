// Copyright Thomas SURBON. All rights reserved.

#pragma once

class DebugUtility
{
public:
	inline static constexpr FColor WarningColor = FColor(255, 177, 0);
	inline static constexpr FColor ErrorColor = FColor(255, 177, 177);

public:
	// Print a message on screen
	// This function does nothing in shipping build
	FORCEINLINE static void Print(
		const FString& Message,
		const float Duration = 5.f,
		const FColor Color = FColor(0, 177, 255),
		const int Key = INDEX_NONE,
		const bool NewerOnTop = true,
		const FVector2D TextScale = FVector2D::UnitVector
	)
	{
#if !UE_BUILD_SHIPPING
		UE_LOG(LogTemp, Display, TEXT("%s"), *Message)
#endif //UE_BUILD_SHIPPING

		_Print(Message, Duration, Color, Key, NewerOnTop, TextScale);
	}

	FORCEINLINE static void PrintWarning(
		const FString& Message,
		const float Duration = 5.f,
		const int Key = INDEX_NONE,
		const bool NewerOnTop = true,
		const FVector2D TextScale = FVector2D::UnitVector
	)
	{
#if !UE_BUILD_SHIPPING
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Message)
#endif //UE_BUILD_SHIPPING

		_Print(Message, Duration, WarningColor, Key, NewerOnTop, TextScale);
	}

	FORCEINLINE static void PrintError(
		const FString& Message,
		const float Duration = 5.f,
		const int Key = INDEX_NONE,
		const bool NewerOnTop = true,
		const FVector2D TextScale = FVector2D::UnitVector
	)
	{
#if !UE_BUILD_SHIPPING
		UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
#endif //UE_BUILD_SHIPPING

		_Print(Message, Duration, ErrorColor, Key, NewerOnTop, TextScale);
	}

private:
	FORCEINLINE static void _Print(
		const FString& Message,
		const float Duration = 5.f,
		const FColor Color = FColor(0, 177, 255),
		const int Key = INDEX_NONE,
		const bool NewerOnTop = true,
		const FVector2D TextScale = FVector2D::UnitVector
	)
	{
#if !UE_BUILD_SHIPPING
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, Duration, Color, Message, NewerOnTop, TextScale);
		}
#endif //UE_BUILD_SHIPPING
	}
};

#ifndef LOG
#define LOG(format, ...) ::DebugUtility::Print(FString::Printf(TEXT(format), ##__VA_ARGS__))
#endif //LOG

#ifndef WARN
#define WARN(format, ...) ::DebugUtility::PrintWarning(FString::Printf(TEXT(format), ##__VA_ARGS__))
#endif //WARN

#ifndef ERROR
#define ERROR(format, ...) ::DebugUtility::PrintError(FString::Printf(TEXT(format), ##__VA_ARGS__))
#endif //ERROR
