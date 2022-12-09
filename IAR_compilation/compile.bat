@echo off
echo "Beggining compilation of example project on IAR 9.0"

set IAR_BUILD="C:\Program Files\IAR Systems\Embedded Workbench 9.0\common\bin\iarbuild.exe"

set COMPILE_PARAMS=
set COMPILE_PARAMS=%COMPILE_PARAMS% ./arm/library.ewp
set COMPILE_PARAMS=%COMPILE_PARAMS% -build Debug
set COMPILE_PARAMS=%COMPILE_PARAMS% -parallel %NUMBER_OF_PROCESSORS%

set Warning_Pattern="Warning"
set Error_Pattern="Error"

set compile_output_file=compile_output_file.txt
set warning_output_file=compile_warning_file.txt
set error_output_file=compile_error_file.txt

:: Change execution script from current directory (where this script is)
pushd %~dp0

echo Processing %IAR_BUILD% %COMPILE_PARAMS% ...
%IAR_BUILD% %COMPILE_PARAMS% > %compile_output_file% & type %compile_output_file%

IF %ERRORLEVEL% NEQ 0 (
	Echo Error happenned in compilation
	set RETURN=1
)
IF %ERRORLEVEL% EQU 0 (
	Echo Compilation ended with success
	set RETURN=0
)


:: Parse compilation output in order to find Warning and Error Pattern save it in error and warning files
type %compile_output_file% | findstr /c:%Warning_Pattern%  > %warning_output_file%
type %compile_output_file% | findstr /c:%Error_Pattern%  > %error_output_file%

:: Change execution script from previous directory
popd


pause
exit /b %RETURN%
