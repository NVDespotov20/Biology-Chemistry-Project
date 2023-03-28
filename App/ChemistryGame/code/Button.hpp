#pragma once

class Button
{
public:

	Button();
	Button(const char label[], float x, float y, float width, float height, int fontSize);

	void setLabel(const char label[]);
	void centerLabel();
	void draw(float roundness, int segments, Color buttonColor, Color textColor);
	Rectangle getBoundingBox() const;

private:

	const char* label = new char[50];
	Rectangle boundingBox;
	Vector2 labelPos;
	int fontSize;

};

