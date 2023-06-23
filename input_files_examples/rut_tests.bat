@echo off
chcp 1251 > nul 
setlocal enabledelayedexpansion
set program=CalculateMinimumPrintingTime.exe

echo. > results.txt
echo 1 - ���������������� ��������. ������ ����� ��������. ������ ����� ��������. >> results.txt
echo. >> results.txt
%program% ./input1.txt ./output.txt >> results.txt 2>&1 
echo ������� ������: >> results.txt
type input1.txt >> results.txt
echo. >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo. >> results.txt
echo. >> results.txt
echo 02 - ���������������� ��������. ��� ����� ��������. >> results.txt
echo. >> results.txt
%program% ./input2.txt ./output.txt >> results.txt 2>&1 
echo ������� ������: >> results.txt
type input2.txt >> results.txt
echo. >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo. >> results.txt
echo. >> results.txt
echo 03 - ��������� ������ 2 �����. ������������ �������. >> results.txt
echo. >> results.txt
%program% ./input3.txt ./output.txt >> results.txt 2>&1 
echo ������� ������: >> results.txt
type input3.txt >> results.txt
echo. >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo. >> results.txt
echo. >> results.txt
echo 04 - �������� ������� ������: �������� ���������� ����������.  >> results.txt
echo. >> results.txt
echo ������� ������: >> results.txt
type input4_invalid_number_of_args.txt >> results.txt
echo. >> results.txt
echo ����� ������: >> results.txt
%program% ./input4_invalid_number_of_args.txt ./output.txt >> results.txt 2>&1 

echo. >> results.txt
echo. >> results.txt
echo 05 - �������� ������� ������: �������� ��� ����������. >> results.txt
echo. >> results.txt
echo ������� ������: >> results.txt
type input5_invalid_type_of_args.txt >> results.txt
echo. >> results.txt
echo ����� ������: >> results.txt
%program% ./input5_invalid_type_of_args.txt ./output.txt >> results.txt 2>&1 

echo. >> results.txt
echo. >> results.txt
echo 06 - �������� ������� ������: ������ ����  >> results.txt
echo. >> results.txt
echo ������� ������: >> results.txt
type input6_empty_file.txt >> results.txt
echo. >> results.txt
echo ����� ������: >> results.txt
%program% ./input6_empty_file.txt ./output.txt >> results.txt 2>&1 
