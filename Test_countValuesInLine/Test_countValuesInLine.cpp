#include "pch.h"
#include "CppUnitTest.h"
#include "../CalculateMinimumPrintingTime/CalculateMinimumPrintingTime.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcountValuesInLine
{
	TEST_CLASS(TestcountValuesInLine)
	{
	public:
		
		TEST_METHOD(sampleTest)
		{
			std::string input_line = "0 1 2 3 4 5 6 7";
			int exp_res = 8;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(noSubstringsInString)
		{
			std::string input_line = "";
			int exp_res = 0;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(oneSubstringInString)
		{
			std::string input_line = "0";
			int exp_res = 1;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(manySubstringInString)
		{
			std::string input_line = "0 1 2";
			int exp_res = 3;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(tabDelimeter)
		{
			std::string input_line = "0\t1\t2\t3\t4\t5\t6\t7";
			int exp_res = 8;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(tabAndSpaceDelimeters)
		{
			std::string input_line = "0 1\t2 3\t4\t5\t6 7";
			int exp_res = 8;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(oneDelimiterAtBeginningAndAtEnd)
		{
			std::string input_line = "\t0 1 2 3 4 5 6 7\t";
			int exp_res = 8;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(manyDelimitersAtBeginningAndAtEnd)
		{
			std::string input_line = "\t \t0 1 2 3 4 5 6 7\t\t";
			int exp_res = 8;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(multipleSeparatorsInMiddle)
		{
			std::string input_line = "0 1 \t 2 3 4\t \t5\t\t6 7";
			int exp_res = 8;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(substringConsistsOfMultipleCharacters)
		{
			std::string input_line = "00 1 222 3333 4 5 6 7";
			int exp_res = 8;

			int res = countValuesInLine(input_line);
			Assert::AreEqual(exp_res, res);
		}
	};
}
