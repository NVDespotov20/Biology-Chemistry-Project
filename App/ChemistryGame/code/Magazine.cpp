#include "pchGame.hpp"
#include "Magazine.hpp"

Magazine::Magazine()
{
}

Magazine::~Magazine()
{
}

void Magazine::drawMagazine()
{
	DrawText("Magazine", 600, 600, 50, RED);
}