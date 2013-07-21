@echo	off
if /i	"%PROCESSOR_ARCHITECTURE%"=="x86" (
	start	"Waffle" %~dp0Component\Waffle\I386\Waffle.exe %*
	goto	eof
	)
if /i	"%PROCESSOR_ARCHITECTURE%"=="AMD64" (
	start	"Waffle" %~dp0Component\Waffle\AMD64\Waffle.exe %*
	goto	eof
	)
echo	Unsupported platform
pause
:eof