#pragma once 

#include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock(void);
		Warlock(const Warlock &copy);
		Warlock &operator=(const Warlock &copy);

	public:
		Warlock(std::string n, std::string t);
		~Warlock(void);

		//Member functions
		std::string	const &getName() const;
		std::string	const &getTitle() const;
		void		setTitle(const std::string &t);
		void		introduce(void) const;
};
