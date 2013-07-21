Set WShell = CreateObject("WScript.Shell")

PATH = Left(WScript.ScriptFullName,InStrRev(WScript.ScriptFullName,"\"))
WAFFLE_PORT_MACHINE_STRING = WShell.ExpandEnvironmentStrings("%PROCESSOR_ARCHITECTURE%")

Select	Case	WAFFLE_PORT_MACHINE_STRING
Case	"x86"
	WAFFLE = PATH & "Component\Waffle\I386\Waffle.exe"
Case	"AMD64"
	WAFFLE = PATH & "Component\Waffle\AMD64\Waffle.exe"
Case	Else
	MsgBox	"Unsupported platform"
	WScript.Quit
End	Select

'             ATTENTION
'!!!THIS IS NOT A PERFECT SOLUTION!!!
' Wscript.Arguments will ignore ALL
' the quotation marks, which makes
' some programs behavior differently
' and makes Waffle more detectable.
Argument = ""
For	Each	arg	In Wscript.Arguments
	Argument = Argument & " """ & arg & """"
Next

WShell.Run """" & WAFFLE & """ " & Argument
