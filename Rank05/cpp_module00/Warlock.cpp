#include "Warlock.hpp"

Warlock::Warlock() : name("Unknown"), title("Unknown")
{}

Warlock::Warlock(const Warlock &copy)
{
	*this = copy;
}

Warlock &Warlock::operator=(const Warlock &copy)
{
	this->name = copy.name;
	this->title = copy.title;
	return (*this);
}

Warlock::Warlock(std::string n, std::string t) : name(n), title(t)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const
{
	return (this->name);
}

std::string const &Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::setTitle(const std::string &t)
{
	this->title = t;
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
