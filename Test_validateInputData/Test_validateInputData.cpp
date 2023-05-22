#include "pch.h"
#include "CppUnitTest.h"
#include "../CalculateMinimumPrintingTime/CalculateMinimumPrintingTime.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestvalidateInputData
{
	TEST_CLASS(TestvalidateInputData)
	{
	public:
		
		TEST_METHOD(sampleTest)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6};

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsFalse(exceptionThrown, L"No exceptions were thrown");
		}
		TEST_METHOD(paramNisLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { -1, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramNisRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 2*1e8 + 1, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramXisLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, -100, 1, 1, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramXisRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 100, 1, 1, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramYisLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 0, 1, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramYisRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 99, 1, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramL1isLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 0, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramL1isRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 19, 0.2, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramL2isLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 3, -9, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramL2isRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 3, 55, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramP1isLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramP1isRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 1, 3, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramP2isLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 3, 1, -1, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramP2isRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 3, 1, 11, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramK1isLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, -1, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramK1isRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 11, 1, 0.6, 6 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramK2isLeftOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, -9 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
		TEST_METHOD(paramK2isRightOfAllowedRange)
		{
			CalcMinPrintingTimeParams res_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 99 };

			bool exceptionThrown = false;
			try {
				validateInputData(res_params);
			}
			catch (const InvalidValueException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidValueException to be thrown.");
		}
	};
}
