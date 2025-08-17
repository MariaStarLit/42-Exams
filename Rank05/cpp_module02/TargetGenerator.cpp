#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::TargetGenerator(const TargetGenerator &copy)
{
	*this = copy;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &copy)
{
	this->_TargetG = copy._TargetG;
	return (*this);
}

TargetGenerator::~TargetGenerator()
{}

//Member functions
void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
	{
		_TargetG[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	if (target.empty())
		return ;
	if (_TargetG.find(target) != _TargetG.end())
		_TargetG.erase(_TargetG.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	ATarget	*tmp = NULL;

	if (_TargetG.find(target) != _TargetG.end())
		tmp= _TargetG[target];
	return (tmp);
}
