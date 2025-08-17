#pragma once

#include <iostream>
#include <map>
#include "Fwoosh.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		SpellBook	_SpellBook;

		Warlock(void);
		Warlock(const Warlock &copy);
		Warlock &operator=(const Warlock &copy);

	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);

		//Member functions
		std::string	getName(void) const;
		std::string	getTitle(void) const;
		void		setTitle(const std::string &title);
		void		introduce(void) const;
		void		learnSpell(ASpell *spell);
		void		forgetSpell(std::string spell_name);
		void		launchSpell(std::string spell_name, const ATarget &target);
};
