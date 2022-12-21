@echo off

SETLOCAL EnableExtensions DisableDelayedExpansion

:: utf8
chcp 65001 > nul

set KW_ADDR=
set outputdir=
set KW_BUILD_PROCESS=1
set build_script=build_firmware.bat

set ProjectName=Klocwork_TestProject

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Check prerequisite tools
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

 REM Set up a local project and connect it to a server project with kwcheck create.
 ECHO ***************************************************
 ECHO Creating Project ...
 ECHO ***************************************************
 if not exist "%USERPROFILE%\klocwork_projects" mkdir %USERPROFILE%\klocwork_projects
 if not exist "%USERPROFILE%\klocwork_projects\%ProjectName%" mkdir %USERPROFILE%\klocwork_projects\%ProjectName%
 REM If directory already exist delete it
if exist .kwps\ (
  rmdir /S /Q .kwps
)

 REM If directory already exist delete it
if exist %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp\ (
  rmdir /S /Q %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp
)


 REM If directory already exist delete it
if exist %USERPROFILE%\klocwork_projects\%ProjectName%\.kwps\ (
  rmdir /S /Q %USERPROFILE%\klocwork_projects\%ProjectName%\.kwps
)

 ECHO Creating project in : %USERPROFILE%\klocwork_projects\%ProjectName%
 if %KW_ADDR%=="" (
	kwcheck create -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp -sd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwps
 ) else (
	kwcheck create --url %KW_ADDR%%ProjectName% -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp -sd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwps
 )
 IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
 )
 
 :CLEAN
 ECHO ***************************************************
 ECHO Cleaning config %ProjectName% ...
 ECHO ***************************************************
 CALL %build_script% clean
 IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
 )
 
 :COMPIL
 ECHO ***************************************************
 ECHO Compiling %ProjectName% ...
 ECHO ***************************************************
 (
  ECHO %build_script%
 )| kwshell -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp
 
 IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
 )
  
 ECHO exit
 
 ECHO ***************************************************
 ECHO Starting Analysis of %ProjectName% ...
 ECHO ***************************************************
  REM kwcheck sync --verbose -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp
  REM Analyze your code with kwcheck run
 kwcheck run -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp
 IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
 )
 ECHO exit
 
 ECHO ***************************************************
 ECHO Generation of result %ProjectName% ...
 ECHO ***************************************************
  REM Display detected issues with kwcheck list
  kwcheck list -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp -l --severity 1-3 -F detailed
  IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
  )
  kwcheck list -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp -l --severity 1-3 -F detailed
  IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
  )
  kwcheck list -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp -l --severity 1-3 -F detailed
  IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
  )
  kwcheck list -pd %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp -l --severity 1-3 -F detailed
  IF %ERRORLEVEL% NEQ 0 (
	pause
	exit 1
  )
  ECHO exit
 ECHO ***************************************************
 ECHO Openning Klocwork Desktop ...
 ECHO ***************************************************
 START /B kwgcheck --project-dir %USERPROFILE%\klocwork_projects\%ProjectName%\.kwlp

REM Delete temps file with .o extension
if exist *.o (
	del *.o /a
)
:: Fin du programme sélection 0

PAUSE
:FIN
exit /B 0