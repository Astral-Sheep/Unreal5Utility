// Copyright Thomas SURBON. All rights reserved.

#include "MathUtility.h"

#include "Kismet/KismetMathLibrary.h"

// -- ARITHMETIC OPERATORS --

#pragma region MOD
#define MOD(T, TName, Op)\
	T UMathUtility::Mod##TName(const T &A, const T &B)\
	{\
		return Op;\
	}

MOD(FVector4, Vector4, FVector4(FMath::Fmod(A.X, B.X), FMath::Fmod(A.Y, B.Y), FMath::Fmod(A.Z, B.Z), FMath::Fmod(A.W, B.W)))
MOD(FVector, Vector, FVector(FMath::Fmod(A.X, B.X), FMath::Fmod(A.Y, B.Y), FMath::Fmod(A.Z, B.Z)))
MOD(FVector2D, Vector2D, FVector2D(FMath::Fmod(A.X, B.X), FMath::Fmod(A.Y, B.Y)))

#undef MOD
#pragma endregion MOD

#pragma region POS_MOD
#define POS_MOD(T, TName, Op)\
	T UMathUtility::PosMod##TName(const T A, const T B)\
	{\
		const T lRes = Op;\
		return lRes < 0 ? lRes + B : lRes;\
	}

POS_MOD(int, Int, A % B)
POS_MOD(int64, Int64, A % B)
POS_MOD(float, Float, FMath::Fmod(A, B))
POS_MOD(double, Double, FMath::Fmod(A, B))

#undef POS_MOD
#define POS_MOD(T, TName, Op)\
	T UMathUtility::PosMod##TName(const T &A, const T &B)\
	{\
		return Op;\
	}

POS_MOD(FVector4, Vector4, FVector4(PosModDouble(A.X, B.X), PosModDouble(A.Y, B.Y), PosModDouble(A.Z, B.Z), PosModDouble(A.W, B.W)));
POS_MOD(FVector, Vector, FVector(PosModDouble(A.X, B.X), PosModDouble(A.Y, B.Y), PosModDouble(A.Z, B.Z)));
POS_MOD(FVector2D, Vector2D, FVector2D(PosModDouble(A.X, B.X), PosModDouble(A.Y, B.Y)));

#undef POS_MOD
#pragma endregion //POS_MOD

// -- ASSIGNMENT OPERATORS --

#define REF_OP(Op, OpName, T, TName, Mod) T& UMathUtility::OpName##Ref##TName(T& Ref, const T Mod Value) { Ref Op Value; return Ref; }

#pragma region ADD_REF
#define ADD_REF(T, TName, Mod) REF_OP(+=, Add, T, TName, Mod)

ADD_REF(uint8, Byte,)
ADD_REF(int, Int,)
ADD_REF(int64, Int64,)
ADD_REF(float, Float,)
ADD_REF(double, Double,)
ADD_REF(FVector4, Vector4, &)
ADD_REF(FVector, Vector, &)
ADD_REF(FVector2D, Vector2D, &)

FRotator& UMathUtility::AddRefRotator(FRotator& Ref, const FRotator& Value)
{
	Ref.Pitch += Value.Pitch;
	Ref.Yaw += Value.Yaw;
	Ref.Roll += Value.Roll;
	return Ref;
}

#undef ADD_REF
#pragma endregion //ADD_REF

#pragma region SUB_REF
#define SUB_REF(T, TName, Mod) REF_OP(-=, Sub, T, TName, Mod)

SUB_REF(uint8, Byte,)
SUB_REF(int, Int,)
SUB_REF(int64, Int64,)
SUB_REF(float, Float,)
SUB_REF(double, Double,)
SUB_REF(FVector4, Vector4, &)
SUB_REF(FVector, Vector, &)
SUB_REF(FVector2D, Vector2D, &)

FRotator& UMathUtility::SubRefRotator(FRotator& Ref, const FRotator& Value)
{
	Ref.Pitch -= Value.Pitch;
	Ref.Yaw -= Value.Yaw;
	Ref.Roll -= Value.Roll;
	return Ref;
}

#undef SUB_REF
#pragma endregion //SUB_REF

#pragma region MULT
#define MULT_REF(T, TName, Mod) REF_OP(*=, Mult, T, TName, Mod)

MULT_REF(uint8, Byte,)
MULT_REF(int, Int,)
MULT_REF(int64, Int64,)
MULT_REF(float, Float,)
MULT_REF(double, Double,)
MULT_REF(FVector4, Vector4, &)
MULT_REF(FVector, Vector, &)
MULT_REF(FVector2D, Vector2D, &)

#undef MULT_REF
#pragma endregion //MULT

#pragma region DIV_REF
#define DIV_REF(T, TName, Mod) REF_OP(/=, Div, T, TName, Mod)

DIV_REF(uint8, Byte,)
DIV_REF(int, Int,)
DIV_REF(int64, Int64,)
DIV_REF(float, Float,)
DIV_REF(double, Double,)
DIV_REF(FVector4, Vector4, &)
DIV_REF(FVector, Vector, &)
DIV_REF(FVector2D, Vector2D, &)

#undef DIV_REF
#pragma endregion //DIV_REF

#pragma region MOD_REF

REF_OP(%=, Mod, uint8, Byte,)
REF_OP(%=, Mod, int, Int,)
REF_OP(%=, Mod, int64, Int64,)

#define MOD_REF(T, TName, Op, Mod)\
	T &UMathUtility::ModRef##TName(T &Ref, const T Mod Value)\
	{\
		Ref = Op;\
		return Ref;\
	}

MOD_REF(float, Float, FMath::Fmod(Ref, Value),)
MOD_REF(double, Double, FMath::Fmod(Ref, Value),)
MOD_REF(FVector4, Vector4, ModVector4(Ref, Value), &)
MOD_REF(FVector, Vector, ModVector(Ref, Value), &)
MOD_REF(FVector2D, Vector2D, ModVector2D(Ref, Value), &)

#undef MOD_REF
#pragma endregion //MOD_REF

#pragma region POS_MOD_REF
#define POS_MOD_REF(T, TName, Func, Mod)\
	T &UMathUtility::PosModRef##TName(T &Ref, const T Mod Value)\
	{\
		Ref = Func(Ref, Value);\
		return Ref;\
	}

POS_MOD_REF(int, Int, PosModInt,)
POS_MOD_REF(int64, Int64, PosModInt64,)
POS_MOD_REF(float, Float, PosModFloat,)
POS_MOD_REF(double, Double, PosModDouble,)
POS_MOD_REF(FVector4, Vector4, PosModVector4, &)
POS_MOD_REF(FVector, Vector, PosModVector, &)
POS_MOD_REF(FVector2D, Vector2D, PosModVector2D, &)

#undef POS_MOD_REF
#pragma endregion //POS_MOD_REF

#pragma region BITWISE_REF
#define BITWISE_NOT_REF(T, TName)\
	T &UMathUtility::BitwiseNotRef##TName(T &Ref)\
	{\
		Ref = ~Ref;\
		return Ref;\
	}

BITWISE_NOT_REF(uint8, Byte)
BITWISE_NOT_REF(int, Int)
BITWISE_NOT_REF(int64, Int64)
#undef BITWISE_NOT_REF

#define BITWISE_REF(T, TName, Op, OpName)\
	T &UMathUtility::Bitwise##OpName##Ref##TName(T &Ref, const T Value)\
	{\
		Ref Op##= Value;\
		return Ref;\
	}

BITWISE_REF(uint8, Byte, &, And)
BITWISE_REF(int, Int, &, And)
BITWISE_REF(int64, Int64, &, And)

BITWISE_REF(uint8, Byte, |, Or)
BITWISE_REF(int, Int, |, Or)
BITWISE_REF(int64, Int64, |, Or)

BITWISE_REF(uint8, Byte, ^, Xor)
BITWISE_REF(int, Int, ^, Xor)
BITWISE_REF(int64, Int64, ^, Xor)

BITWISE_REF(uint8, Byte, <<, LeftShift)
BITWISE_REF(int, Int, <<, LeftShift)
BITWISE_REF(int64, Int64, <<, LeftShift)

BITWISE_REF(uint8, Byte, >>, RightShift)
BITWISE_REF(int, Int, >>, RightShift)
BITWISE_REF(int64, Int64, >>, RightShift)

#undef BITWISE_REF
#pragma endregion //BITWISE_REF

#pragma region BOOL_REF
#define BOOL_REF(Op, OpName)\
	bool &UMathUtility::Boolean##OpName##Ref(bool &Ref, const bool Value)\
	{\
		Ref Op##= Value;\
		return Ref;\
	}

BOOL_REF(&, And)
BOOL_REF(|, Or)
BOOL_REF(^, Xor)

bool& UMathUtility::BooleanNotRef(bool& Ref)
{
	Ref = !Ref;
	return Ref;
}

#undef BOOL_REF
#pragma endregion //BOOL_REF

#undef REF_OP

// -- FUNCTIONS --

#pragma region NAN

bool UMathUtility::HasNan_Vector4D(const FVector4& Value)
{
	return FMath::IsNaN(Value.X) || FMath::IsNaN(Value.Y) || FMath::IsNaN(Value.Z) || FMath::IsNaN(Value.W);
}

bool UMathUtility::HasNan_Vector3D(const FVector& Value)
{
	return FMath::IsNaN(Value.X) || FMath::IsNaN(Value.Y) || FMath::IsNaN(Value.Z);
}

bool UMathUtility::HasNan_Vector2D(const FVector2D& Value)
{
	return FMath::IsNaN(Value.X) || FMath::IsNaN(Value.Y);
}

#pragma endregion //NAN

#pragma region INFINITY

bool UMathUtility::IsFiniteFloat(const float Value)
{
	return isfinite(Value);
}

bool UMathUtility::IsFiniteDouble(const double Value)
{
	return isfinite(Value);
}

#pragma endregion //INFINITY

#pragma region VECTORS

FVector4 UMathUtility::NormalizedVector4(const FVector4 Vector, const float Tolerance)
{
	float lLength = Vector.SizeSquared();

	if (lLength <= Tolerance * Tolerance || FMath::Abs(lLength - 1.f) <= Tolerance)
	{
		return Vector;
	}

	lLength = FMath::Sqrt(lLength);
	return FVector4(Vector.X / lLength, Vector.Y / lLength, Vector.Z / lLength, Vector.W / lLength);
}

FVector UMathUtility::NormalizedVector(const FVector Vector, const float Tolerance)
{
	float lLength = Vector.SquaredLength();

	if (lLength <= Tolerance || FMath::Abs(lLength - 1.f) <= Tolerance)
	{
		return Vector;
	}

	lLength = FMath::Sqrt(lLength);
	return FVector(Vector.X / lLength, Vector.Y / lLength, Vector.Z / lLength);
}

FVector2D UMathUtility::NormalizedVector2D(const FVector2D Vector, const float Tolerance)
{
	const float lLength = Vector.Length();

	if (lLength <= Tolerance || FMath::Abs(lLength - 1.f) <= Tolerance)
	{
		return Vector;
	}

	return FVector2D(Vector.X / lLength, Vector.Y / lLength);
}

double UMathUtility::AngleBetweenVector4(const FVector4 A, const FVector4 B)
{
	return FMath::Acos(DotVector4(NormalizedVector4(A), NormalizedVector4(B)));
}

double UMathUtility::AngleBetweenVector(const FVector A, const FVector B)
{
	return FMath::Acos(NormalizedVector(A).Dot(NormalizedVector(B)));
}

double UMathUtility::AngleBetweenVector2D(const FVector2D A, const FVector2D B)
{
	return FMath::Atan2(B.Y - A.Y, B.X - A.Y);
}

double UMathUtility::DotVector4(const FVector4 A, const FVector4 B)
{
	return A.X * B.X + A.Y * B.Y + A.Z * B.Z + A.W * B.W;
}

FVector UMathUtility::CartesianToCylindrical(const FVector Vector)
{
	return FVector(
		FMath::Sqrt(Vector.X * Vector.X + Vector.Y * Vector.Y),
		FMath::Atan2(Vector.Y, Vector.X),
		Vector.Z
	);
}

FVector UMathUtility::CartesianToSpherical(const FVector Vector)
{
	const float lLength = Vector.Length();
	return FVector(
		lLength,
		FMath::Atan2(Vector.Y, Vector.X),
		FMath::Asin(Vector.Z / lLength)
	);
}

FVector UMathUtility::CylindricalToCartesian(const FVector Vector)
{
	return FVector(
		Vector.X * FMath::Cos(Vector.Y),
		Vector.X * FMath::Sin(Vector.Y),
		Vector.Z
	);
}

FVector UMathUtility::CylindricalToSpherical(const FVector Vector)
{
	const float lLength = FMath::Sqrt(Vector.X * Vector.X + Vector.Z * Vector.Z);
	return FVector(
		lLength,
		Vector.Y,
		FMath::Asin(Vector.Z / lLength)
	);
}

FVector UMathUtility::SphericalToCartesian(const FVector Vector)
{
	return FVector(
		Vector.X * FMath::Cos(Vector.Z) * FMath::Cos(Vector.Y),
		Vector.X * FMath::Cos(Vector.Z) * FMath::Sin(Vector.Y),
		Vector.X * FMath::Sin(Vector.Z)
	);
}

FVector UMathUtility::SphericalToCylindrical(const FVector Vector)
{
	return FVector(
		Vector.X * FMath::Cos(Vector.Z),
		Vector.Y,
		Vector.X * FMath::Sin(Vector.Z)
	);
}

FVector2D UMathUtility::CartesianToPolar(const FVector2D Vector)
{
	return FVector2D(
		Vector.Length(),
		FMath::Atan2(Vector.Y, Vector.X)
	);
}

FVector2D UMathUtility::PolarToCartesian(const FVector2D Vector)
{
	return FVector2D(
		Vector.X * FMath::Cos(Vector.Y),
		Vector.X * FMath::Sin(Vector.Y)
	);
}

#pragma endregion //VECTORS

#pragma region ROTATOR

FRotator UMathUtility::AddRotator(const FRotator A, const FRotator B)
{
	return FRotator(A.Pitch + B.Pitch, A.Yaw + B.Yaw, A.Roll + B.Roll);
}

FRotator UMathUtility::SubRotator(const FRotator A, const FRotator B)
{
	return FRotator(A.Pitch - B.Pitch, A.Yaw - B.Yaw, A.Roll - B.Roll);
}

#pragma endregion //ROTATOR

FVector UMathUtility::RotateFromAngle(const FTransform &Transform, const FVector Euler, const FVector Axis)
{
	const FRotator lAngle = FRotator::MakeFromEuler(Euler);
	return Transform.TransformVector(lAngle.RotateVector(Axis));
}

// -- MISCELLANEOUS --

FVector UMathUtility::SphereLineIntersection(const float SphereRadius, const FVector SphereCenter, const FVector LinePoint, const FVector LineDirection)
{
	const float a = LineDirection.SquaredLength();                                            // d^2 * (u . u)
	const float b = 2.f * LineDirection.Dot(LinePoint - SphereCenter);                        // 2 * u . (p - o)
	const float c = (LinePoint - SphereCenter).SquaredLength() - SphereRadius * SphereRadius; // (p - o) . (p - o) - r^2
	const float delta = b * b - 4.f * a * c; // b^2 - 4ac
	const float d1 = (-b - FMath::Sqrt(delta)) / 2.f * a; // (-b - sqrt(delta)) / 2a
	const float d2 = (-b + FMath::Sqrt(delta)) / 2.f * a; // (-b + sqrt(delta)) / 2a
	return LinePoint + LineDirection * FMath::Max(d1, d2);
}

FVector UMathUtility::RotateAround(const FVector Point, const FVector Origin, const FRotator Rotation)
{
	return Rotation.RotateVector(Point - Origin) + Origin;
}

float UMathUtility::DistanceToPlane(const FVector Point, const FVector PlaneBase, FVector PlaneNormal)
{
	PlaneNormal = NormalizedVector(PlaneNormal);
	const FVector lProjection = UKismetMathLibrary::ProjectPointOnToPlane(Point, PlaneBase, PlaneNormal);

	if (lProjection.Equals(Point))
		return 0.f;

	return FVector::Distance(Point, lProjection) * NormalizedVector(Point - lProjection).Dot(PlaneNormal);
}
