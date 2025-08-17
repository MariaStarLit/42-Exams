#include "ATarget.hpp"

ATarget::ATarget() : _type("Villan")
{}

ATarget::ATarget(std::string type) : _type(type)
{}

ATarget::ATarget(const ATarget &copy)
{
	*this = copy;
}

ATarget &ATarget::operator=(const ATarget &copy)
{
	this->_type = copy._type;
	return (*this);
}

ATarget::~ATarget()
{}

std::string	ATarget::getType(void) const
{
	return (this->_type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}