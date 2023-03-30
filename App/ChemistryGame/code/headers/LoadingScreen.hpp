#pragma once
class LoadingScreen
{

public:
	LoadingScreen();
	~LoadingScreen();

private:
	void draw();

	bool loaded;
	Texture2D bgTexture;
	std::thread loadingThread;
};