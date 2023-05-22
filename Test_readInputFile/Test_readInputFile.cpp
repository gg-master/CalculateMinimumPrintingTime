#include "pch.h"
#include "CppUnitTest.h"
#include <filesystem>
#include "../CalculateMinimumPrintingTime/CalculateMinimumPrintingTime.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


bool compareCalcMinPrintingParams(CalcMinPrintingTimeParams first, CalcMinPrintingTimeParams second) {
	if (first.numOfSheets != second.numOfSheets) return false;
	if (first.firstPrintingTime != second.firstPrintingTime) return false;
	if (first.secondPrintingTime != second.secondPrintingTime) return false;
	if (first.firstPrinterUptime != second.firstPrinterUptime) return false;
	if (first.firstPrinterFailureProbability != second.firstPrinterFailureProbability) return false;
	if (first.firstPrinterRepairTime != second.firstPrinterRepairTime) return false;
	if (first.secondPrinterUptime != second.secondPrinterUptime) return false;
	if (first.secondPrinterFailureProbability != second.secondPrinterFailureProbability) return false;
	if (first.secondPrinterRepairTime != second.secondPrinterRepairTime) return false;
	return true;
}

namespace TestreadInputFile
{
	TEST_CLASS(TestreadInputFile)
	{
	private:
		std::filesystem::path currentPath = std::filesystem::current_path().parent_path().parent_path();
	public:
		TEST_METHOD(sampleTest)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\sampleTest.txt";

			CalcMinPrintingTimeParams exp_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
		TEST_METHOD(emptyFile)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\emptyFile.txt";
			CalcMinPrintingTimeParams res_params = { };

			bool exceptionThrown = false;
			try {
				readInputFile(filePath.string(), &res_params);
			}
			catch (const InvalidInputFileException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidInputFileException to be thrown.");
		}
		TEST_METHOD(moreThanOneLineInFile)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\moreThanOneLineInFile.txt";

			CalcMinPrintingTimeParams exp_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
		TEST_METHOD(firstLineHasOneSubstring)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\firstLineHasOneSubstring.txt";
			CalcMinPrintingTimeParams res_params = { };

			bool exceptionThrown = false;
			try {
				readInputFile(filePath.string(), &res_params);
			}
			catch (const InvalidInputFileException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidInputFileException to be thrown.");
		}
		TEST_METHOD(firstLineHasTwoSubstrings)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\firstLineHasTwoSubstrings.txt";
			CalcMinPrintingTimeParams res_params = { };

			bool exceptionThrown = false;
			try {
				readInputFile(filePath.string(), &res_params);
			}
			catch (const InvalidInputFileException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidInputFileException to be thrown.");
		}
		TEST_METHOD(tabDelimeter)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\tabDelimeterType.txt";

			CalcMinPrintingTimeParams exp_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
		TEST_METHOD(tabAndSpaceDelimeters)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\tabAndSpaceDelimeters.txt";

			CalcMinPrintingTimeParams exp_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
		TEST_METHOD(oneDelimiterAtBginningAndAtEnd)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\oneDelimiterAtBginningAndAtEnd.txt";

			CalcMinPrintingTimeParams exp_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
		TEST_METHOD(multipleDelimetersAtBginningAndAtEnd)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\multipleDelimetersAtBginningAndAtEnd.txt";

			CalcMinPrintingTimeParams exp_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
		TEST_METHOD(multipleDelimetersInMiddle)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\multipleDelimetersInMiddle.txt";

			CalcMinPrintingTimeParams exp_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
		TEST_METHOD(substringContainsOneCharacterThatDoesntFormNumber)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\substringContainsOneCharacterThatDoesntFormNumber.txt";
			CalcMinPrintingTimeParams res_params = { };

			bool exceptionThrown = false;
			try {
				readInputFile(filePath.string(), &res_params);
			}
			catch (const InvalidInputFileException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidInputFileException to be thrown.");
		}
		TEST_METHOD(substringContainsMultimpleCharactersThatDontFormNumber)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\substringContainsMultimpleCharactersThatDontFormNumber.txt";
			CalcMinPrintingTimeParams res_params = { };

			bool exceptionThrown = false;
			try {
				readInputFile(filePath.string(), &res_params);
			}
			catch (const InvalidInputFileException&) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown, L"Expected InvalidInputFileException to be thrown.");
		}
		TEST_METHOD(substringConsistsOfMultipleCharacters)
		{
			std::filesystem::path filePath = currentPath / "Test_readInputFile\\input_files\\substringConsistsOfMultipleCharacters.txt";

			CalcMinPrintingTimeParams exp_params = { 421, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };
			CalcMinPrintingTimeParams res_params = { };

			readInputFile(filePath.string(), &res_params);

			Assert::IsTrue(compareCalcMinPrintingParams(res_params, exp_params));
		}
	};
}
