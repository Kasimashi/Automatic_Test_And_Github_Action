call tools\find-tools.bat

if exist html rmdir /s /q html

if "%CMD_DOXYGEN%" == "" (
	echo doxygen was not found
) else if exist "%CMD_DOXYGEN%" (
	"%CMD_DOXYGEN%" doxygen.conf
) else (
	echo doxygen was not found
)

pause
exit /b 0
