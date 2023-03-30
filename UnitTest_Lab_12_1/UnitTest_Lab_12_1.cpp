#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_1/Lab_12_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab121
{
	TEST_CLASS(UnitTestLab121)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Elem* p;

            p = new Elem;                       //1
            p->info = 1;                        //2
            p->link1 = new Elem;                //3
            p->link1->info = 2;                 //4
            p->link1->link1 = p;                //5
            p->link1->link2 = new Elem;         //6
            p->link1->link2->info = 3;          //7
            p->link1->link2->link1 = p->link1;  //8
            p->link2 = new Elem;                //9
            p->link2->info = 4;                 //10
            p->link2->link2 = NULL;             //11
            p->link1->link2->link2 = p->link2;  //12
            p->link2->link1 = p->link1;         //13

			Assert::AreEqual(p->link1->info, p->link2->link1->info);
            Assert::AreEqual(p->info, p->link1->link1->info);
            Assert::AreEqual(p->link2->info, p->link1->link2->link2->info);
		}
	};
}
