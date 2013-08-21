@echo	off

::VS2013
call	"%VS120COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_arm > NUL

if	"%VisualStudioVersion%" == "" (
	echo	You should run this script under Visual Studio ARM cross tools command prompt.
	pause
	goto	eof
	)

echo	This script uses "dll2lib" made by Peter Nelson
echo	See more informations at https://github.com/peterdn/dll2lib

call	:dll2lib kernel32
call	:dll2lib gdi32
call	:dll2lib comdlg32

pause
goto	eof
:dll2lib
copy	%WINDIR%\System32\%1.dll
..\..\Tool\dll2lib	%1.dll > NUL
del	%1.dll
goto	eof
:eof