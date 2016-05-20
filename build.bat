@ECHO OFF

IF "%_PROJ_%"=="" SET _PROJ_="WoT_Launcher.sln"
IF "%_CONF_%"=="" SET _CONF_=Release

:: Set here version of VS
IF "%_VS_VER%"=="" SET _VS_VER=12.0

CALL :GetPathToVisualStudio %_VS_VER%
ECHO Path to VS: %_PATH_TO_VS%

SET _ENV_BAT_="%_PATH_TO_VS%..\..\VC\vcvarsall.bat"

ECHO CALL %_ENV_BAT_% 
CALL %_ENV_BAT_% 

:: msbuild %_PROJ_% /property:Configuration=Hybrid /maxcpucount:1
msbuild %_PROJ_% /property:Configuration=%_CONF_% /m /flp:logfile=%_PROJ_%.build.log %*

GOTO END

:GetPathToVisualStudio
CALL :GetPathToVisualStudioHelper HKLM\SOFTWARE\Microsoft\VisualStudio %1 > NUL 2>&1
IF ERRORLEVEL 1 CALL :GetPathToVisualStudioHelper HKLM\SOFTWARE\Wow6432Node\Microsoft\VisualStudio %1 > NUL 2>&1
EXIT /B 0

:GetPathToVisualStudioHelper
FOR /F "tokens=1,2*" %%i IN ('reg query "%1\%2" /v "InstallDir"') DO (
        if "%%i"=="InstallDir" (
                SET "_PATH_TO_VS=%%k"
        )
)
IF "%_PATH_TO_VS%"=="" EXIT /B 1
EXIT /B 0
  
:END