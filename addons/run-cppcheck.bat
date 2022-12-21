@echo off

set OutputFolder=cppcheck_html

call %~dp0tools\find-tools.bat
if not defined CMD_CPPCHECK (
	echo cppcheck.exe was not found. so skip to run it.
	exit /b 0
)

:: Read Platform : cf https://mivilisnet.wordpress.com/2018/05/30/read-the-windows-platform-from-the-batch-file/
for /f "usebackq tokens=1,2 delims=,=- " %%i in (`wmic computersystem list full`) do @if %%i==SystemType set platform=%%j

echo ***********************************************
echo Running CPPCheck on %platform%
echo ***********************************************

set CPPCHECK_PLATFORM=
if "%platform%" == "Win32" (
	set CPPCHECK_PLATFORM=win32W
) else if "%platform%" == "x64" (
	set CPPCHECK_PLATFORM=win64
) else (
	@echo not supported platform
	pause
	exit /b 1
)

set CPPCHECK_OUT=cppcheck.xml

if exist "%CPPCHECK_OUT%" (
	del %CPPCHECK_OUT%
)

if exist %OutputFolder% rmdir /s /q %OutputFolder%

set CPPCHECK_PARAMS=
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% %~dp0
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --force
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --suppress=missingIncludeSystem
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --suppress=unmatchedSuppression
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --enable=all
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --xml
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --platform=%CPPCHECK_PLATFORM%
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --output-file=%CPPCHECK_OUT%
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% -j %NUMBER_OF_PROCESSORS%
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --check-config
set CPPCHECK_PARAMS=%CPPCHECK_PARAMS% --cppcheck-build-dir=b ../src

pushd %~dp0
set ERROR_RESULT=0
if exist "%CMD_CPPCHECK%" (
	@echo Process :
	@echo "%CMD_CPPCHECK%" %CPPCHECK_PARAMS%
	"%CMD_CPPCHECK%" %CPPCHECK_PARAMS% > NUL 2>&1 || set ERROR_RESULT=1
	@echo.
	@echo The log files are %CPPCHECK_LOG% and %CPPCHECK_OUT%
	
	python38 cppcheck-htmlreport.py --source-dir=. --title=CPPCheckReport --file=%CPPCHECK_OUT% --report-dir=%OutputFolder%
)
popd
pause
exit /b %ERROR_RESULT%