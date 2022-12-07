@echo off
echo "Beggining compilation of example project on IAR 9.0"

pushd %~dp0
"C:\Program Files\IAR Systems\Embedded Workbench 9.0\common\bin\iarbuild.exe" ./arm/library.ewp -build Debug
popd