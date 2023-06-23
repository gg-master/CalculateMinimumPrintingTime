@echo off
chcp 1251 > nul 
setlocal enabledelayedexpansion
set program=CalculateMinimumPrintingTime.exe

echo. > results.txt
echo 1 - Áûñòðîïå÷àòàþùèå ïðèíòåðû. Ïåðâûé ÷àñòî ëîìàåòñÿ. Âòîðîé ðåäêî ëîìàåòñÿ. >> results.txt
echo. >> results.txt
%program% ./input1.txt ./output.txt >> results.txt 2>&1 
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input1.txt >> results.txt
echo. >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo. >> results.txt
echo. >> results.txt
echo 02 - Áûñòðîïå÷àòàþùèå ïðèíòåðû. Îáà ÷àñòî ëîìàþòñÿ. >> results.txt
echo. >> results.txt
%program% ./input2.txt ./output.txt >> results.txt 2>&1 
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input2.txt >> results.txt
echo. >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo. >> results.txt
echo. >> results.txt
echo 03 - Ïîâòîðíûé çàïóñê 2 òåñòà. Äåìîíñòðàöèÿ ðàíäîìà. >> results.txt
echo. >> results.txt
%program% ./input3.txt ./output.txt >> results.txt 2>&1 
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input3.txt >> results.txt
echo. >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo. >> results.txt
echo. >> results.txt
echo 04 - Íåâåðíûå âõîäíûå äàííûå: íåâåðíîå êîëè÷åñòâî ïàðàìåòðîâ.  >> results.txt
echo. >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input4_invalid_number_of_args.txt >> results.txt
echo. >> results.txt
echo ÂÛÂÎÄ ÎØÈÁÊÈ: >> results.txt
%program% ./input4_invalid_number_of_args.txt ./output.txt >> results.txt 2>&1 

echo. >> results.txt
echo. >> results.txt
echo 05 - Íåâåðíûå âõîäíûå äàííûå: íåâåðíûé òèï ïàðàìåòðîâ. >> results.txt
echo. >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input5_invalid_type_of_args.txt >> results.txt
echo. >> results.txt
echo ÂÛÂÎÄ ÎØÈÁÊÈ: >> results.txt
%program% ./input5_invalid_type_of_args.txt ./output.txt >> results.txt 2>&1 

echo. >> results.txt
echo. >> results.txt
echo 06 - Íåâåðíûå âõîäíûå äàííûå: Ïóñòîé ôàéë  >> results.txt
echo. >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input6_empty_file.txt >> results.txt
echo. >> results.txt
echo ÂÛÂÎÄ ÎØÈÁÊÈ: >> results.txt
%program% ./input6_empty_file.txt ./output.txt >> results.txt 2>&1 
