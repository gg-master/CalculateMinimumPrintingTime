﻿#include <iostream>
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


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 3)
	{
		std::cerr << "Неправильно указаны параметры запуска. "
			"Убедитесь, что параметры соотвествуют шаблону: \n"
			<< argv[0] << " <path/to/input_file> <path/to/save_file>\n";
		return 1;
	}

	std::ifstream input_file(argv[1]);

	if (!input_file.is_open()) {
		std::cerr << "Неверно указан файл с входными данными. Возможно, файл не существует." << argv[1] << '\n';
		return 1;
	}

	filesystem::path output_path = filesystem::path(argv[2]);

	if (!(filesystem::exists(output_path.parent_path()) &&
		filesystem::is_directory(output_path.parent_path()) &&
		output_path.has_filename()))
	{
		std::cerr << "Неверно указан файл для выходных данных. "
			"Возможно указанного расположения не существует или нет прав на запись." << '\n';
		return 1;
	}
	std::ofstream output_file(output_path);

	if (!output_file.is_open()) {
		std::cerr << "Неверно указан файл для выходных данных. "
			"Возможно указанного расположения не существует или нет прав на запись." << '\n';
		return 1;
	}

	CalcMinPrintingTimeParams params = {};

	try {
		readInputFile(argv[1], &params);
	}
	catch (const InvalidInputFileException& e) {
		std::cerr << e.what();
		return 1;
	}

	std::cout << calcMinPrintingTime(params) << '\n';

	// Закрыть файлы
	input_file.close();
	output_file.close();

	return 0;
}
