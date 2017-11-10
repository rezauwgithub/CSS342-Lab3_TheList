#ifndef BIRD_H
#define BIRD_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bird
{
	friend ostream &operator <<(ostream &output, const Bird &rightObj);
	friend istream &operator >>(istream &input, Bird &rightObj);

	private:
		string name;
		int id;

	public:
		Bird();
		Bird(string name, int ID);
		~Bird();

		string getName() const;
		int getID() const;


		bool operator <(const Bird &rightObj) const;
		bool operator <=(const Bird &rightObj) const;
		bool operator >(const Bird &rightObj) const;
		bool operator >=(const Bird &rightObj) const;
		bool operator ==(const Bird &rightObj) const;
		bool operator !=(const Bird &rightObj) const;

};

#endif

