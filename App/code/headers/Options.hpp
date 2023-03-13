#pragma once
#include <raylib.h>
class Options
{
public:
	~Options();
	void loop();
	static Options* getInstantiation();
private:
	static Options* instantiate_;
	Options();
	void load();
	void unload();
};

