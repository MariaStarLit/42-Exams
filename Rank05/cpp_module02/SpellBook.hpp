#pragma once 

#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		std::map <std::string, ASpell*> _SpellBook;

		SpellBook(const SpellBook &copy);
		SpellBook &operator=(const SpellBook &copy);

	public:
		SpellBook();
		~SpellBook();

		//Member functions
		void	learnSpell(ASpell*);
		void	forgetSpell(std::string const &);
		ASpell*	createSpell(std::string const &);
};