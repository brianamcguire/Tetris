#pragma once

#include "shape.h"

class T : public Shape
{
public:
	T() : Shape()
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




