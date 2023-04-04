#pragma once // This is a preprocessor directive that ensures the header file is only included once in the compilation process.

#include "Button.hpp" // Including the header file for the Button class.
#include "FileReader.hpp" // Including the header file for the FileReader class.

class App
{
public:
	~App(); // Destructor of the App class.
	void drawUI(); // Member function to draw the user interface.
	void setSizes(); // Member function to set the sizes of the interface elements.
	void setButtons(); // Member function to set the buttons of the interface.
	void showInfo(int indexOfMuscle); // Member function to show the information of a muscle.

	static std::shared_ptr<App> getInstantiation(); // Static member function to get an instance of the App class.
private:
	App(); // Constructor of the App class.

	
	static std::shared_ptr<App> instantiate_; // Static shared pointer to an instance of the App class.

	void load(); // Member function to load the interface elements.
	void unload(); // Member function to unload the interface elements.
	void checkInput(); // Member function to check the user input.

	int indexOfButtons; // Index of the buttons.
	int fontSize = 20; // Font size of the interface elements.
	int sizeOfmuscleButtons; // Size of the muscle buttons.

	float WIDTH, offsetX; // Width and X offset of the interface elements.
	float HEIGHT, offsetY; // Height and Y offset of the interface elements.

	Texture2D background; // Texture for the background of the interface.

	Texture2D nextButton; // Texture for the "next" button of the interface.
	Texture2D previousButton; // Texture for the "previous" button of the interface.

	Texture2D humanBody; // Texture for the human body of the interface.
	Texture2D* selectedMuscle; // Pointer to the selected muscle texture of the interface.
	Texture2D muscleTextures[12]; // Array of muscle textures of the interface.

	std::string muscleNames[12]; // Array of muscle names of the interface.

	Button muscles[12]; // Array of muscle buttons of the interface.
	Button backButton; // Button to go back in the interface.

	Rectangle nextButtonRec; // Rectangle for the "next" button of the interface.
	Rectangle previousButtonRec; // Rectangle for the "previous" button of the interface.
	Rectangle sideOfHumanRec; // Rectangle for the side of the human body of the interface.

	Vector2 mousePoint; // Vector for the mouse position of the interface.
	Vector2 sideOfHumanVec; // Vector for the side of the human body of the interface.
	Vector2 lineOfButtons[2]; // Array of vectors for the line of buttons of the interface.

	FileReader fReader; // Object of the FileReader class for reading files.
	std::string muscleInfo; // String for the information of a muscle.
};