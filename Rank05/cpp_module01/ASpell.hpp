#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string	_name;
		std::string	_effects;
		ASpell(void);

	public:
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell &copy);
		ASpell &operator=(const ASpell &copy);
		virtual ~ASpell(void);

		//Member functions
		std::string		getName() const;
		std::string		getEffects() const;
		void			launch(const ATarget &target);
		virtual ASpell*	clone() const = 0;
};
