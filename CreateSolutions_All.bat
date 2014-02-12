@echo off

set LUA_PATH=%CD%\?.lua;%LUA_PATH%

ECHO set TARGET=Win32

..\premake\Premake4 --file=AxToolkit-Premake.lua --platform=x32 vs2008

PAUSE