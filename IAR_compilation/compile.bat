@echo off
echo "Beggining compilation of example project on IAR 9.0"

set cmd="C:\Program Files\IAR Systems\Embedded Workbench 9.0\common\bin\iarbuild.exe" ./arm/library.ewp -build Debug -output compilationn.txt
set Warning_Pattern="Warning"
pushd %~dp0
%cmd%
IF %ERRORLEVEL% NEQ 0 (
	Echo Error happenned in compilation
	set ERROR_RESULT=1
)
IF %ERRORLEVEL% EQU 0 (
	Echo Compilation ended with success
	set ERROR_RESULT=0
)

echo %cmd%

type compilation.txt | findstr /c:%Warning_Pattern%  > warning.txt
popd

pause
exit /b %ERROR_RESULT%
