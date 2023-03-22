#include<pch.hpp>
std::shared_ptr<pch> pch::instantiate_ = nullptr;

std::shared_ptr<pch> pch::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<pch>(new pch);
	}
	return instantiate_;
}
