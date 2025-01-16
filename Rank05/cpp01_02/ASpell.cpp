#include "ASpell.hpp"

ASpell::ASpell() : _name("Unknown"), _effects("Unknown")
{}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{}

ASpell::ASpell(const ASpell &copy)
{
	*this = copy;
}

ASpell &ASpell::operator=(const ASpell &copy)
{
	this->_name = copy._name;
	this->_effects = copy._effects;
	return (*this);
}

ASpell::~ASpell(void)
{}

std::string ASpell::getName() const
{
	return (this->_name);
}

std::string ASpell::getEffects() const
{
	return (this->_effects);
}

void	ASpell::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}