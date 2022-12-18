#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 11.2/Laba 11.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* fname;
			fname = 3;
			int N = 3;
			Student* p = new Student[N];
			Create(p, fname, N);
			Print(p, N);
			LineSearch(p, N);
		}
	};
}
