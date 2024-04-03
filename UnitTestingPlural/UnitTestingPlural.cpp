#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication4/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestingPlural
{
	TEST_CLASS(SetTest)
	{
	public:
		TEST_METHOD(TestAdd)
		{
			Plural<int> set;
			// Add and check
			set.add(5);
			Assert::AreEqual(1, set.size());
			Assert::IsTrue(set.contain(5));
			
			// Add some elements and check
			set.add(10);
			set.add(15);
			Assert::AreEqual(3, set.size());
			Assert::IsTrue(set.contain(10));
			Assert::IsTrue(set.contain(15));

			// Add negative and check
			set.add(-5);
			Assert::AreEqual(4, set.size());
			Assert::IsTrue(set.contain(-5));
		}

		TEST_METHOD(TestAddRange)
		{
			Plural<int> set;
			// Add range and check
			int arr[] = { 1, 2, 3 };
			set.addRange(arr, 3);
			Assert::AreEqual(3, set.size());
			Assert::IsTrue(set.contain(1));
			Assert::IsTrue(set.contain(2));
			Assert::IsTrue(set.contain(3));

			// Add one more range and check
			int newArr[] = { 4, 5, 6 };
			set.addRange(newArr, 3);
			Assert::AreEqual(6, set.size());
			Assert::IsTrue(set.contain(4));
			Assert::IsTrue(set.contain(5));
			Assert::IsTrue(set.contain(6));

			// Add negative range and check
			int negativeArr[] = { -1, -2, -3 };
			set.addRange(negativeArr, 3);
			Assert::AreEqual(9, set.size());
			Assert::IsTrue(set.contain(-1));
			Assert::IsTrue(set.contain(-2));
			Assert::IsTrue(set.contain(-3));
		}

		TEST_METHOD(TestRemove)
		{
			Plural<int> set;
			// Add
			set.add(5);
			set.add(10);
			// Remove and check
			set.remove(5);
			Assert::AreEqual(1, set.size());
			Assert::IsFalse(set.contain(5));
			Assert::IsTrue(set.contain(10));
			
			// Remove unreal element and check
			set.remove(20);
			Assert::AreEqual(1, set.size());
			Assert::IsFalse(set.contain(20));

			// Remove unreal negative and check
			set.remove(-10);
			Assert::AreEqual(1, set.size());
			Assert::IsFalse(set.contain(-10));
		}

		TEST_METHOD(TestClear)
		{
			Plural<int> set;
			set.clear();
			// Check if empty
			Assert::AreEqual(0, set.size());

			// Add, clear and check
			set.add(5);
			set.add(10);
			set.add(15);
			set.clear();
			Assert::AreEqual(0, set.size());

			// Add and check if plural have true size
			set.add(20);
			set.add(25);
			Assert::AreEqual(2, set.size());
			Assert::IsTrue(set.contain(20));
			Assert::IsTrue(set.contain(25));
		}
	};
}