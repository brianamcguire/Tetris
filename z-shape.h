#pragma once

#include "shape.h"

class Z : public Shape
{
public:
	Z() : Shape()
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


