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


class InvalidValueException;

class InvalidInputFileException;


// ”казатель на функцию, провер€ющую работоспособность принтера
typedef bool (*isPrinterFunctionalPtr)(float);


/*! ѕровер€ет работоспособность принтера, использу€ рандом.
* \param[in] failureProbability - веро€тность выхода принтера из стро€.
* \return true, если принтер работает, иначе false.
*/
bool isPrinterFunctionalByRandom(float failureProbability);


/*! –ассчитывает минимальное врем€ на печать копий документов на двух принтерах
	с учетом веро€тностей выхода принтеров из стро€.
* \param[in] params - параметры задачи, объединенные в структуру.
* \return минимальное врем€ на печать заданного количества копий документов.
*/
int calcMinPrintingTime(CalcMinPrintingTimeParams params, isPrinterFunctionalPtr isPrinterFunctional = isPrinterFunctionalByRandom);


/*! ѕодсчет количества подстрок в строке, разделенных пробелами или табул€цией.
* \param[in] input_line - строка, в которой производитс€ подсчет подстрок.
* \return  оличество подстрок в строке, разделенных пробелами или табул€цией.
*/
int countValuesInLine(const std::string& input_line);


/*! ѕрочитывает входные данные из файла и сохран€ет их в структуру CalcMinPrintingTimeParams.
* \param[in] input_file_path - строка с путем к файлу с входными данными.
* \param[out] params - параметры решаемой задачи, объединенные в одну структуру.
*/
void readInputFile(const std::string& input_file_path, CalcMinPrintingTimeParams* params);


/*! ѕровер€ет принадлежность значени€ указанному диапазону.
* \param[in] value - провер€емое значение.
* \param[in] left_border - лева€ граница диапазона.
* \param[in] right_border - права€ граница диапазоне.
* \return true, если значение принадлежит диапазону, иначе - false.
*/
bool isInRange(double value, double left_border, double right_border);


/*! ѕроводит валидацию входных параметров согласно ограничен€ми.
	ѕри провале проверки, выбрасывает ошибку валидации.
* \param[in] params - валидируемые параметры задачи, объединенные в структуру.
*/
void validateInputData(const CalcMinPrintingTimeParams params);
