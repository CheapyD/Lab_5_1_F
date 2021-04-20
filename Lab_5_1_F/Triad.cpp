#include "Triad.h"

Triad::Triad()
	: a(0), b(0), c(0)
{}

Triad::Triad(double a, double b, double c) throw (out_of_range)
{
	if (!((a > -10 && a < 10) || (b > -10 && b < 10) || (c > -10 && c < 10)))
		throw out_of_range("Numbers must belong to [-10;10]");

	this->a = a;
	this->b = b;
	this->c = c;
}

Triad::Triad(const Triad& A)
{
	SetA(A.GetA());
	SetB(A.GetB());
	SetC(A.GetC());
}

Triad& Triad::operator =(const Triad& n)
{
	SetA(n.GetA());
	SetB(n.GetB());
	SetC(n.GetC());
	return *this;
}

Triad::operator string() const
{
	stringstream ss;
	ss << "a = " << a << endl;
	ss << "b = " << b << endl;
	ss << "c = " << c << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const Triad& A)
{
	out << string(A);
	return out;
}

istream& operator >> (istream& in, Triad& A) throw(MyException)
{
	double a, b, c;
	cout << "a = "; in >> a;
	cout << "b = "; in >> b;
	cout << "c = "; in >> c;

	if (!((a > -10 && a < 10) || (b > -10 && b < 10) || (c > -10 && c < 10)))
		throw out_of_range("Numbers must belong to [-10;10]");

	A.SetA(a); A.SetB(b); A.SetC(c);
	return in;
}