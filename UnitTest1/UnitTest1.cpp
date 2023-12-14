#include "pch.h"
#include "CppUnitTest.h"
#include "../81 іт/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            char str1[] = "abc aabbccabc";
            char str2[] = "abc abc abcgg";
            char str3[] = "xyz";

            Assert::AreEqual(4, countLetterGroups(str1));
            Assert::AreEqual(3, countLetterGroups(str2));
            Assert::AreEqual(0, countLetterGroups(str3));

            char* modifiedStr1 = Change(str1);
            char* modifiedStr2 = Change(str2);
            char* modifiedStr3 = Change(str3);

            Assert::AreEqual("** ******", modifiedStr1);
            Assert::AreEqual("** ** **gg", modifiedStr2);
            Assert::AreEqual("xyz", modifiedStr3);
            delete[] modifiedStr1;
            delete[] modifiedStr2;
            delete[] modifiedStr3;
        }
    };
}