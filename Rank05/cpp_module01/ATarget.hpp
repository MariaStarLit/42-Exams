#pragma once

#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string	_type;
		ATarget();

	public:
		ATarget(std::string type);
		ATarget(const ATarget &copy);
		ATarget &operator=(const ATarget &copy);
		virtual ~ATarget();

		std::string			getType(void) const;
		void				getHitBySpell(const ASpell &spell) const;
		virtual ATarget*	clone() const = 0;
};
