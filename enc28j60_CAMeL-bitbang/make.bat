@echo off

if NOT DEFINED NO_PAUSE (
	SET NO_PAUSE=1
	SET PAUSE_AT_END=1
)


REM call_msys_batch.bat startet msys und ruft make auf der make.msys_bat im aktuellen Verzeichnis auf
call ..\..\..\..\..\call_msys_batch.bat


if DEFINED PAUSE_AT_END (
	pause
)