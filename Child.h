#ifndef CHILD_H
#define CHILD_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Child
{
	friend ostream &operator <<(ostream &output, const Child &rightObj);
	friend istream &operator >>(istream &input, Child &rightObj);

	private:
		string firstName;
		string lastName;
		int age;

	public:
		Child();
		Child(string firstName, string lastName, int age);
		~Child();

		string getFirstName() const;
		string getLastName() const;
		int getAge() const;

		
		bool operator <(const Child &rightObj) const;
		bool operator <=(const Child &rightObj) const;
		bool operator >(const Child &rightObj) const;
		bool operator >=(const Child &rightObj) const;
		bool operator ==(const Child &rightObj) const;
		bool operator !=(const Child &rightObj) const;

};

#endif

