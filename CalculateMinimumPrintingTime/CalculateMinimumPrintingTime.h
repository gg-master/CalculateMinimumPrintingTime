#pragma once

struct CalcMinPrintingTimeParams
{
	int numOfSheets;
	int firstPrintingTime;
	int secondPrintingTime;

	int firstPrinterFailureRate;
	float firstPrinterFailureProbability;
	int firstPrinterRepairTime;

	int secondPrinterFailureRate;
	float secondPrinterFailureProbability;
	int secondPrinterRepairTime;
};

int calcMinPrintingTime(CalcMinPrintingTimeParams params);
