#include "pchGame.hpp"
#include "Navigator.hpp"
std::shared_ptr<Navigator> Navigator::instantiate_ = nullptr;

std::shared_ptr<Navigator> Navigator::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<Navigator>(new Navigator);
	}
	return instantiate_;
}
