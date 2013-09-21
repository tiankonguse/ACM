@echo off
if "%1"=="" goto loop
copy fact%1.in fact.in >nul
echo Problem Test
echo Data %1
fact
fc fact.out fact%1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7) do call %0 %%i
:end
