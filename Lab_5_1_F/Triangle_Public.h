#pragma once
#include "Triad.h"

class Triangle_Public : public Triad
{
public:
	Triangle_Public();
	Triangle_Public(double a, double b, double c) throw(logic_error);
	Triangle_Public(const Triangle_Public& v);

	Triangle_Public& operator ++ () throw(out_of_range);
	Triangle_Public& operator -- () throw(MyDerivedException);
	Triangle_Public operator ++ (int) throw(MyException);
	Triangle_Public operator -- (int) throw(MyDerivedException);

	double Sum();
	double Square() const;
	void Angle(double& A, double& B, double& C) const;
};