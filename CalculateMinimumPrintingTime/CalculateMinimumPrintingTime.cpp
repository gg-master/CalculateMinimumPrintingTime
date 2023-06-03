#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include "CalculateMinimumPrintingTime.h"


using namespace std;


bool isPrinterFunctionalByRandom(float failureProbability)
{
	return (float)rand() / RAND_MAX > failureProbability;
}


int calcMinPrintingTime(CalcMinPrintingTimeParams params, isPrinterFunctionalPtr isPrinterFunctional)
{
	// Самый быстрый принтер считаем первым
	if (params.firstPrintingTime > params.secondPrintingTime)
	{
		swap(params.firstPrintingTime, params.secondPrintingTime);
		swap(params.firstPrinterUptime, params.secondPrinterUptime);
		swap(params.firstPrinterFailureProbability, params.secondPrinterFailureProbability);
		swap(params.firstPrinterRepairTime, params.secondPrinterRepairTime);
	}

	int minimumPrintingTime = 0;

	// Печатаем первую страницу на самом быстром принтере
	params.numOfSheets = params.numOfSheets - 1;
	minimumPrintingTime += params.firstPrintingTime;

	// Определяем таймеры времени для отсчета на печать 1 страницы
	int firstPrintingTimer = 0, secondPrintintTimer = 0;

	// Определяем общее время безотказной работы принтеров
	int firstPrintrerStableOpTime = minimumPrintingTime;
	int secondPrintrerStableOpTime = 0;

	// Если время стабильной работы больше, чем время безотказной работы, то проверяем, сломался ли принтер
	if (firstPrintrerStableOpTime >= params.firstPrinterUptime)
	{
		// Если принтер сломан, то сбрасываем таймер печати и общее время безотказной работы, 
		// на время, требующееся на восстановление работы принтера 
		if (!isPrinterFunctional(params.firstPrinterFailureProbability))
			firstPrintingTimer = firstPrintrerStableOpTime = -params.firstPrinterRepairTime;

		// Если принтер не сломан, то сбрасываем время безотказной работы, 
		// чтобы проверять поломки периодически
		else firstPrintrerStableOpTime = 0;
	}

	// Пока не распечатали все страницы
	while (params.numOfSheets > 0)
	{
		minimumPrintingTime++; firstPrintingTimer++; secondPrintintTimer++;
		firstPrintrerStableOpTime++; secondPrintrerStableOpTime++;

		// Проевряем работоспособность принтеров, после каждой секунды печати
		if (firstPrintrerStableOpTime >= params.firstPrinterUptime)
		{
			if (!isPrinterFunctional(params.firstPrinterFailureProbability))
				firstPrintingTimer = firstPrintrerStableOpTime = -params.firstPrinterRepairTime;
			else firstPrintrerStableOpTime = 0;
		}
		if (secondPrintrerStableOpTime >= params.secondPrinterUptime)
		{
			if (!isPrinterFunctional(params.secondPrinterFailureProbability))
				secondPrintintTimer = secondPrintrerStableOpTime = -params.secondPrinterRepairTime;
			else  secondPrintrerStableOpTime = 0;
		}

		// Если прошло нужное время на печать одной страницы, то считаем, что страницу распечатали
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

	// Считать, что количество подстрок в строке равно нулю
	int count = 0;

	// Пока возможно разбить строку по пробелу
	while (iss.good()) {
		std::string value;
		iss >> value; // Считать подстроку

		// Если подстрока непустая, то инкрементировать количество подстрок в строке
		if (!value.empty()) ++count; 
	}

	// Вернуть количество подстрок в строке
	return count;
}


void readInputFile(const std::string& input_file_path, CalcMinPrintingTimeParams* params)
{
	// Открыть файл (автоматически закроется после выполнения функции)
	std::ifstream input_file(input_file_path);

	string input_line;
	// Прочитать первую строку файла
	if (std::getline(input_file, input_line)) {
		std::istringstream iss(input_line);

		// Разделить строку на 9 параметров и обновить параметр params
		iss >> params->numOfSheets
			>> params->firstPrintingTime
			>> params->secondPrintingTime
			>> params->firstPrinterUptime
			>> params->firstPrinterFailureProbability
			>> params->firstPrinterRepairTime
			>> params->secondPrinterUptime
			>> params->secondPrinterFailureProbability
			>> params->secondPrinterRepairTime;

		if (countValuesInLine(input_line) != 9) // количество параметров в строке не равно 9
		{
			// Ошибка чтения файла
			throw InvalidInputFileException("Во входной строке неверное количество параметров. "
				"Убедитесь, что введены 9 параметров, разделенных пробелами, в одной строке.\n");
		}
		if (iss.fail()) // обнаружено несоответствие типов
		{
			// Ошибка чтения файла
			throw InvalidInputFileException("Во входной строке один из параметров имеет неправильный формат. "
				"Убедитесь, что были введены 9 параметров в числовом формате, разделенных пробелами, в одной строке.\n");
		}
	}
	// Если прочитать не удалось
	else {
		// Ошибка файла
		throw InvalidInputFileException("Во входной строке неверное количество параметров. "
			"Убедитесь, что введены 9 параметров, разделенных пробелами, в одной строке.\n");
	}
}


bool isInRange(double value, double left_border, double right_border)
{
	return left_border <= value && value <= right_border;
}


void validateInputData(const CalcMinPrintingTimeParams& params)
{
	if (!isInRange(params.numOfSheets, 1, 2 * pow(10, 8)))
		throw InvalidValueException("Параметр N не принадлежит диапазону [1..2*(10)^8].\n");

	if (!isInRange(params.firstPrintingTime, 1, 10))
		throw InvalidValueException("Параметр X не принадлежит диапазону [1..10].\n");

	if (!isInRange(params.secondPrintingTime, 1, 10))
		throw InvalidValueException("Параметр Y не принадлежит диапазону [1..10].\n");

	if (!isInRange(params.firstPrinterUptime, 1, 10))
		throw InvalidValueException("Параметр L1 не принадлежит диапазону [1..10].\n");

	if (!isInRange(params.secondPrinterUptime, 1, 10))
		throw InvalidValueException("Параметр L2 не принадлежит диапазону [1..10].\n");

	if (!isInRange(params.firstPrinterFailureProbability, 0.01, 0.99))
		throw InvalidValueException("Параметр P1 не принадлежит диапазону [0.01..0.99].\n");

	if (!isInRange(params.secondPrinterFailureProbability, 0.01, 0.99))
		throw InvalidValueException("Параметр P2 не принадлежит диапазону [0.01..0.99].\n");

	if (!isInRange(params.firstPrinterRepairTime, 0, 10))
		throw InvalidValueException("Параметр K1 не принадлежит диапазону [0..10].\n");

	if (!isInRange(params.secondPrinterRepairTime, 0, 10))
		throw InvalidValueException("Параметр K2 не принадлежит диапазону [0..10].\n");
}


int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	// Если указано неверное количество аргементов командной строки
	if (argc != 3)
	{
		std::cerr << "Неправильно указаны параметры запуска. "
			"Убедитесь, что параметры соотвествуют шаблону: \n"
			<< argv[0] << " <path/to/input_file> <path/to/save_file>\n";
		return 1;
	}

	std::ifstream input_file(argv[1]);

	// Если не удалось открыть файл с входными данными
	if (!input_file.is_open()) {
		std::cerr << "Неверно указан файл с входными данными. Возможно, файл не существует." << argv[1] << '\n';
		return 1;
	}

	filesystem::path output_path = filesystem::path(argv[2]);

	// Если не удалось определить путь для выходного файла
	if (!(filesystem::exists(output_path.parent_path()) &&
		filesystem::is_directory(output_path.parent_path()) &&
		output_path.has_filename()))
	{
		std::cerr << "Неверно указан файл для выходных данных. "
			"Возможно указанного расположения не существует или нет прав на запись." << '\n';
		return 1;
	}

	std::ofstream output_file(output_path);

	// Если не удалось открыть файл для записи выходных данных
	if (!output_file.is_open()) {
		std::cerr << "Неверно указан файл для выходных данных. "
			"Возможно указанного расположения не существует или нет прав на запись." << '\n';
		return 1;
	}

	CalcMinPrintingTimeParams params = {};

	try {
		// Считываем и валидируем входные параметры для задачи
		readInputFile(argv[1], &params);
		validateInputData(params);
	}
	catch (const InvalidValueException& e) {
		std::cerr << e.what();
		return 1;
	}
	catch (const InvalidInputFileException& e) {
		std::cerr << e.what();
		return 1;
	}

	// Записываем рассчитанное минимальное время печати
	output_file << calcMinPrintingTime(params) << '\n';

	// Закрываем входной и выходной файлы
	input_file.close();
	output_file.close();

	return 0;
}
