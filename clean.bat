@ECHO OFF
SET _CONF_=Release
CALL "%~dp0build.bat" /t:Clean
SET _CONF_=Debug
CALL "%~dp0build.bat" /t:Clean