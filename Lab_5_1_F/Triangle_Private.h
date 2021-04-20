#pragma once
#include "Triad.h"

class Triangle_Private : private Triad
{
public:
	using Triad::GetA;
	using Triad::GetB;
	using Triad::GetC;

	using Triad::SetA;
	using Triad::SetB;
	using Triad::SetC;

	using Triad::Triad;

	Triangle_Private();
	Triangle_Private(double a, double b, double c) throw (logic_error);
	Triangle_Private(const Triangle_Private& s);

	Triangle_Private& operator = (const Triangle_Private& s);
	operator string () const;

	Triangle_Private& operator ++ () throw (out_of_range);
	Triangle_Private& operator -- () throw (MyDerivedException);
	Triangle_Private operator ++ (int) throw (MyException);
	Triangle_Private operator -- (int) throw (MyDerivedException);

	friend ostream& operator << (ostream& out, const Triangle_Private& s);
	friend istream& operator >> (istream& in, Triangle_Private& s) throw (logic_error);

	double Sum();
	double Square() const;
	void Angle(double& A, double& B, double& C) const;
};