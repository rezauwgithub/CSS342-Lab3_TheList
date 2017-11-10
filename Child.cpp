#include "stdafx.h"
#include "Child.h"


ostream &operator <<(ostream &output, const Child &rightObj)
{
	output << rightObj.getFirstName() << rightObj.getLastName() << rightObj.getAge();

	return output;
}

istream &operator >>(istream &input, Child &rightObj)
{
	input >> rightObj.firstName >> rightObj.lastName >> rightObj.age;

	return input;
}

Child::Child()
{
	firstName = "Unknown";
	lastName = "Unknown";
	age = -1;
}

Child::Child(string firstName, string lastName, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}

Child::~Child()
{
}

string Child::getFirstName() const
{
	return firstName;
}

string Child::getLastName() const
{
	return lastName;
}

int Child::getAge() const
{
	return age;
}


bool Child::operator <(const Child &rightObj) const
{
	if (lastName == rightObj.getLastName())
	{
		if (firstName < rightObj.getFirstName())
		{
			return true;
		}
	}
	else if (lastName < rightObj.getLastName())
	{
		return true;
	}


	return false;
}

bool Child::operator <=(const Child &rightObj) const
{
	return (*this == rightObj || *this < rightObj);
}

bool Child::operator >(const Child &rightObj) const
{
	if (lastName == rightObj.getLastName())
	{
		if (firstName > rightObj.getFirstName())
		{
			return true;
		}
	}
	else if (lastName > rightObj.getLastName())
	{
		return true;
	}


	return false;
}

bool Child::operator >=(const Child &rightObj) const
{
	return (*this == rightObj || *this > rightObj);
}

bool Child::operator ==(const Child &rightObj) const
{
	return (firstName == rightObj.getFirstName() && 
		lastName == rightObj.getLastName() && 
		age == rightObj.getAge());
}

bool Child::operator !=(const Child &rightObj) const
{
	return !
		(*this == rightObj);
}




