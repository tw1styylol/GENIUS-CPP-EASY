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

        TEST_METHOD(TestSetUnion)
        {
            // Positive numbers test
            Plural<int> set1;
            set1.add(1);
            set1.add(2);
            set1.add(3);

            Plural<int> set2;
            set2.add(2);
            set2.add(3);
            set2.add(4);

            Plural<int> unionSet = set1.set_union(set2);
            Assert::AreEqual(4, unionSet.size());
            Assert::IsTrue(unionSet.contain(1));
            Assert::IsTrue(unionSet.contain(2));
            Assert::IsTrue(unionSet.contain(3));
            Assert::IsTrue(unionSet.contain(4));

            // Negative numbers test
            Plural<int> set3;
            set3.add(-1);
            set3.add(-2);
            set3.add(-3);

            Plural<int> set4;
            set4.add(-2);
            set4.add(-3);
            set4.add(-4);

            Plural<int> unionSet2 = set3.set_union(set4);
            Assert::AreEqual(4, unionSet2.size());
            Assert::IsTrue(unionSet2.contain(-1));
            Assert::IsTrue(unionSet2.contain(-2));
            Assert::IsTrue(unionSet2.contain(-3));
            Assert::IsTrue(unionSet2.contain(-4));

            // Char test
            Plural<char> set5;
            set5.add('a');
            set5.add('b');
            set5.add('c');

            Plural<char> set6;
            set6.add('b');
            set6.add('c');
            set6.add('d');

            Plural<char> unionSet3 = set5.set_union(set6);
            Assert::AreEqual(4, unionSet3.size());
            Assert::IsTrue(unionSet3.contain('a'));
            Assert::IsTrue(unionSet3.contain('b'));
            Assert::IsTrue(unionSet3.contain('c'));
            Assert::IsTrue(unionSet3.contain('d'));
        }

        TEST_METHOD(TestIntersect)
        {
            // Positive numbers test
            Plural<int> set1;
            set1.add(1);
            set1.add(2);
            set1.add(3);

            Plural<int> set2;
            set2.add(2);
            set2.add(3);
            set2.add(4);

            Plural<int> intersectSet = set1.intersect(set2);
            Assert::AreEqual(2, intersectSet.size());
            Assert::IsTrue(intersectSet.contain(2));
            Assert::IsTrue(intersectSet.contain(3));

            // Negative numbers test
            Plural<int> set3;
            set3.add(-1);
            set3.add(-2);
            set3.add(-3);

            Plural<int> set4;
            set4.add(-2);
            set4.add(-3);
            set4.add(-4);

            Plural<int> intersectSet2 = set3.intersect(set4);
            Assert::AreEqual(2, intersectSet2.size());
            Assert::IsTrue(intersectSet2.contain(-2));
            Assert::IsTrue(intersectSet2.contain(-3));

            // Char test
            Plural<char> set5;
            set5.add('a');
            set5.add('b');
            set5.add('c');

            Plural<char> set6;
            set6.add('b');
            set6.add('c');
            set6.add('d');

            Plural<char> intersectSet3 = set5.intersect(set6);
            Assert::AreEqual(2, intersectSet3.size());
            Assert::IsTrue(intersectSet3.contain('b'));
            Assert::IsTrue(intersectSet3.contain('c'));
        }

        
        TEST_METHOD(TestDifference)
        {
            // Positive numbers test
            Plural<int> set1;
            set1.add(1);
            set1.add(2);
            set1.add(3);

            Plural<int> set2;
            set2.add(2);
            set2.add(3);
            set2.add(4);

            Plural<int> differenceSet = set1.difference(set2);
            Assert::AreEqual(1, differenceSet.size());
            Assert::IsTrue(differenceSet.contain(1));
            Assert::IsFalse(differenceSet.contain(2));
            Assert::IsFalse(differenceSet.contain(3));
            Assert::IsFalse(differenceSet.contain(4));

            // Negative numbers test
            Plural<int> set3;
            set3.add(-1);
            set3.add(-2);
            set3.add(-3);

            Plural<int> set4;
            set4.add(-2);
            set4.add(-3);
            set4.add(-4);

            Plural<int> differenceSet2 = set3.difference(set4);
            Assert::AreEqual(1, differenceSet2.size());
            Assert::IsTrue(differenceSet2.contain(-1));
            Assert::IsFalse(differenceSet2.contain(-2));
            Assert::IsFalse(differenceSet2.contain(-3));
            Assert::IsFalse(differenceSet2.contain(-4));

            // Char test
            Plural<char> set5;
            set5.add('a');
            set5.add('b');
            set5.add('c');

            Plural<char> set6;
            set6.add('b');
            set6.add('c');
            set6.add('d');

            Plural<char> differenceSet3 = set5.difference(set6);
            Assert::AreEqual(1, differenceSet3.size());
            Assert::IsTrue(differenceSet3.contain('a'));
            Assert::IsFalse(differenceSet3.contain('b'));
            Assert::IsFalse(differenceSet3.contain('c'));
            Assert::IsFalse(differenceSet3.contain('d'));
        }
	};
}