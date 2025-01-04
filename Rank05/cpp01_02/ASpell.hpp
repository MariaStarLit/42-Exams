#pragma once

#include <iostream>

class ASpell
{
	private:
		std::string _name;
		std::string _effects;
		ASpell(void);

	public:
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell &copy);
		ASpell &operator=(const ASpell &copy);
		~ASpell(void);

		//Member functions
		std::string const &getName() const;
		std::string const &getEffects() const;
};
