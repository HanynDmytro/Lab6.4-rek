#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 1, 2, 3, 4, 5, 6 };
			int size = 6;
			int result = sumOddIndexElements(arr, size);
			Assert::AreEqual(12, result); // 2 + 4 + 6 = 12
		}
	};
}
