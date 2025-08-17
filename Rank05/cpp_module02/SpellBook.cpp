#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::SpellBook(const SpellBook &copy)
{
	*this = copy;
}

SpellBook &SpellBook::operator=(const SpellBook &copy)
{
	this->_SpellBook = copy._SpellBook;
	return (*this);
}

SpellBook::~SpellBook()
{}

//Member functions
void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		_SpellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
	if (spell_name.empty())
		return ;
	if (_SpellBook.find(spell_name) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(spell_name));
}

ASpell*	SpellBook::createSpell(std::string const &spell_name)
{
	ASpell *tmp = NULL;

	if (_SpellBook.find(spell_name) != _SpellBook.end())
		tmp= _SpellBook[spell_name];
	return (tmp);
}