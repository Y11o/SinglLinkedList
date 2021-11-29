#include "pch.h"
#include "CppUnitTest.h"
#include "../SibglLinkedList/MyList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTests
{
	TEST_CLASS(ListTests)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1);
			Assert::IsTrue(list.get_size() == 0);
		}

		TEST_METHOD(Push_backTest)
		{
			MyList list;
			list.push_back(10);
			Assert::IsTrue(list.at(0) == 10);

		}

		TEST_METHOD(Get_SizeTest)
		{
			MyList list;
			list.push_back(10);
			Assert::IsTrue(list.get_size() == 1);
		}

		TEST_METHOD(AtTest)
		{
			MyList list;
			list.push_back(100);
			Assert::IsTrue(list.at(0) == 100);
		}

		TEST_METHOD(IsEmptyTest)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_back(20);
			Assert::IsTrue(list.isEmpty() == 0);
		}

		TEST_METHOD(Pop_frontTest)
		{
			MyList list;
			list.push_back(11);
			list.push_back(21);
			list.pop_front();
			Assert::IsTrue(list.at(0) == 21);
			Assert::IsTrue(list.get_size() == 1);
		}

		TEST_METHOD(ClearTest)
		{
			MyList list;
			list.push_back(11);
			list.push_back(21);
			list.clear();
			Assert::IsTrue(list.get_size() == 0);
		}

		TEST_METHOD(Push_frontTest)
		{
			MyList list;
			list.push_front(11);
			list.push_front(21);
			Assert::IsTrue(list.at(0) == 21);
			Assert::IsTrue(list.at(1) == 11);
		}

		TEST_METHOD(InsertTest)
		{
			MyList list;
			list.insert(5, 0);
			Assert::IsTrue(list.at(0) == 5);
			list.push_front(21);
			list.insert(40, 1);
			Assert::IsTrue(list.at(2) == 5);
			Assert::IsTrue(list.at(1) == 40);
			Assert::IsTrue(list.at(0) == 21);
		}

		TEST_METHOD(RemoveTest)
		{
			MyList list;
			list.push_front(10);
			list.push_front(20);
			list.push_front(30);
			list.remove(1);
			Assert::IsTrue(list.at(1) == 10);
			list.remove(0);
			Assert::IsTrue(list.at(0) == 10);
		}

		TEST_METHOD(SetTest)
		{
			MyList list;
			list.push_front(10);
			list.push_front(20);
			list.push_front(30);
			list.set(100, 1);
			Assert::IsTrue(list.at(1) == 100);
		}

		TEST_METHOD(Pop_backTest)
		{
			MyList list;
			list.push_front(10);
			list.push_front(20);
			list.push_front(30);
			Assert::IsTrue(list.get_size() == 3);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 2);
		}

		TEST_METHOD(ContainsTest)
		{
			MyList list;
			MyList list2;
			MyList list3;
			list.push_front(10);
			list.push_front(20);
			list.push_front(30);
			Assert::IsTrue(list.contains(list3) == 0);
			list3.push_back(13);
			list3.push_back(71);
			Assert::IsTrue(list3.contains(list) == 0);
			list2.push_front(10);
			list2.push_front(20);
			Assert::IsTrue(list.contains(list) == 1);
			Assert::IsTrue(list2.contains(list2) == 1);
			
			
		}
	};
}
