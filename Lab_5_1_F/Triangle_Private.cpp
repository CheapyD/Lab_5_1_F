#include "Triangle_Private.h"

Triangle_Private::Triangle_Private()
	: Triad()
{}

Triangle_Private::Triangle_Private(double A, double B, double C) throw (logic_error)
{
	if (!(A + B > C && B + C > A && A + C > B))
		throw logic_error("Condition is not met");

	SetA(A); SetB(B); SetC(C);
}

Triangle_Private::Triangle_Private(const Triangle_Private& v)
	: Triad(v)
{}

Triangle_Private& Triangle_Private::operator = (const Triangle_Private& n)
{
	double a = n.GetA();
	double b = n.GetB();
	double c = n.GetC();
	return *this;
}

Triangle_Private::operator string () const
{
	stringstream ss;
	ss << endl;
	ss << "a = " << GetA() << endl;
	ss << "b = " << GetB() << endl;
	ss << "c = " << GetC() << endl;
	return ss.str();
}

Triangle_Private& Triangle_Private::operator ++() throw(out_of_range)
{
	this->SetA(this->GetA() + 1);
	if (GetA() > 10)
		throw out_of_range("Side is bigger than 10");
	return *this;
}

Triangle_Private& Triangle_Private::operator --() throw(MyDerivedException)
{
	this->SetB(this->GetB() - 1);
	if (GetB() <= 0)
		throw new MyDerivedException();
	return *this;
}

Triangle_Private Triangle_Private::operator ++(int) throw (MyException)
{
	Triangle_Private a(*this);
	this->SetA(this->GetA() + 1);
	if (GetA() > 10)
		throw MyException("Side is bigger than 10");
	return a;
}

Triangle_Private Triangle_Private::operator --(int) throw(MyDerivedException)
{
	Triangle_Private a(*this);
	this->SetB(this->GetB() - 1);
	if (GetB() <= 0)
		throw MyDerivedException();
	return a;
}

ostream& operator <<(ostream& out, const Triangle_Private& s)
{
	out << (string)s;
	return out;
}

istream& operator >>(istream& in, Triangle_Private& s) throw (logic_error)
{
	double a, b, c;
	cout << "a = "; in >> a;
	cout << "b = "; in >> b;
	cout << "c = "; in >> c;

	if (!(a + b > c && b + c > a && a + c > b))
		throw logic_error("Condition is not met");

	s.SetA(a); s.SetB(b); s.SetC(c);
}

double Triangle_Private::Sum()
{
	return GetA() + GetB() + GetC();
}

double Triangle_Private::Square() const
{
	double a = GetA();
	double b = GetB();
	double c = GetC();
	double S = 0;
	double p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

void Triangle_Private::Angle(double& A, double& B, double& C) const
{
	const double PI = atan(1) * 4;
	double a = GetA();
	double b = GetB();
	double c = GetC();

	double S = Square();
	double sinA = (S * 2) / (a * b);
	double x1 = asin(sinA);
	A = (x1 * 180) / PI;

	double sinB = (sinA * b) / c;
	double x2 = asin(sinB);
	B = (x2 * 180) / PI;

	C = 180 - (A + B);
}