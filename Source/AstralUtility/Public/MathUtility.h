// Copyright Thomas SURBON. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathUtility.generated.h"

/**
 * Function library containing usual math functions
 */
UCLASS()
class ASTRALUTILITY_API UMathUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// -- ARITHMETIC OPERATORS --

#pragma region NEGATE

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer", DisplayName="Negate", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static int NegateInt(const int Value) { return -Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer64", DisplayName="Negate", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static int64 NegateInt64(const int64 Value) { return -Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="Negate (simple-precision)", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static float NegateFloat(const float Value) { return -Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="Negate (double-precision)", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static double NegateDouble(const double Value) { return -Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="Negate", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static FVector4 NegateVector4(const FVector4 &Value) { return -Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="Negate", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static FVector NegateVector(const FVector &Value) { return -Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="Negate", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static FVector2D NegateVector2D(const FVector2D &Value) { return -Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Rotator", DisplayName="Negate", meta=(CompactNodeTitle="-", Keywords="- negate"))
	static FRotator NegateRotator(const FRotator &Rotator) { return FRotator(-Rotator.Pitch, -Rotator.Yaw, -Rotator.Roll); }

#pragma endregion //NEGATE

#pragma region MOD

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="Mod", meta=(CompactNodeTitle="%", Keywords="% modulus modulo"))
	static FVector4 ModVector4(const FVector4 &A, const FVector4 &B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="Mod", meta=(CompactNodeTitle="%", Keywords="% modulus modulo"))
	static FVector ModVector(const FVector &A, const FVector &B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="Mod", meta=(CompactNodeTitle="%", Keywords="% modulus modulo"))
	static FVector2D ModVector2D(const FVector2D &A, const FVector2D &B);

#pragma endregion //MOD

#pragma region POS_MOD

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer", DisplayName="PosMod", meta=(CompactNodeTitle="% (+)", Keywords="% + positive modulus modulo"))
	static int PosModInt(const int A, const int B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer64", DisplayName="PosMod", meta=(CompactNodeTitle="% (+)", Keywords="% + positive modulus modulo"))
	static int64 PosModInt64(const int64 A, const int64 B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="PosMod (single-precision)", meta=(CompactNodeTitle="% (+)", Keywords="% + positive modulus modulo"))
	static float PosModFloat(const float A, const float B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="PosMod (double-precision)", meta=(CompactNodeTitle="% (+)", Keywords="% + positive modulus modulo"))
	static double PosModDouble(const double A, const double B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="PosMod", meta=(CompactNodeTitle="% (+)", Keywords="% + positive modulus modulo"))
	static FVector4 PosModVector4(const FVector4 &A, const FVector4 &B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="PosMod", meta=(CompactNodeTitle="% (+)", Keywords="% + positive modulus modulo"))
	static FVector PosModVector(const FVector &A, const FVector &B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="PosMod", meta=(CompactNodeTitle="% (+)", Keywords="% + positive modulus modulo"))
	static FVector2D PosModVector2D(const FVector2D &A, const FVector2D &B);

#pragma endregion //POS_MOD

#pragma region BITWISE

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Byte", DisplayName="Bitwise NOT", meta=(CompactNodeTitle="~", Keywords="~ bitwise and"))
	static uint8 BitwiseNotByte(const uint8 A) { return ~A; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Byte", DisplayName="Bitwise AND", meta=(CompactNodeTitle="&", Keywords="& bitwise and"))
	static uint8 BitwiseAndByte(const uint8 A, const uint8 B) { return A & B; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Byte", DisplayName="Bitwise OR", meta=(CompactNodeTitle="|", Keywords="| bitwise and"))
	static uint8 BitwiseOrByte(const uint8 A, const uint8 B) { return A | B; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Byte", DisplayName="Bitwise XOR", meta=(CompactNodeTitle="^", Keywords="^ bitwise and"))
	static uint8 BitwiseXorByte(const uint8 A, const uint8 B) { return A ^ B; }

#pragma endregion //BITWISE

#pragma region BITWISE_SHIFT

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Byte", DisplayName="Bitwise Left Shift", meta=(CompactNodeTitle="<<", Keywords="<< bitwise left shift"))
	static uint8 BitwiseLeftShiftByte(const uint8 A, const uint8 B) { return A << B; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Byte", DisplayName="Bitwise Right Shift", meta=(CompactNodeTitle=">>", Keywords=">> bitwise right shift"))
	static uint8 BitwiseRightShiftByte(const uint8 A, const uint8 B) { return A >> B; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer", DisplayName="Bitwise Left Shift", meta=(CompactNodeTitle="<<", Keywords="<< bitwise left shift"))
	static int BitwiseLeftShiftInt(const int A, const int B) { return A << B; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer", DisplayName="Bitwise Right Shift", meta=(CompactNodeTitle=">>", Keywords=">> bitwise right shift"))
	static int BitwiseRightShiftInt(const int A, const int B) { return A >> B; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer64", DisplayName="Bitwise Left Shift", meta=(CompactNodeTitle="<<", Keywords="<< bitwise left shift"))
	static int64 BitwiseLeftShiftInt64(const int64 A, const int64 B) { return A << B; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Integer64", DisplayName="Bitwise Right Shift", meta=(CompactNodeTitle=">>", Keywords=">> bitwise right shift"))
	static int64 BitwiseRightShiftInt64(const int64 A, const int64 B) { return A >> B; }

#pragma endregion //BITWISE_SHIFT

	// -- ASSIGNMENT OPERATORS --

#pragma region ADD_REF

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Add", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) uint8 &AddRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Add", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) int &AddRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Add", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) int64 &AddRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Add (single-precision)", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) float &AddRefFloat(UPARAM(ref) float &Ref, const float Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Add (double-precision)", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) double &AddRefDouble(UPARAM(ref) double &Ref, const double Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector4", DisplayName="Add", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) FVector4 &AddRefVector4(UPARAM(ref) FVector4 &Ref, const FVector4 &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector", DisplayName="Add", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) FVector &AddRefVector(UPARAM(ref) FVector &Ref, const FVector &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector2D", DisplayName="Add", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) FVector2D &AddRefVector2D(UPARAM(ref) FVector2D &Ref, const FVector2D &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Rotator", DisplayName="Add", meta=(CompactNodeTitle="+=", Keywords="+= add assign ref"))
	static UPARAM(ref) FRotator &AddRefRotator(UPARAM(ref) FRotator &Ref, const FRotator &Value);

#pragma endregion //ADD_REF

#pragma region SUB_REF

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Subtract", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) uint8 &SubRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Subtract", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) int &SubRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Subtract", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) int64 &SubRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Subtract (single-precision)", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) float &SubRefFloat(UPARAM(ref) float &Ref, const float Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Subtract (double-precision)", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) double &SubRefDouble(UPARAM(ref) double &Ref, const double Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector4", DisplayName="Subtract", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) FVector4 &SubRefVector4(UPARAM(ref) FVector4 &Ref, const FVector4 &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector", DisplayName="Subtract", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) FVector &SubRefVector(UPARAM(ref) FVector &Ref, const FVector &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector2D", DisplayName="Subtract", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) FVector2D &SubRefVector2D(UPARAM(ref) FVector2D &Ref, const FVector2D &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Rotator", DisplayName="Subtract", meta=(CompactNodeTitle="-=", Keywords="-= subtract assign ref"))
	static UPARAM(ref) FRotator &SubRefRotator(UPARAM(ref) FRotator &Ref, const FRotator &Value);

#pragma endregion //SUB_REF

#pragma region MULT_REF

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Multiply", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) uint8 &MultRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Multiply", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) int &MultRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Multiply", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) int64 &MultRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Multiply (single-precision)", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) float &MultRefFloat(UPARAM(ref) float &Ref, const float Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Multiply (double-precision)", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) double &MultRefDouble(UPARAM(ref) double &Ref, const double Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector4", DisplayName="Multiply", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) FVector4 &MultRefVector4(UPARAM(ref) FVector4 &Ref, const FVector4 &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector", DisplayName="Multiply", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) FVector &MultRefVector(UPARAM(ref) FVector &Ref, const FVector &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector2D", DisplayName="Multiply", meta=(CompactNodeTitle="*=", Keywords="*= multiply assign ref"))
	static UPARAM(ref) FVector2D &MultRefVector2D(UPARAM(ref) FVector2D &Ref, const FVector2D &Value);

#pragma endregion //MULT_REF

#pragma region DIV_REF

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Divide", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) uint8 &DivRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Divide", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) int &DivRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Divide", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) int64 &DivRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Divide (single-precision)", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) float &DivRefFloat(UPARAM(ref) float &Ref, const float Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Divide (double-precision)", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) double &DivRefDouble(UPARAM(ref) double &Ref, const double Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector4", DisplayName="Divide", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) FVector4 &DivRefVector4(UPARAM(ref) FVector4 &Ref, const FVector4 &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector", DisplayName="Divide", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) FVector &DivRefVector(UPARAM(ref) FVector &Ref, const FVector &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector2D", DisplayName="Divide", meta=(CompactNodeTitle="/=", Keywords="/= divide assign ref"))
	static UPARAM(ref) FVector2D &DivRefVector2D(UPARAM(ref) FVector2D &Ref, const FVector2D &Value);

#pragma endregion //DIV_REF

#pragma region MOD_REF

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Mod", meta=(CompactNodeTitle="%=", Keywords="%= modulo modulus assign ref"))
	static UPARAM(ref) uint8 &ModRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Mod", meta=(CompactNodeTitle="%=", Keywords="%= modulo modulus assign ref"))
	static UPARAM(ref) int &ModRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Mod", meta=(CompactNodeTitle="%=", Keywords="%= modulo modulus assign ref"))
	static UPARAM(ref) int64 &ModRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Mod (single-precision)", meta=(CompactNodeTitle="%=", Keywords="%= modulo modulus assign ref"))
	static UPARAM(ref) float &ModRefFloat(UPARAM(ref) float &Ref, const float Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="Mod (double-precision)", meta=(CompactNodeTitle="%=", Keywords="%= modulo modulus assign ref"))
	static UPARAM(ref) double &ModRefDouble(UPARAM(ref) double &Ref, const double Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector4", DisplayName="Mod", meta=(CompactNodeTitle="%=", Keywords="%= modulus modulo assign ref"))
	static UPARAM(ref) FVector4 &ModRefVector4(UPARAM(ref) FVector4 &Ref, const FVector4 &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector", DisplayName="Mod", meta=(CompactNodeTitle="%=", Keywords="%= modulus modulo assign ref"))
	static UPARAM(ref) FVector &ModRefVector(UPARAM(ref) FVector &Ref, const FVector &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector2D", DisplayName="Mod", meta=(CompactNodeTitle="%=", Keywords="%= modulus modulo assign ref"))
	static UPARAM(ref) FVector2D &ModRefVector2D(UPARAM(ref) FVector2D &Ref, const FVector2D &Value);

#pragma endregion //MOD_REF

#pragma region POS_MOD_REF

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="PosMod", meta=(CompactNodeTitle="%= (+)", Keywords="%= + positive modulus modulo assign ref"))
	static UPARAM(ref) int &PosModRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="PosMod", meta=(CompactNodeTitle="%= (+)", Keywords="%= + positive modulus modulo assign ref"))
	static UPARAM(ref) int64 &PosModRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="PosMod (single-precision)", meta=(CompactNodeTitle="%= (+)", Keywords="%= + positive modulus modulo assign ref"))
	static UPARAM(ref) float &PosModRefFloat(UPARAM(ref) float &Ref, const float Value);

	UFUNCTION(BlueprintCallable, Category="Math|Float", DisplayName="PosMod (double-precision)", meta=(CompactNodeTitle="%= (+)", Keywords="%= + positive modulus modulo assign ref"))
	static UPARAM(ref) double &PosModRefDouble(UPARAM(ref) double &Ref, const double Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector4", DisplayName="PosMod", meta=(CompactNodeTitle="%= (+)", Keywords="%= + positive modulus modulo assign ref"))
	static UPARAM(ref) FVector4 &PosModRefVector4(UPARAM(ref) FVector4 &Ref, const FVector4 &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector", DisplayName="PosMod", meta=(CompactNodeTitle="%= (+)", Keywords="%= + positive modulus modulo assign ref"))
	static UPARAM(ref) FVector &PosModRefVector(UPARAM(ref) FVector &Ref, const FVector &Value);

	UFUNCTION(BlueprintCallable, Category="Math|Vector2D", DisplayName="PosMod", meta=(CompactNodeTitle="%= (+)", Keywords="%= + positive modulus modulo assign ref"))
	static UPARAM(ref) FVector2D &PosModRefVector2D(UPARAM(ref) FVector2D &Ref, const FVector2D &Value);

#pragma endregion //POS_MOD_REF

#pragma region BITWISE_REF

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Bitwise NOT", meta=(CompactNodeTitle="~=", Keywords="~= bitwise not assign ref"))
	static UPARAM(ref) uint8 &BitwiseNotRefByte(UPARAM(ref) uint8 &Ref);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Bitwise NOT", meta=(CompactNodeTitle="~=", Keywords="~= bitwise not assign ref"))
	static UPARAM(ref) int &BitwiseNotRefInt(UPARAM(ref) int &Ref);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Bitwise NOT", meta=(CompactNodeTitle="~=", Keywords="~= bitwise not assign ref"))
	static UPARAM(ref) int64 &BitwiseNotRefInt64(UPARAM(ref) int64 &Ref);

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Bitwise AND", meta=(CompactNodeTitle="&=", Keywords="&= bitwise and assign ref"))
	static UPARAM(ref) uint8 &BitwiseAndRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Bitwise AND", meta=(CompactNodeTitle="&=", Keywords="&= bitwise and assign ref"))
	static UPARAM(ref) int &BitwiseAndRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Bitwise AND", meta=(CompactNodeTitle="&=", Keywords="&= bitwise and assign ref"))
	static UPARAM(ref) int64 &BitwiseAndRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Bitwise OR", meta=(CompactNodeTitle="|=", Keywords="|= bitwise or assign ref"))
	static UPARAM(ref) uint8 &BitwiseOrRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Bitwise OR", meta=(CompactNodeTitle="|=", Keywords="|= bitwise or assign ref"))
	static UPARAM(ref) int &BitwiseOrRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Bitwise OR", meta=(CompactNodeTitle="|=", Keywords="|= bitwise or assign ref"))
	static UPARAM(ref) int64 &BitwiseOrRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Bitwise XOR", meta=(CompactNodeTitle="^=", Keywords="^= bitwise xor assign ref"))
	static UPARAM(ref) uint8 &BitwiseXorRefByte(UPARAM(ref) uint8 &Ref, const uint8 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Bitwise XOR", meta=(CompactNodeTitle="^=", Keywords="^= bitwise xor assign ref"))
	static UPARAM(ref) int &BitwiseXorRefInt(UPARAM(ref) int &Ref, const int Value);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Bitwise XOR", meta=(CompactNodeTitle="^=", Keywords="^= bitwise xor assign ref"))
	static UPARAM(ref) int64 &BitwiseXorRefInt64(UPARAM(ref) int64 &Ref, const int64 Value);

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Bitwise Left Shift", meta=(CompactNodeTitle="<<=", Keywords="<<= bitwise left shift assign ref"))
	static UPARAM(ref) uint8 &BitwiseLeftShiftRefByte(UPARAM(ref) uint8 &A, const uint8 B);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Bitwise Left Shift", meta=(CompactNodeTitle="<<=", Keywords="<<= bitwise left shift assign ref"))
	static UPARAM(ref) int &BitwiseLeftShiftRefInt(UPARAM(ref) int &A, const int B);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Bitwise Left Shift", meta=(CompactNodeTitle="<<=", Keywords="<<= bitwise left shift assign ref"))
	static UPARAM(ref) int64 &BitwiseLeftShiftRefInt64(UPARAM(ref) int64 &A, const int64 B);

	UFUNCTION(BlueprintCallable, Category="Math|Byte", DisplayName="Bitwise Right Shift", meta=(CompactNodeTitle=">>=", Keywords=">>= bitwise right shift assign ref"))
	static UPARAM(ref) uint8 &BitwiseRightShiftRefByte(UPARAM(ref) uint8 &A, const uint8 B);

	UFUNCTION(BlueprintCallable, Category="Math|Integer", DisplayName="Bitwise Right Shift", meta=(CompactNodeTitle=">>=", Keywords=">>= bitwise right shift assign ref"))
	static UPARAM(ref) int &BitwiseRightShiftRefInt(UPARAM(ref) int &A, const int B);

	UFUNCTION(BlueprintCallable, Category="Math|Integer64", DisplayName="Bitwise Right Shift", meta=(CompactNodeTitle=">>=", Keywords=">>= bitwise right shift assign ref"))
	static UPARAM(ref) int64 &BitwiseRightShiftRefInt64(UPARAM(ref) int64 &A, const int64 B);

#pragma endregion //BITWISE_REF

#pragma region BOOL_REF

	UFUNCTION(BlueprintCallable, Category="Math|Boolean", DisplayName="Boolean NOT", meta=(CompactNodeTitle="!=", Keywords="!= not assign ref boolean"))
	static UPARAM(ref) bool &BooleanNotRef(UPARAM(ref) bool &Ref);

	UFUNCTION(BlueprintCallable, Category="Math|Boolean", DisplayName="Boolean AND", meta=(CompactNodeTitle="&=", Keywords="&= and assign ref boolean"))
	static UPARAM(ref) bool &BooleanAndRef(UPARAM(ref) bool &Ref, const bool Value);

	UFUNCTION(BlueprintCallable, Category="Math|Boolean", DisplayName="Boolean OR", meta=(CompactNodeTitle="|=", Keywords="|= or assign ref boolean"))
	static UPARAM(ref) bool &BooleanOrRef(UPARAM(ref) bool &Ref, const bool Value);

	UFUNCTION(BlueprintCallable, Category="Math|Boolean", DisplayName="Boolean XOR", meta=(CompactNodeTitle="^=", Keywords="^= xor assign ref boolean"))
	static UPARAM(ref) bool &BooleanXorRef(UPARAM(ref) bool &Ref, const bool Value);

#pragma endregion //BOOL_REF

	// -- FUNCTIONS --

#pragma region INVERSION

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="Invert (single-precision)", meta=(CompactNodeTitle="1/x", Keywords="/ invert"))
	static float InvertFloat(const float Value) { return 1.f / Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="Invert (double-precision)", meta=(CompactNodeTitle="1/x", Keywords="/ invert"))
	static double InvertDouble(const double Value) { return 1. / Value; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="Invert", meta=(CompactNodeTitle="1/x", Keywords="/ invert"))
	static FVector4 InvertVector4(const FVector4 Value) { return FVector4(1. / Value.X, 1. / Value.Y, 1. / Value.Z, 1. / Value.W); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="Invert", meta=(CompactNodeTitle="1/x", Keywords="/ invert"))
	static FVector InvertVector(const FVector Value) { return FVector(1. / Value.X, 1. / Value.Y, 1. / Value.Z); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="Invert", meta=(CompactNodeTitle="1/x", Keywords="/ invert"))
	static FVector2D InvertVector2D(const FVector2D Value) { return FVector2D(1. / Value.X, 1. / Value.Y); }

#pragma endregion //INVERSION

#pragma region NAN

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="GetNaN", meta=(CompactNodeTitle="NaN"))
	static float GetNan_Float() { return nanf("0"); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="GetNaN", meta=(CompactNodeTitle="NaN"))
	static double GetNan_Double() { return nanf("0"); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="Get NaN Vector")
	static FVector4 GetNanVector4D() { return FVector4(nanf("0"), nanf("0"), nanf("0"), nanf("0")); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="Get NaN Vector")
	static FVector GetNanVector3D() { return FVector(nanf("0"), nanf("0"), nanf("0")); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="Get NaN Vector")
	static FVector2D GetNanVector2D() { return FVector2D(nanf("0"), nanf("0")); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="IsNaN")
	static bool IsNan_Float(const float Value) { return isnan(Value); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="IsNaN")
	static bool IsNan_Double(const float Value) { return isnan(Value); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="HasNaN")
	static bool HasNan_Vector4D(const FVector4& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="HasNaN")
	static bool HasNan_Vector3D(const FVector& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="HasNaN")
	static bool HasNan_Vector2D(const FVector2D& Value);

#pragma endregion //NAN

#pragma region INFINITY

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float")
	static float GetPositiveInfinity() { return INFINITY; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float")
	static float GetNegativeInfinity() { return -INFINITY; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="IsFinite (single-precision)")
	static bool IsFiniteFloat(const float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Float", DisplayName="IsFinite (double-precision)")
	static bool IsFiniteDouble(const double Value);

#pragma endregion //INFINITY

#pragma region VECTORS

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="Normalized")
	static FVector4 NormalizedVector4(const FVector4 Vector, const float Tolerance = 1e-4f);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="Normalized")
	static FVector NormalizedVector(const FVector Vector, const float Tolerance = 1e-4f);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="Normalized")
	static FVector2D NormalizedVector2D(const FVector2D Vector, const float Tolerance = 1e-4f);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="AngleBetween")
	static double AngleBetweenVector4(const FVector4 A, const FVector4 B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector", DisplayName="AngleBetween")
	static double AngleBetweenVector(const FVector A, const FVector B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D", DisplayName="AngleBetween")
	static double AngleBetweenVector2D(const FVector2D A, const FVector2D B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector4", DisplayName="DotProduct", meta=(CompactNodeTitle="Dot"))
	static double DotVector4(const FVector4 A, const FVector4 B);

	// Convert Vector from cartesian coordinates to cylindrical coordinates
	// (x, y, z) -> (ρ, φ, z)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector")
	static FVector CartesianToCylindrical(const FVector Vector);

	// Convert Vector from cartesian coordinates to spherical coordinates
	// (x, y, z) -> (r, φ, θ)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector")
	static FVector CartesianToSpherical(const FVector Vector);

	// Convert Vector from cylindrical coordinates to cartesian coordinates
	// (ρ, φ, z) -> (x, y, z)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector")
	static FVector CylindricalToCartesian(const FVector Vector);

	// Convert Vector from cylindrical coordinates to spherical coordinates
	// (ρ, φ, z) -> (r, φ, θ)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector")
	static FVector CylindricalToSpherical(const FVector Vector);

	// Convert Vector from spherical coordinates to cartesian coordinates
	// (r, φ, θ) -> (x, y, z)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector")
	static FVector SphericalToCartesian(const FVector Vector);

	// Convert Vector from spherical coordinates to cylindrical coordinates
	// (r, φ, θ) -> (ρ, φ, z)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector")
	static FVector SphericalToCylindrical(const FVector Vector);

	// Convert Vector from cartesian coordinates to polar coordinates
	// (x, y) -> (r, θ)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D")
	static FVector2D CartesianToPolar(const FVector2D Vector);

	// Convert Vector from polar coordinates to cartesian coordinates
	// (r, θ) -> (x, y)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector2D")
	static FVector2D PolarToCartesian(const FVector2D Vector);

#pragma endregion //VECTORS

#pragma region ROTATOR

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Rotator", DisplayName="Add", meta=(CompactNodeTitle="+", Keywords="+ add"))
	static FRotator AddRotator(const FRotator A, const FRotator B);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Rotator", DisplayName="Subtract", meta=(CompactNodeTitle="-", Keywords="- subtract"))
	static FRotator SubRotator(const FRotator A, const FRotator B);

#pragma endregion //ROTATOR

#pragma region TRANSFORM

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Transform", DisplayName="Identity")
	static FTransform GetIdentityTransform() { return FTransform::Identity; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Transform")
	static FVector RotateFromAngle(const FTransform &Transform, const FVector Euler, const FVector Axis = FVector::ForwardVector);

#pragma endregion //TRANSFORM

	// -- MISCELLANEOUS --

	// Returns the intersection between the given sphere and line closest to LinePoint
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Intersection")
	static FVector SphereLineIntersection(const float SphereRadius, const FVector SphereCenter, const FVector LinePoint, const FVector LineDirection);

	// Rotates a point around another point by the given rotation
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math")
	static FVector RotateAround(const FVector Point, const FVector Origin, const FRotator Rotation);

	// Signed distance between a point and a plane. Positive if above plane and negative if below plane.
	// If you just want the distance you can just call the absolute function to remove the sign
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Math|Vector")
	static float DistanceToPlane(const FVector Point, const FVector PlaneBase, FVector PlaneNormal);
};
