@echo off
if "%1"=="" goto loop
copy int%1.in int.in >nul
echo Problem Test
echo Data %1
time<enter
int
time<enter
fc int.out int%1.out
del int.in
del int.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
