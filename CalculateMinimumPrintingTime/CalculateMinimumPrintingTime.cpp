#include <iostream>
#include "CalculateMinimumPrintingTime.h"


using namespace std;


int calcMinPrintingTime(CalcMinPrintingTimeParams params)
{
	if (params.firstPrintingTime > params.secondPrintingTime)
	{
		swap(params.firstPrintingTime, params.secondPrintingTime);
		swap(params.firstPrinterFailureRate, params.secondPrinterFailureRate);
		swap(params.firstPrinterFailureProbability, params.secondPrinterFailureProbability);
		swap(params.firstPrinterRepairTime, params.secondPrinterRepairTime);
	}

	int minimumPrintingTime = 0;

	params.numOfSheets = params.numOfSheets - 1;
	minimumPrintingTime += params.firstPrintingTime;

	int firstPrintingTimer = 0, secondPrintintTimer = 0;

	int firstPrintrerStableOpTime = minimumPrintingTime;
	int secondPrintrerStableOpTime = 0;

	if (firstPrintrerStableOpTime >= params.firstPrinterFailureRate)
	{
		if ((float)rand() / RAND_MAX <= params.firstPrinterFailureProbability)
			firstPrintingTimer = firstPrintrerStableOpTime = -params.firstPrinterRepairTime;

		else firstPrintrerStableOpTime = 0;
	}

	while (params.numOfSheets > 0)
	{
		minimumPrintingTime++; firstPrintingTimer++; secondPrintintTimer++;
		firstPrintrerStableOpTime++; secondPrintrerStableOpTime++;

		if (firstPrintrerStableOpTime >= params.firstPrinterFailureRate)
		{
			if ((float)rand() / RAND_MAX <= params.firstPrinterFailureProbability)
				firstPrintingTimer = firstPrintrerStableOpTime = -params.firstPrinterRepairTime;
			else firstPrintrerStableOpTime = 0;
		}
		if (secondPrintrerStableOpTime >= params.secondPrinterFailureRate)
		{
			if ((float)rand() / RAND_MAX <= params.secondPrinterFailureProbability)
				secondPrintintTimer = secondPrintrerStableOpTime = -params.secondPrinterRepairTime;
			else  secondPrintrerStableOpTime = 0;
		}
		if (firstPrintingTimer == params.firstPrintingTime)
		{
			params.numOfSheets--;
			firstPrintingTimer = 0;
		}
		if (secondPrintintTimer == params.secondPrintingTime)
		{
			params.numOfSheets--;
			secondPrintintTimer = 0;
		}
	}
	return minimumPrintingTime;
}

int main()
{
	int N, X, Y, L1, L2, K1, K2;
	float P1 = 0.2, P2 = 0.1;

	std::cin >> N >> X >> Y >> L1 >> L2 >> K1 >> K2;
	CalcMinPrintingTimeParams params = { N, X, Y, L1, P1, K1, L2, P2, K2 };
	cout << calcMinPrintingTime(params);
}
