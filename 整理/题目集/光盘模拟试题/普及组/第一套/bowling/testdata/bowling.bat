@echo off
if "%1"=="" goto loop
copy bowling%1.in bowling.in >nul
echo Problem Test
echo Data %1
bowling
fc bowling.out bowling%1.out
del bowling.in
del bowling.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6) do call %0 %%i
:end
