#include "Triangle_Public.h"

Triangle_Public::Triangle_Public()
	: Triad()
{}

Triangle_Public::Triangle_Public(double A, double B, double C) throw(logic_error)
{
	if (!(A + B > C && B + C > A && A + C > B))
		throw logic_error("Condition is not met");

	SetA(A); SetB(B); SetC(C);
}

Triangle_Public::Triangle_Public(const Triangle_Public& v)
	: Triad(v)
{}

Triangle_Public& Triangle_Public::operator ++() throw(out_of_range)
{
	this->SetA(this->GetA() + 1);
	if (GetA() > 10 || GetB() > 10 || GetC() > 10)
		throw out_of_range("Side is bigger than 10");
	return *this;
}

Triangle_Public& Triangle_Public::operator --() throw(MyDerivedException)
{
	this->SetB(this->GetB() - 1);
	if (GetB() == 0)
		throw new MyDerivedException();
	return *this;
}

Triangle_Public Triangle_Public::operator ++(int) throw (MyException)
{
	Triangle_Public a(*this);
	this->SetA(this->GetA() + 1);
	if (GetA() > 10 || GetB() > 10 || GetC() > 10)
		throw MyException("Side is bigger than 10");
	return a;
}

Triangle_Public Triangle_Public::operator --(int) throw(MyDerivedException)
{
	Triangle_Public a(*this);
	this->SetB(this->GetB() - 1);
	if (GetB() == 0)
		throw MyDerivedException();
	return a;
}

double Triangle_Public::Sum()
{
	return GetA() + GetB() + GetC();
}

double Triangle_Public::Square() const
{
	double a = GetA();
	double b = GetB();
	double c = GetC();
	double S = 0;
	double p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

void Triangle_Public::Angle(double& A, double& B, double& C) const
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