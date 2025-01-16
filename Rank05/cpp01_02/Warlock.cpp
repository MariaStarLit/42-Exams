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

void	Warlock::setTitle(const std::string &title)
{
	this->_title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
		{
			_SpellBook[spell->getName()] = spell->clone();
		}
	}
}

void	Warlock::forgetSpell(std::string spell_name)
{
	if (spell_name.empty())
		return ;
	if (_SpellBook.find(spell_name) != _SpellBook.end())
	{
		delete _SpellBook[spell_name];
		_SpellBook.erase(_SpellBook.find(spell_name));
	}
}

void	Warlock::launchSpell(std::string spell_name, const ATarget &target)
{
		if (spell_name.empty())
			return ;
		if (_SpellBook.find(spell_name) != _SpellBook.end())
		{
			_SpellBook[spell_name]->launch(target);
		}
}