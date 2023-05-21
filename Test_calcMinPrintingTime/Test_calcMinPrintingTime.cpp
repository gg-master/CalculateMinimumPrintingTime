#include "pch.h"
#include "CppUnitTest.h"
#include "../CalculateMinimumPrintingTime/CalculateMinimumPrintingTime.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/* ��������� ��������������� ��������. �����������, �������� �� ������� �� �����.
* \param[in] unused_failureProbability - �������������� ����������� ������ �������� �� �����.
* \return tru�.
*/
bool isPrinterFunctionalAlways(float unused_failureProbability)
{
	return true;
}


float printers_probability[2]; // ������ � ������������� ���������, ��� �� �������� ���� �� �����
int breakdown_counters[2]; // �������� ������� ���������
int max_breakdowns; // ������������ ����� ������� ��������

/*  ��������� ��������������� ��������. ��������� ����������������� ����� �������, ��������� ��������.
* \param[in] failureProbability - ����������� ������ �������� �� �����, ������������ ��� �������� ���������.
* \return true, ���� ������� ��������, ����� false.
*/
bool isPrinterFunctionalExceptMaxBreakdownCount(float failureProbability)
{
	// ���� ��� �� ���������� ��� ��������
	if (printers_probability[0] == 0 && printers_probability[1] == 0)
	{
		// �������, ��� ������ ������� � ��������� ������������
		printers_probability[0] = failureProbability;
	}
	// ����� ���� �� ��������� ������ �������
	else if (printers_probability[1] == 0)
	{
		// �������, ��� ������ ������� � ��������� ������������
		printers_probability[1] = failureProbability;
	}
	// ���� ����������� ����� ����������� ������� ��������
	if (failureProbability == printers_probability[0])
	{
		// ���� ������� ������� �� ����� ������ ������������� ���������� ����� �������
		if (breakdown_counters[0] < max_breakdowns)
		{
			// �������, ��� ������� ��������
			breakdown_counters[0]++;
			return false;
		}
	}
	// ����� ���� ����������� ����� ����������� ������� ��������
	else if (failureProbability == printers_probability[1])
	{
		// ���� ������� ������� �� ����� ������ ������������� ���������� ����� �������
		if (breakdown_counters[1] < max_breakdowns)
		{
			// �������, ��� ������� ��������
			breakdown_counters[1]++;
			return false;
		}
	}
	// ������� ������, ����������, ��� ������� ��������
	return true;
}


namespace TestcalcMinPrintingTime
{
	TEST_CLASS(TestcalcMinPrintingTime)
	{
	public:
		TEST_METHOD(sampleTest)
		{
			CalcMinPrintingTimeParams input_params = { 4, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };

			int exp_time = 3;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalAlways);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(oneCopyIsRequired)
		{
			CalcMinPrintingTimeParams input_params = { 1, 1, 1, 1, 0.2, 3, 1, 0.6, 6 };

			int exp_time = 1;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalAlways);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(firstPrinterTimeMoreThanSecondPrinterTime)
		{
			CalcMinPrintingTimeParams input_params = { 4, 10, 5, 1, 0.2, 3, 1, 0.6, 6 };

			int exp_time = 15;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalAlways);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(firstPrinterTimeLessThanSecondPrinterTime)
		{
			CalcMinPrintingTimeParams input_params = { 4, 5, 10, 1, 0.2, 3, 1, 0.6, 6 };

			int exp_time = 15;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalAlways);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(uptimeLessThanPrintTime)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 1;

			CalcMinPrintingTimeParams input_params = { 4, 5, 5, 1, 0.2, 3, 1, 0.6, 6 };

			int exp_time = 18;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(uptimeMoreThanPrintTime)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 1;

			CalcMinPrintingTimeParams input_params = { 4, 5, 5, 8, 0.2, 3, 9, 0.6, 6 };

			int exp_time = 21;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(uptimeFirstLessThanSecond)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 1;

			CalcMinPrintingTimeParams input_params = { 4, 5, 5, 4, 0.2, 3, 9, 0.6, 6 };

			int exp_time = 15;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(repairTimeLessThanPrintTime)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 1;

			CalcMinPrintingTimeParams input_params = { 4, 5, 5, 1, 0.2, 3, 1, 0.6, 0 };

			int exp_time = 16;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(repairTimeEqualPrintTime)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 1;

			CalcMinPrintingTimeParams input_params = { 4, 5, 5, 1, 0.2, 5, 1, 0.6, 5 };

			int exp_time = 20;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(repairTimeMoreThanPrintTime)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 1;

			CalcMinPrintingTimeParams input_params = { 4, 5, 5, 1, 0.2, 7, 1, 0.6, 10 };

			int exp_time = 22;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(firstPrinterPrintTimeMoreThanSecondPrinterPrintTime)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 2;

			CalcMinPrintingTimeParams input_params = { 4, 10, 5, 1, 0.2, 3, 1, 0.6, 6 };

			int exp_time = 28;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
		TEST_METHOD(firstPrinterPrintTimeLessThanSecondPrinterPrintTime)
		{
			for (int i = 0; i < 2; i++) {
				printers_probability[i] = 0;
			}
			for (int i = 0; i < 2; i++) {
				breakdown_counters[i] = 0;
			}
			max_breakdowns = 2;

			CalcMinPrintingTimeParams input_params = { 4, 5, 10, 1, 0.2, 3, 1, 0.6, 6 };

			int exp_time = 27;
			int result_time = calcMinPrintingTime(input_params, isPrinterFunctionalExceptMaxBreakdownCount);
			Assert::AreEqual(exp_time, result_time);
		}
	};
}
