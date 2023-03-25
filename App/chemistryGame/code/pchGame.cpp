#include"pchGame.hpp"
std::shared_ptr<Direction> Direction::instantiate_ = nullptr;

std::shared_ptr<Direction> Direction::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<Direction>(new Direction);
	}
	return instantiate_;
}