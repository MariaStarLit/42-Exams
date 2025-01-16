#pragma once 

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		std::map <std::string, ATarget*> _TargetG;

		TargetGenerator(const TargetGenerator &copy);
		TargetGenerator &operator=(const TargetGenerator &copy);

	public:
		TargetGenerator();
		~TargetGenerator();

		//Member functions
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};