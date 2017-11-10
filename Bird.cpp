#include "stdafx.h"
#include "Bird.h"


ostream &operator <<(ostream &output, const Bird &rightObj)
{
	output << rightObj.getName() << rightObj.getID();

	return output;
}

istream &operator >>(istream &input, Bird &rightObj)
{
	input >> rightObj.name >> rightObj.id;

	return input;
}

Bird::Bird()
{
	name = "Unknown";
	id = -1;
}

Bird::Bird(string name, int id)
{
	this->name = name;
	this->id = id;
}

Bird::~Bird()
{
}

string Bird::getName() const
{
	return name;
}

int Bird::getID() const
{
	return id;
}

bool Bird::operator <(const Bird &rightObj) const
{
	return (id < rightObj.getID());
}

bool Bird::operator <=(const Bird &rightObj) const
{
	return (*this == rightObj || *this < rightObj);
}

bool Bird::operator >(const Bird &rightObj) const
{
	return (id > rightObj.getID());
}

bool Bird::operator >=(const Bird &rightObj) const
{
	return (*this == rightObj || *this > rightObj);
}

bool Bird::operator ==(const Bird &rightObj) const
{
	return (id == rightObj.getID() && name == rightObj.getName());
}

bool Bird::operator !=(const Bird &rightObj) const
{
	return !
		(*this == rightObj);
}

