Function GetCommandLine()
    'This function is brought to you by Demon<http://demon.tw>. Thank you!
    'But I still need to modify some codes...

    Dim objServices, colItems, objItem
    Dim strExePath, strFullName, intPos
    
    strExePath = Replace(WScript.FullName, "\", "\\")
    strFullName = WScript.ScriptFullName
    Set objServices = GetObject("winmgmts:\\.\root\CIMV2")
    Set colItems = objServices.ExecQuery("SELECT CommandLine FROM Win32_Process WHERE ExecutablePath = '" & strExePath & "'")
    
    For Each objItem In colItems
        intPos = InStr(objItem.CommandLine, strFullName)
        If intPos > 0 Then
            GetCommandLine = Mid(objItem.CommandLine, intPos - 1)
            Exit For
        End If
    Next
End Function

Function CheckSystemVersion()
    'This function is based on the example script in http://msdn.microsoft.com/en-us/library/windows/desktop/aa394239.aspx

    ' Connect to WMI and obtain instances of Win32_OperatingSystem
    For Each objOS in GetObject("winmgmts:\\.\root\CIMV2").InstancesOf("Win32_OperatingSystem")
        CheckSystemVersion = 0
        For i = 1 to Len(objOS.Version)
            If Mid(objOS.Version, i, 1) = "." Then
                CheckSystemVersion = CheckSystemVersion * 10 + Mid(objOS.Version, i + 1, 1)
                Exit For
            End If
            CheckSystemVersion = CheckSystemVersion * 10 + Mid(objOS.Version, i, 1)
        Next
        If CheckSystemVersion < 51 Then
            MsgBox  "Waffle requires at least Windows XP. Please update your system."
            WScript.Quit
        End If
    Next
End Function

CheckSystemVersion

Set WShell = CreateObject("WScript.Shell")

PATH = Left(WScript.ScriptFullName, InStrRev(WScript.ScriptFullName, "\"))
WAFFLE_PORT_MACHINE_STRING = WShell.ExpandEnvironmentStrings("%PROCESSOR_ARCHITECTURE%")
COMMANDLINE = Mid(GetCommandLine(), Len(WScript.ScriptFullName) + 5)

Select  Case WAFFLE_PORT_MACHINE_STRING
Case    "x86"
    WAFFLE = PATH & "Component\Waffle\I386\Waffle.shell.1.0.dll"
Case    "AMD64"
    WAFFLE = PATH & "Component\Waffle\AMD64\Waffle.shell.1.0.dll"
Case    "ARM"
    WAFFLE = PATH & "Component\Waffle\ARMNT\Waffle.shell.1.0.dll"
Case    "IA64"
    WAFFLE = PATH & "Component\Waffle\IA64\Waffle.shell.1.0.dll"
Case    Else
    MsgBox "Unsupported platform"
    WScript.Quit
End     Select

TEXT = "Press Yes to install Waffle Shell Extension." & vbCrLf & "Press No to uninstall Waffle Shell Extension." & vbCrLf & "WE WILL RESTART YOUR WINDOWS EXPLORER!"
If MsgBox(TEXT, vbYesNo, "Waffle Shell Extension") = vbYes Then
    WShell.Run "regsvr32 /s """ & WAFFLE & """", 0, true
Else
    WShell.Run "regsvr32 /s /u """ & WAFFLE & """", 0, true
End If
WShell.Run "taskkill /f /im explorer.exe", 0, true
WShell.Run "explorer"
WShell.Run "explorer """ & PATH & """"