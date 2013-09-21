@echo off
if "%1"=="" goto loop
copy num%1.in num.in >nul
echo Problem Test
echo Data %1
num
fc num.out num%1.out
del num.in
del num.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
