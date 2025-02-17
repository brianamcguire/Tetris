#pragma once

#include "shape.h"

class L : public Shape
{
public:
	L() : Shape()
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

