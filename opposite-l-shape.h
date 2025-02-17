#pragma once

#include "shape.h"

class LL : public Shape
{
public:
	LL() : Shape()
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


