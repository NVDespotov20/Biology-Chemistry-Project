#include "pch.hpp"
#include "Button.hpp"

Button::Button()
{
	label = "BUTTON";
	fontSize = 40;
	boundingBox = {
		0,
		0,
		320,
		50
	};
	centerLabel();
}

Button::Button(const char label[], float x, float y, float width, float height, int fontSize) :
	label(label), boundingBox({x,y,width,height}), fontSize(fontSize)
{
	centerLabel();
}

void Button::setLabel(const char label[])
{
	this->label = label;
	centerLabel();
}

void Button::centerLabel()
{
	if (label == "")
		return;

	Vector2 labelSize = MeasureTextEx(GetFontDefault(), label, fontSize, 1);
	labelPos = {
		boundingBox.x + boundingBox.width / 2 - labelSize.x / 2,
		boundingBox.y + boundingBox.height / 2 - labelSize.y / 2
	};
}

void Button::draw(float roundness, int segments, Color buttonColor, Color textColor)
{
	DrawRectangleRounded(boundingBox, roundness, segments, buttonColor);

	if (label == "")
		return;
	DrawText(label, labelPos.x, labelPos.y, fontSize, textColor);
}

Rectangle Button::getBoundingBox() const
{
	return boundingBox;
}
