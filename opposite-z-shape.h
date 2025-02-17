#pragma once

#include "shape.h"

class ZZ : public Shape
{
public:
	ZZ() : Shape()
	{
		mShapeColor = Color::Green;
	}
	void initializePosition();
	void initializeOrientation();
	void previewPosition();
	void initializeColor();
private:
	Color mShapeColor;
};


