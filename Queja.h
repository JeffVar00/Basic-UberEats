#ifndef QUEJA_H
#define QUEJA_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
class Queja {
public:
	Queja();
	Queja(string *, string *);
	void setCed(string *);
	void setDescrip(string *);
	string getCed();
	string getDescrip();
	string toStringQueja();
	virtual ~Queja();
private:
	string *Ced;
	string *Descrip;
};

#endif

