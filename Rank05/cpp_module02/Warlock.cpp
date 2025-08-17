#include "Warlock.hpp"

Warlock::Warlock() : _name("Unknown"), _title("Unknown")
{}

Warlock::Warlock(const Warlock &copy)
{
	*this = copy;
}

Warlock &Warlock::operator=(const Warlock &copy)
{
	this->_name = copy._name;
	this->_title = copy._title;
	return (*this);
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

std::string	Warlock::getName() const
{
	return (this->_name);
}

std::string	Warlock::getTitle() const
{
	return (this->_title);
}

void Warlock::setTitle(const std::string &title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
		_SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell_name)
{
	_SpellBook.forgetSpell(spell_name);
}

void Warlock::launchSpell(std::string spell_name, const ATarget &target)
{
	if (_SpellBook.createSpell(spell_name))
		_SpellBook.createSpell(spell_name)->launch(target);
}
