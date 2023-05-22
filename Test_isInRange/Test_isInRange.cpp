#include "pch.h"
#include "CppUnitTest.h"
#include "../CalculateMinimumPrintingTime/CalculateMinimumPrintingTime.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestisInRange
{
	TEST_CLASS(TestisInRange)
	{
	public:
		
		TEST_METHOD(sampleTest)
		{
			int value = 5;
			int left_border = 1;
			int rigth_border = 10;

			bool exp_res = true;
			bool res = isInRange(value, left_border, rigth_border);
			Assert::AreEqual(exp_res, res);
		}
		TEST_METHOD(leftBorderEqualsRight)
		{
			int value = 5;
			int left_border = 10;
			int rigth_border = 10;

			bool exp_res = false;
			bool res = isInRange(value, left_border, rigth_border);
			Assert::AreEqual(exp_res, res);
		}
        TEST_METHOD(leftBorderGreaterThanRight)
        {
            int value = 5;
            int left_border = 15;
            int right_border = 10;

            bool expected_result = false;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(valueLessThanLeftBorder)
        {
            int value = -10;
            int left_border = 1;
            int right_border = 10;

            bool expected_result = false;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(valueEqualsLeftBorder)
        {
            int value = 1;
            int left_border = 1;
            int right_border = 10;

            bool expected_result = true;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(valueGreaterThanRightBorder)
        {
            int value = 15;
            int left_border = 1;
            int right_border = 10;

            bool expected_result = false;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(valueEqualsRightBorder)
        {
            int value = 10;
            int left_border = 1;
            int right_border = 10;

            bool expected_result = true;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(leftBorderLessThanZero)
        {
            int value = 5;
            int left_border = -10;
            int right_border = 10;

            bool expected_result = true;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(leftBorderEqualsZero)
        {
            int value = 5;
            int left_border = 0;
            int right_border = 10;

            bool expected_result = true;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(leftAndRightBordersLessThanZeroValueOutOfRange)
        {
            int value = 5;
            int left_border = -10;
            int right_border = -5;

            bool expected_result = false;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(leftAndRightBordersLessThanZeroValueInRange)
        {
            int value = -6;
            int left_border = -10;
            int right_border = -5;

            bool expected_result = true;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(leftAndRightBordersEqualZero)
        {
            int value = 5;
            int left_border = 0;
            int right_border = 0;

            bool expected_result = false;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }

        TEST_METHOD(valueEqualsLeftAndRightBorders)
        {
            int value = 5;
            int left_border = 5;
            int right_border = 5;

            bool expected_result = true;
            bool result = isInRange(value, left_border, right_border);
            Assert::AreEqual(expected_result, result);
        }
	};
}
