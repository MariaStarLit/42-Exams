#include "ASpell.hpp"

ASpell::ASpell() : name("Unknown"), title("Unknown")
{}

ASpell::ASpell(std::string name, std::string effects) : _name(n), _effects(e)
{
	std::cout << "Spell " << this->_name << ": Created." << std::endl;
}

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
{
	std::cout << "Spell " << this->_name << ": Destroid." << std::endl;
}

std::string const &ASpell::getName() const
{
	return (this->_name);
}

std::string const &ASpell::getEffects() const
{
	return (this->_effects);
}
