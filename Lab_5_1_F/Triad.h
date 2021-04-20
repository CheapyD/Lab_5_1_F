#pragma once
#include "MyException.h"
#include "MyDerivedException.h"

class Triad
{
private:
	double a, b, c;

public:
	Triad();
	Triad(double a, double b, double c) throw(out_of_range);
	Triad(const Triad& s);

	double GetA() const { return a; }
	double GetB() const { return b; }
	double GetC() const { return c; }

	void SetA(double value) { a = value; }
	void SetB(double value) { b = value; }
	void SetC(double value) { c = value; }

	Triad& operator = (const Triad& s);
	operator string () const;

	friend ostream& operator << (ostream& out, const Triad& s);
	friend istream& operator >> (istream& in, Triad& s) throw(MyException);
};

