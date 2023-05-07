#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include "CalculateMinimumPrintingTime.h"


using namespace std;


class InvalidInputFileException : public std::exception {
public:
	InvalidInputFileException(const std::string& message) : m_message(message) {}

	const char* what() const noexcept override {
		return m_message.c_str();
	}
private:
	std::string m_message;
};


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


int countValuesInLine(const std::string& input_line) {
	std::istringstream iss(input_line);
	int count = 0;
	while (iss.good()) {
		std::string value;
		iss >> value;
		if (!value.empty()) ++count;
	}
	return count;
}


void readInputFile(const std::string& input_file_path, CalcMinPrintingTimeParams* params)
{
	std::ifstream input_file(input_file_path);

	string input_line;
	if (std::getline(input_file, input_line)) {
		std::istringstream iss(input_line);

		iss >> params->numOfSheets
			>> params->firstPrintingTime
			>> params->secondPrintingTime
			>> params->firstPrinterFailureRate
			>> params->firstPrinterFailureProbability
			>> params->firstPrinterRepairTime
			>> params->secondPrinterFailureRate
			>> params->secondPrinterFailureProbability
			>> params->secondPrinterRepairTime;

		if (countValuesInLine(input_line) != 9)
		{
			// Ошибка чтения параметров
			throw InvalidInputFileException("Во входной строке неверное количество параметров. "
				"Убедитесь, что введены 9 параметров, разделенных пробелами, в одной строке.\n");
		}
		if (iss.fail())
		{
			throw InvalidInputFileException("Во входной строке один из параметров имеет неправильный формат. "
				"Убедитесь, что были введены 9 параметров в числовом формате, разделенных пробелами, в одной строке.\n");
		}
	}
	else {
		// Ошибка чтения строки из файла
		throw InvalidInputFileException("Во входной строке неверное количество параметров. "
			"Убедитесь, что введены 9 параметров, разделенных пробелами, в одной строке.\n");
	}
}


int main()
{
	int N, X, Y, L1, L2, K1, K2;
	float P1 = 0.2, P2 = 0.1;

	std::cin >> N >> X >> Y >> L1 >> L2 >> K1 >> K2;
	CalcMinPrintingTimeParams params = { N, X, Y, L1, P1, K1, L2, P2, K2 };
	cout << calcMinPrintingTime(params);
}
