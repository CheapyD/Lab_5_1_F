#include "MyDerivedException.h"

const char* MyDerivedException::What() const
{
	return "Exception: MyDerivedException: side can't be == 0";
}