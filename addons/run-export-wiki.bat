set output_dir=%~dp0Automatic_Test_And_Github_Action.wiki
set wiki_dir=%~dp0wiki_html

if exist %output_dir% rmdir /s /q %output_dir%

git clone git@github.com:Kasimashi/Automatic_Test_And_Github_Action.wiki.git

pushd %output_dir%
call export_wiki.bat
popd


if exist %wiki_dir% rmdir /s /q %wiki_dir%

if not exist %wiki_dir% mkdir %wiki_dir%

xcopy /s %output_dir%\worddocs %wiki_dir%

if exist %output_dir% rmdir /s /q %output_dir%

pause
exit /b 0
