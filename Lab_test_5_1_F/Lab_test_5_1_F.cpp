#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1_F/Triangle_Public.cpp"
#include "../Lab_5_1_F/Triangle_Private.cpp"
#include "../Lab_5_1_F/Triad.cpp"
#include "../Lab_5_1_F/MyDerivedException.cpp"
#include "../Lab_5_1_F/MyException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest51F
{
	TEST_CLASS(Labtest51F)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Triangle_Private T(3, 4, 5);
			Assert::AreEqual(T.Square(), 6.0);
		}

		TEST_METHOD(TestMethod2)
		{
			Triangle_Public K(5, 5, 5);
			Assert::AreEqual(K.Sum(), 15.0);
		}
	};
}