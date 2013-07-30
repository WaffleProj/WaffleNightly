Function GetCommandLine()
    'This function is bought you by Demon<http://demon.tw>. Thank you!
    'Should support Windows XP
    'http://msdn.microsoft.com/en-us/library/windows/desktop/aa394372.aspx
    'Command line used to start a specific process, if applicable. This property is new for Windows XP.
    Dim objServices, colItems, objItem
    Dim strExePath, strFullName, intPos
    
    strExePath = Replace(WScript.FullName, "\", "\\")
    strFullName = WScript.ScriptFullName
    Set objServices = GetObject("winmgmts:\\.\root\cimv2")
    Set colItems = objServices.ExecQuery("SELECT CommandLine FROM Win32_Process WHERE ExecutablePath = '" & strExePath & "'")
    
    For Each objItem In colItems
        intPos = InStr(1, objItem.CommandLine, strFullName, vbTextCompare)
        If intPos > 0 Then
            GetCommandLine = Mid(objItem.CommandLine, intPos - 1)
            Exit For
        End If
    Next
End Function

Set WShell = CreateObject("WScript.Shell")

PATH = Left(WScript.ScriptFullName, InStrRev(WScript.ScriptFullName, "\"))
WAFFLE_PORT_MACHINE_STRING = WShell.ExpandEnvironmentStrings("%PROCESSOR_ARCHITECTURE%")
COMMANDLINE = Mid(GetCommandLine(), Len(WScript.ScriptFullName) + 5)

Select  Case WAFFLE_PORT_MACHINE_STRING
Case    "x86"
    WAFFLE = PATH & "Component\Waffle\I386\Waffle.exe"
Case    "AMD64"
    WAFFLE = PATH & "Component\Waffle\AMD64\Waffle.exe"
Case    "ARM"
    WAFFLE = PATH & "Component\Waffle\ARMNT\Waffle.exe"
Case    Else
    MsgBox "Unsupported platform"
    WScript.Quit
End     Select

WShell.Run """" & WAFFLE & """ " & COMMANDLINE
