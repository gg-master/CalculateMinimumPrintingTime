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


// ��������� �� �������, ����������� ����������������� ��������
typedef bool (*isPrinterFunctionalPtr)(float);


/*! ��������� ����������������� ��������, ��������� ������.
* \param[in] failureProbability - ����������� ������ �������� �� �����.
* \return true, ���� ������� ��������, ����� false.
*/
bool isPrinterFunctionalByRandom(float failureProbability);


/*! ������������ ����������� ����� �� ������ ����� ���������� �� ���� ���������
	� ������ ������������ ������ ��������� �� �����.
* \param[in] params - ��������� ������, ������������ � ���������.
* \return ����������� ����� �� ������ ��������� ���������� ����� ����������.
*/
int calcMinPrintingTime(CalcMinPrintingTimeParams params, isPrinterFunctionalPtr isPrinterFunctional = isPrinterFunctionalByRandom);


/*! ������� ���������� �������� � ������, ����������� ��������� ��� ����������.
* \param[in] input_line - ������, � ������� ������������ ������� ��������.
* \return ���������� �������� � ������, ����������� ��������� ��� ����������.
*/
int countValuesInLine(const std::string& input_line);


/*! ����������� ������� ������ �� ����� � ��������� �� � ��������� CalcMinPrintingTimeParams.
* \param[in] input_file_path - ������ � ����� � ����� � �������� �������.
* \param[out] params - ��������� �������� ������, ������������ � ���� ���������.
*/
void readInputFile(const std::string& input_file_path, CalcMinPrintingTimeParams* params);


/*! ��������� �������������� �������� ���������� ���������.
* \param[in] value - ����������� ��������.
* \param[in] left_border - ����� ������� ���������.
* \param[in] right_border - ������ ������� ���������.
* \return true, ���� �������� ����������� ���������, ����� - false.
*/
bool isInRange(double value, double left_border, double right_border);


/*! �������� ��������� ������� ���������� �������� ������������.
	��� ������� ��������, ����������� ������ ���������.
* \param[in] params - ������������ ��������� ������, ������������ � ���������.
*/
void validateInputData(const CalcMinPrintingTimeParams params);
