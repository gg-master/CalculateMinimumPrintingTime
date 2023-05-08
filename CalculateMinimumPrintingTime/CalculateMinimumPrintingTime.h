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


int countValuesInLine(const std::string& input_line);


void readInputFile(const std::string& input_file_path, CalcMinPrintingTimeParams* params);


bool isInRange(double value, double left_border, double right_border);


void validateInputData(const CalcMinPrintingTimeParams params);
