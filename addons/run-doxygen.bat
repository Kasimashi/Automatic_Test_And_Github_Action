call tools\find-tools.bat

if exist doxygen_out rmdir /s /q doxygen_out

pushd %~dp0doxygen-awesome-css
if "%CMD_DOXYGEN%" == "" (
	echo doxygen tools was not found
) else if exist "%CMD_DOXYGEN%" (
	"%CMD_DOXYGEN%" Doxyfile
) else (
	echo doxygen was not found
)

popd

pause
exit /b 0
