/*  ============================================================================================
*  PROJECT:  Dillon's Tool Box Math Edition
*  AUTHOR:   Dillon Williams
*  LICENSE:  Do What The Fuck Ever license
*  LANGUAGE: C\C++
*
*  INFORMATION:
*  To implement into your code base just include this file into your main compilation unit
*  This is meant to work in both C as well as C++
*
*  This is developed in my free time, constant and consistent updates should not be expected.
*  Feel free to modify this code to your preference.
*
*  ============================================================================================
*/

#if !defined DTB_MATH_H

#if __cplusplus
#define DTB_MATH_B32 bool
#define DTB_MATH_TRUE 1
#define DTB_MATH_FALSE 0
#else
typedef unsigned int DTB_MATH_B32;
#define DTB_MATH_TRUE 1
#define DTB_MATH_FALSE 0
#endif

#define PI 3.14159265358979323846
#define PI32 3.14159265359f
#define TWO_PI PI * 2

#define DTB_MIN(a, b) a > b ? b : a
#define DTB_MAX(a, b) a < b ? b : a
#define DTB_ABS(a) (a > 0 ? a : -(a))
#define DTB_MOD(a, m) ((a) % (m)) >= 0 ? ((a) % (m)) : (((a) % (m)) + (m))
#define DTB_SQUARE(x) x * x

#include <math.h>

typedef union dtbV2
{
	struct
	{
		float x, y;
	};
	
	struct
	{
		float width, height;
	};
	
	struct
	{
		float left, right;
	};
	
	struct
	{
		float u, v;
	};
	
	float elements[2];
	
}dtbV2;

typedef union dtbV3
{
	struct
	{
		float x, y, z;
	};
	
	struct
	{
		float u, v, w;
	};
	
	struct
	{
		float r, g, b;
	};
	
	float elements[3];
	
}dtbV3;

typedef union dtbV4
{
	struct
	{
		float x, y, z, w;
	};
	
	struct
	{
		float r, g, b, a;
	};
	
	float elements[4];
	
}dtbV4;

typedef struct dtbCircle
{
	float radius, x, y;
}dtbCircle;

typedef struct dtbM4
{
	float elements[4][4];
}dtbM4;

#if defined(DTB_MATH_USE_TYPES)
typedef dtbV2 v2;
typedef dtbV3 v3;
typedef dtbV4 v4;
typedef dtbM4 m4;
#endif

#define dtb_function inline

// NOTE(DILLON): Strictly utitily functions outside of math structures
dtb_function float ToRadians(float degrees){
	float result = degrees * (PI32 / 180.f);
	return result;
}

dtb_function float Lerp(float a, float time, float b){
	return (1.0f - time) * a + time * b;
}

dtb_function float Clamp(float min, float value, float max){
	float result = value;
	
	if(result < min){
		result = min;
	} else if(result > max){
		result = max;
	}
	
	return result;
}

// NOTE(DILLON): Vector 2's
dtb_function dtbV2 dtbVec2(float x, float y)
{
	dtbV2 result = {0};
	result.x = x;
	result.y = y;
	return result;
}

dtb_function dtbV2 dtbVec2z()
{
	dtbV2 result = {0};
	return result;
}

dtb_function DTB_MATH_B32 dtbVec2_Equals(dtbV2 left, dtbV2 right)
{
    for(int i = 0; i < 2; i++)
    {
        if(left.elements[i] != right.elements[i])
        {
            return DTB_MATH_FALSE;
        }
    }
    
    return DTB_MATH_TRUE;
}

dtb_function dtbV2 dtbVec2_Add(dtbV2 left, dtbV2 right)
{
	dtbV2 result = {0};
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}

dtb_function dtbV2 dtbVec2_Addf(dtbV2 left, float right)
{
	dtbV2 result = {0};
	result.x = left.x + right;
	result.y = left.y + right;
	return result;
}


dtb_function dtbV2 dtbVec2_Subtract(dtbV2 left, dtbV2 right)
{
	dtbV2 result = {0};
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}

dtb_function dtbV2 dtbVec2_Subtractf(dtbV2 left, float right)
{
	dtbV2 result = {0};
	result.x = left.x - right;
	result.y = left.y - right;
	return result;
}

dtb_function dtbV2 dtbVec2_Multiply(dtbV2 left, dtbV2 right)
{
	dtbV2 result = {0};
	result.x = left.x * right.x;
	result.y = left.y * right.y;
	return result;
}

dtb_function dtbV2 dtbVec2_Multiplyf(dtbV2 left, float right)
{
	dtbV2 result = {0};
	result.x = left.x * right;
	result.y = left.y * right;
	return result;
}


dtb_function dtbV2 dtbVec2_Divide(dtbV2 left, dtbV2 right)
{
	dtbV2 result = {0};
	result.x = left.x / right.x;
	result.y = left.y / right.y;
	return result;
}

dtb_function dtbV2 dtbVec2_Dividef(dtbV2 left, float right)
{
	dtbV2 result = {0};
	result.x = left.x / right;
	result.y = left.y / right;
	return result;
}


// NOTE(DILLON): Vector 3's
dtb_function dtbV3 dtbVec3(float x, float y, float z)
{
	dtbV3 result = {0};
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

dtb_function dtbV3 dtbVec3z()
{
	dtbV3 result = {0};
	return result;
}

dtb_function DTB_MATH_B32 dtbVec3_Equals(dtbV3 left, dtbV3 right)
{
    for(int i = 0; i < 3; i++)
    {
        if(left.elements[i] != right.elements[i])
        {
            return DTB_MATH_FALSE;
        }
    }
    
    return DTB_MATH_TRUE;
}

dtb_function dtbV3 dtbVec3_Add(dtbV3 left, dtbV3 right)
{
	dtbV3 result = {0};
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	return result;
}

dtb_function dtbV3 dtbVec3_Addf(dtbV3 left, float right)
{
	dtbV3 result = {0};
	result.x = left.x + right;
	result.y = left.y + right;
	result.z = left.z + right;
	return result;
}

dtb_function dtbV3 dtbVec3_Subtract(dtbV3 left, dtbV3 right)
{
	dtbV3 result = {0};
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	return result;
}

dtb_function dtbV3 dtbVec3_Subtractf(dtbV3 left, float right)
{
	dtbV3 result = {0};
	result.x = left.x - right;
	result.y = left.y - right;
	result.z = left.z - right;
	return result;
}

dtb_function dtbV3 dtbVec3_Multiply(dtbV3 left, dtbV3 right)
{
	dtbV3 result = {0};
	result.x = left.x * right.x;
	result.y = left.y * right.y;
	result.z = left.z * right.z;
	return result;
}

dtb_function dtbV3 dtbVec3_Multiplyf(dtbV3 left, float right)
{
	dtbV3 result = {0};
	result.x = left.x * right;
	result.y = left.y * right;
	result.z = left.z * right;
	return result;
}

dtb_function dtbV3 dtbVec3_Divide(dtbV3 left, dtbV3 right)
{
	dtbV3 result = {0};
	result.x = left.x / right.x;
	result.y = left.y / right.y;
	result.z = left.z / right.z;
	return result;
}

dtb_function dtbV3 dtbVec3_Dividef(dtbV3 left, float right)
{
	dtbV3 result = {0};
	result.x = left.x / right;
	result.y = left.y / right;
	result.z = left.z / right;
	return result;
}

// NOTE(DILLON): Vector 4's
dtb_function dtbV4 dtbVec4(float x, float y, float z, float w)
{
	dtbV4 result = {0};
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

dtb_function dtbV4 dtbVec4z()
{
	dtbV4 result = {0};
	return result;
}

dtb_function DTB_MATH_B32 dtbVec4_Equals(dtbV4 left, dtbV4 right)
{
    for(int i = 0; i < 4; i++)
    {
        if(left.elements[i] != right.elements[i])
        {
            return DTB_MATH_FALSE;
        }
    }
    
    return DTB_MATH_TRUE;
}

dtb_function dtbV4 dtbVec4_Add(dtbV4 left, dtbV4 right)
{
	dtbV4 result = {0};
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	result.w = left.w + right.w;
	return result;
}

dtb_function dtbV4 dtbVec4_Addf(dtbV4 left, float right)
{
	dtbV4 result = {0};
	result.x = left.x + right;
	result.y = left.y + right;
	result.z = left.z + right;
	result.w = left.w + right;
	return result;
}

dtb_function dtbV4 dtbVec4_Subtract(dtbV4 left, dtbV4 right)
{
	dtbV4 result = {0};
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	result.w = left.w - right.w;
	return result;
}

dtb_function dtbV4 dtbVec4_Subtractf(dtbV4 left, float right)
{
	dtbV4 result = {0};
	result.x = left.x - right;
	result.y = left.y - right;
	result.z = left.z - right;
	result.w = left.w - right;
	return result;
}

dtb_function dtbV4 dtbVec4_Multiply(dtbV4 left, dtbV4 right)
{
	dtbV4 result = {0};
	result.x = left.x * right.x;
	result.y = left.y * right.y;
	result.z = left.z * right.z;
	result.w = left.w * right.w;
	return result;
}

dtb_function dtbV4 dtbVec4_Multiplyf(dtbV4 left, float right)
{
	dtbV4 result = {0};
	result.x = left.x * right;
	result.y = left.y * right;
	result.z = left.z * right;
	result.w = left.w * right;
	return result;
}

dtb_function dtbV4 dtbVec4_Divide(dtbV4 left, dtbV4 right)
{
	dtbV4 result = {0};
	result.x = left.x / right.x;
	result.y = left.y / right.y;
	result.z = left.z / right.z;
	result.w = left.w / right.w;
	return result;
}

dtb_function dtbV4 dtbVec4_Dividef(dtbV4 left, float right)
{
	dtbV4 result = {0};
	result.x = left.x / right;
	result.y = left.y / right;
	result.z = left.z / right;
	result.w = left.w / right;
	return result;
}

// NOTE(DILLON): Matrix4x4

dtb_function dtbM4 dtbMat4(){
	dtbM4 result = {0};
	return result;
}

dtb_function dtbM4 dtbMat4d(float diagonal){
	dtbM4 result = dtbMat4();
	
	result.elements[0][0] = diagonal;
	result.elements[1][1] = diagonal;
	result.elements[2][2] = diagonal;
	result.elements[3][3] = diagonal;
	return result;
}

dtb_function dtbM4 dtbMat4_Add(dtbM4 left, dtbM4 right){
	dtbM4 result;
	
	for(int columns = 0; columns < 4; columns++){
		for(int rows = 0; rows < 4; rows++){
			result.elements[columns][rows] = left.elements[columns][rows] + right.elements[columns][rows];
		}
	}
	
	return result;
}


dtb_function dtbM4 dtbMat4_Subtract(dtbM4 left, dtbM4 right){
	dtbM4 result;
	
	for(int columns = 0; columns < 4; columns++){
		for(int rows = 0; rows < 4; rows++){
			result.elements[columns][rows] = left.elements[columns][rows] - right.elements[columns][rows];
		}
	}
	
	return result;
}

dtb_function dtbM4 dtbMat4_Multiply(dtbM4 left, dtbM4 right){
	dtbM4 result;
	
	for(int columns = 0; columns < 4; columns++){
		for(int rows = 0; rows < 4; rows++){
			float sum = 0;
			for(int current_matrice = 0; current_matrice < 4; current_matrice++){
				sum += left.elements[current_matrice][rows] * right.elements[columns][current_matrice];
			}
			
			result.elements[columns][rows] = sum;
		}
	}
	
	return result;
}

dtb_function dtbM4 dtbMat4_Dividef(dtbM4 matrix, float scalar){
	dtbM4 result;
	
	for(int columns = 0; columns < 4; columns++){
		for(int rows = 0; rows < 4; rows++){
			result.elements[columns][rows] = matrix.elements[columns][rows] / scalar;
		}
	}
	
	return result;
}


#ifdef __cplusplus

dtb_function dtbV2 operator+(dtbV2 left, dtbV2 right){
	return dtbVec2_Add(left, right);
}

dtb_function dtbV2 operator+=(dtbV2 left, dtbV2 right){
    return left = left + right;
}

dtb_function dtbV2 operator-(dtbV2 left, dtbV2 right){
	return dtbVec2_Subtract(left, right);
}

dtb_function dtbV2 operator-=(dtbV2 left, dtbV2 right){
    return left = left - right;
}

dtb_function dtbV2 operator*(dtbV2 left, dtbV2 right){
	return dtbVec2_Multiply(left, right);
}

dtb_function dtbV2 operator*=(dtbV2 left, dtbV2 right){
    return left = left * right;
}

dtb_function dtbV2 operator/(dtbV2 left, dtbV2 right){
	return dtbVec2_Divide(left, right);
}

dtb_function dtbV2 operator/=(dtbV2 left, dtbV2 right){
    return left = left / right;
}

dtb_function dtbV2 operator+(dtbV2 left, float right)
{
	return dtbVec2_Addf(left, right);
}

dtb_function dtbV2 operator+(float left, dtbV2 right)
{
	return dtbVec2_Addf(right, left);
}

dtb_function dtbV2 operator+=(dtbV2 left, float right)
{
	return left = left + right;
}

dtb_function dtbV2 operator-(dtbV2 left, float right)
{
	return dtbVec2_Subtractf(left, right);
}

dtb_function dtbV2 operator-(float left, dtbV2 right)
{
	return dtbVec2_Subtractf(right, left);
}

dtb_function dtbV2 operator-=(dtbV2 left, float right)
{
	return left = left - right;
}

dtb_function dtbV2 operator*(dtbV2 left, float right)
{
	return dtbVec2_Multiplyf(left, right);
}

dtb_function dtbV2 operator*(float left, dtbV2 right)
{
	return dtbVec2_Multiplyf(right, left);
}

dtb_function dtbV2 operator*=(dtbV2 left, float right)
{
	return left = left * right;
}

dtb_function dtbV2 operator/(dtbV2 left, float right)
{
	return dtbVec2_Dividef(left, right);
}

dtb_function dtbV2 operator/(float left, dtbV2 right)
{
	return dtbVec2_Dividef(right, left);
}

dtb_function dtbV2 operator/=(dtbV2 left, float right){
	return left = left / right;
}

dtb_function DTB_MATH_B32 operator==(dtbV2 left, dtbV2 right)
{
    return dtbVec2_Equals(left, right);
}

dtb_function dtbV3 operator+(dtbV3 left, dtbV3 right){
	return dtbVec3_Add(left, right);
}

dtb_function dtbV3 operator+=(dtbV3 left, dtbV3 right){
    return left = left + right;
}

dtb_function dtbV3 operator-(dtbV3 left, dtbV3 right){
	return dtbVec3_Subtract(left, right);
}

dtb_function dtbV3 operator-=(dtbV3 left, dtbV3 right){
    return left = left - right;
}

dtb_function dtbV3 operator*(dtbV3 left, dtbV3 right){
	return dtbVec3_Multiply(left, right);
}

dtb_function dtbV3 operator*=(dtbV3 left, dtbV3 right){
    return left = left * right;
}

dtb_function dtbV3 operator/(dtbV3 left, dtbV3 right){
	return dtbVec3_Divide(left, right);
}

dtb_function dtbV3 operator/=(dtbV3 left, dtbV3 right){
    return left = left / right;
}

dtb_function dtbV3 operator+(dtbV3 left, float right)
{
	return dtbVec3_Addf(left, right);
}

dtb_function dtbV3 operator+(float left, dtbV3 right)
{
	return dtbVec3_Addf(right, left);
}

dtb_function dtbV3 operator+=(dtbV3 left, float right)
{
	return left = left + right;
}

dtb_function dtbV3 operator-(dtbV3 left, float right)
{
	return dtbVec3_Subtractf(left, right);
}

dtb_function dtbV3 operator-(float left, dtbV3 right)
{
	return dtbVec3_Subtractf(right, left);
}

dtb_function dtbV3 operator-=(dtbV3 left, float right)
{
	return left = left - right;
}

dtb_function dtbV3 operator*(dtbV3 left, float right)
{
	return dtbVec3_Multiplyf(left, right);
}

dtb_function dtbV3 operator*(float left, dtbV3 right)
{
	return dtbVec3_Multiplyf(right, left);
}

dtb_function dtbV3 operator*=(dtbV3 left, float right)
{
	return left = left * right;
}

dtb_function dtbV3 operator/(dtbV3 left, float right)
{
	return dtbVec3_Dividef(left, right);
}

dtb_function dtbV3 operator/(float left, dtbV3 right)
{
	return dtbVec3_Dividef(right, left);
}

dtb_function dtbV3 operator/=(dtbV3 left, float right)
{
	return left = left / right;
}

dtb_function DTB_MATH_B32 operator==(dtbV3 left, dtbV3 right)
{
    return dtbVec3_Equals(left, right);
}

dtb_function dtbV4 operator+(dtbV4 left, dtbV4 right){
	return dtbVec4_Add(left, right);
}

dtb_function dtbV4 operator+=(dtbV4 left, dtbV4 right){
	return left = left + right;
}

dtb_function dtbV4 operator-(dtbV4 left, dtbV4 right){
	return dtbVec4_Subtract(left, right);
}

dtb_function dtbV4 operator-=(dtbV4 left, dtbV4 right){
	return left = left - right;
}

dtb_function dtbV4 operator*(dtbV4 left, dtbV4 right){
	return dtbVec4_Multiply(left, right);
}

dtb_function dtbV4 operator*=(dtbV4 left, dtbV4 right){
	return left = left * right;
}

dtb_function dtbV4 operator/(dtbV4 left, dtbV4 right){
	return dtbVec4_Divide(left, right);
}

dtb_function dtbV4 operator/=(dtbV4 left, dtbV4 right){
	return left = left / right;
}

dtb_function dtbV4 operator+(dtbV4 left, float right)
{
	return dtbVec4_Addf(left, right);
}

dtb_function dtbV4 operator+(float left, dtbV4 right)
{
	return dtbVec4_Addf(right, left);
}

dtb_function dtbV4 operator+=(dtbV4 left, float right)
{
	return left = left + right;
}

dtb_function dtbV4 operator-(dtbV4 left, float right)
{
	return dtbVec4_Subtractf(left, right);
}

dtb_function dtbV4 operator-(float left, dtbV4 right)
{
	return dtbVec4_Subtractf(right, left);
}

dtb_function dtbV4 operator-=(dtbV4 left, float right)
{
	return left = left - right;
}

dtb_function dtbV4 operator*(dtbV4 left, float right)
{
	return dtbVec4_Multiplyf(left, right);
}

dtb_function dtbV4 operator*(float left, dtbV4 right)
{
	return dtbVec4_Multiplyf(right, left);
}

dtb_function dtbV4 operator*=(dtbV4 left, float right)
{
	return left = left * right;
}

dtb_function dtbV4 operator/(dtbV4 left, float right)
{
	return dtbVec4_Dividef(left, right);
}

dtb_function dtbV4 operator/(float left, dtbV4 right)
{
	return dtbVec4_Dividef(right, left);
}

dtb_function dtbV4 operator/=(dtbV4 left, float right)
{
	return left = left / right;
}

dtb_function DTB_MATH_B32 operator==(dtbV4 left, dtbV4 right)
{
    return dtbVec4_Equals(left, right);
}

dtb_function dtbM4 operator+(dtbM4 left, dtbM4 right){
	return dtbMat4_Add(left, right);
}

dtb_function dtbM4 operator+=(dtbM4 left, dtbM4 right){
    return left = left + right;
}

dtb_function dtbM4 operator-(dtbM4 left, dtbM4 right){
	return dtbMat4_Subtract(left, right);
}

dtb_function dtbM4 operator-=(dtbM4 left, dtbM4 right){
    return left = left - right;
}

dtb_function dtbM4 operator*(dtbM4 left, dtbM4 right){
	return dtbMat4_Multiply(left, right);
}

dtb_function dtbM4 operator*=(dtbM4 left, dtbM4 right){
    return left = left * right;
}

dtb_function dtbM4 operator/(dtbM4 left, float scalar){
	return dtbMat4_Dividef(left, scalar);
}

#endif

dtb_function dtbV3 dtbVec3_Normalize(dtbV3 vec)
{
	dtbV3 Result = { 0 };
	
	float f = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	
    Result.x = vec.x * (1.0f / f);
    Result.y = vec.y * (1.0f / f);
    Result.z = vec.z * (1.0f / f);
    
	return Result;
}

dtb_function dtbV3 dtbVec3_Cross(dtbV3 left, dtbV3 right)
{
	dtbV3 Result;
	
	Result.x = (left.y * right.z) - (left.z * right.y);
	Result.y = (left.z * right.x) - (left.x * right.z);
	Result.z = (left.x * right.y) - (left.y * right.x);
	
	return (Result);
}

dtb_function float dtbVec3_Dot(dtbV3 left, dtbV3 right)
{
	float Result = (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
	
	return (Result);
}

dtb_function dtbM4 dtbTranslate(dtbV3 translation){
	dtbM4 result = dtbMat4d(1.0f);
	
	result.elements[3][0] = translation.x;
	result.elements[3][1] = translation.y;
	result.elements[3][2] = translation.z;
	
	return result;
}

dtb_function dtbM4 dtbScale(dtbV3 scale){
    dtbM4 result = dtbMat4d(1.0f);
    
    result.elements[0][0] = scale.x;
    result.elements[1][1] = scale.y;
    result.elements[2][2] = scale.z;
    
    return result;
}

dtb_function dtbM4 dtbRotate(float angle, dtbV3 axis){
	dtbM4 result = dtbMat4d(1.0f);
	
	axis = dtbVec3_Normalize(axis);
	
	float sin_theta = sinf(ToRadians(angle));
	float cos_theta = cosf(ToRadians(angle));
	float cos_value = 1.0f - cos_theta;
	
	result.elements[0][0] = (axis.x * axis.y * cos_value) + cos_theta;
	result.elements[0][1] = (axis.x * axis.y * cos_value) + (axis.z * sin_theta);
	result.elements[0][2] = (axis.x * axis.z * cos_value) - (axis.y * sin_theta);
	
	result.elements[1][0] = (axis.y * axis.x * cos_value) - (axis.z * sin_theta);
	result.elements[1][1] = (axis.y * axis.y * cos_value) + cos_theta;
	result.elements[1][2] = (axis.y * axis.z * cos_value) + (axis.x * sin_theta);
	
	result.elements[2][0] = (axis.z * axis.x * cos_value) + (axis.y * sin_theta);
	result.elements[2][1] = (axis.z * axis.y * cos_value) - (axis.x * sin_theta);
	result.elements[2][2] = (axis.z * axis.z * cos_value) + cos_theta;
	
	return result;
}

dtb_function dtbM4 dtbFrustum(float right, float left, float top, float bottom, float mFar, float mNear)
{
	dtbM4 Result = {0};
	
	Result.elements[0][0] = 2 * mNear / (right - left);
	Result.elements[1][1] = 2 * mNear / (top - bottom);
	Result.elements[2][0] = (right + left) / (right - left);
	Result.elements[2][1] = (top + bottom) / (top - bottom);
	Result.elements[2][2] = -(mFar + mNear) / (mFar - mNear);
	Result.elements[2][3] = -1;
	Result.elements[3][2] = -2 * mFar * mNear / (mFar - mNear);
	
	return Result;
}

dtb_function dtbM4 dtbOrthographic(float left, float right, float bottom, float top, float mNear, float mFar)
{
	dtbM4 Result = {0};
	
	Result.elements[0][0] = 2.0f / (right - left);
    Result.elements[1][1] = 2.0f / (top - bottom);
    Result.elements[2][2] = 2.0f / (mNear - mFar);
    Result.elements[3][3] = 1.0f;
	
    Result.elements[3][0] = (left + right) / (left - right);
    Result.elements[3][1] = (bottom + top) / (bottom - top);
    Result.elements[3][2] = (mFar + mNear) / (mNear - mFar);
	return Result;
}

dtb_function dtbM4 dtbProjection(float right, float left, float top, float bottom, float mFar, float mNear)
{
	dtbM4 Result = {0};
	
	Result.elements[0][0] = 2 / (right - left);
	Result.elements[0][3] = -((right + left) / (right - left));
	Result.elements[1][1] = 2 / (top - bottom);
	Result.elements[1][3] = -((top + bottom) / (top - bottom));
	Result.elements[2][2] = -(2 / (mFar - mNear));
	Result.elements[2][3] = -((mFar + mNear) / (mFar - mNear));
	Result.elements[3][3] = 1;
	
	return Result;
}

dtb_function dtbM4 dtbPerspective(float FOV, float AspectRatio, float Near, float Far)
{
	dtbM4 Result = dtbMat4();
	
    float Cotangent = 1.0f / tanf(FOV * ( 3.14 / 360.0f));
    
    Result.elements[0][0] = Cotangent / AspectRatio;
    Result.elements[1][1] = Cotangent;
    Result.elements[2][3] = -1.0f;
    Result.elements[2][2] = (Near + Far) / (Near - Far);
    Result.elements[3][2] = (2.0f * Near * Far) / (Near - Far);
    Result.elements[3][3] = 0.0f;
	
    return (Result);
}

dtb_function dtbM4 dtbLookAt(dtbV3 Eye, dtbV3 Center, dtbV3 Up)
{
	dtbM4 Result;
	
	dtbV3 F = dtbVec3_Normalize(dtbVec3_Subtract(Center, Eye));
	dtbV3 S = dtbVec3_Normalize(dtbVec3_Cross(F, Up));
	dtbV3 U = dtbVec3_Cross(S, F);
	
	Result.elements[0][0] = S.x;
	Result.elements[0][1] = U.x;
	Result.elements[0][2] = -F.x;
	Result.elements[0][3] = 0.0f;
	
	Result.elements[1][0] = S.y;
	Result.elements[1][1] = U.y;
	Result.elements[1][2] = -F.y;
	Result.elements[1][3] = 0.0f;
	
	Result.elements[2][0] = S.z;
	Result.elements[2][1] = U.z;
	Result.elements[2][2] = -F.z;
	Result.elements[2][3] = 0.0f;
	
	Result.elements[3][0] = -dtbVec3_Dot(S, Eye);
	Result.elements[3][1] = -dtbVec3_Dot(U, Eye);
	Result.elements[3][2] = dtbVec3_Dot(F, Eye);
	Result.elements[3][3] = 1.0f;
	
	return (Result);
}

dtb_function dtbV2 dtbCross2f(dtbV2 vec)
{
	dtbV2 result = {0};
	result.x = vec.y;
	result.y = -vec.x;
	return result;
}

dtb_function float dtbDistancef(float x1, float y1, float x2, float y2)
{
	return sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
}

dtb_function float dtbDistancev(dtbV2 left, dtbV2 right)
{
	return sqrtf(powf(right.x - left.x, 2) + powf(right.y - left.y, 2));
}

dtb_function float dtbVec2_Length(dtbV2 vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

dtb_function float dtbVec3_Length(dtbV3 vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

dtb_function float dtbVec4_Length(dtbV4 vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
}

dtb_function void dtbV2_SetAngle(dtbV2 vec, float angle)
{
	float length = dtbVec2_Length(vec);
	
	vec.x = cos(angle) * length;
	vec.y = sin(angle) * length;
}


dtb_function int IsCircleColliding(dtbCircle c1, dtbCircle c2)
{
	return dtbDistancef(c1.x, c1.y, c2.x, c2.y) <= c1.radius + c2.radius;
}

dtb_function int dtbIsCirclePointColliding(float x, float y, dtbCircle c)
{
	return dtbDistancef(x, y, c.x, c.y) < c.radius;
}

#define DTB_MATH_H
#endif