#pragma once

#include <vector>
#include <string>

typedef struct _tagCustomizeTime
{
	int Year;
	int Mon;
	int Day;
	int Hour;
	int Min;
	int Second;
}CustomizeTime;

enum EcPosType
{
	Null = -1,
	TopLeft,
	TopCenter,
	TopRight,
	RightCenter,
	BottomRight,
	BottomCenter,
	BottomLeft,
	LeftCenter,
	SelectRect,
};