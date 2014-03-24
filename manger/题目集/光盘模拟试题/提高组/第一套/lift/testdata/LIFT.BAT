@echo off
if "%1"=="" goto loop
copy lift%1.in lift.in >nul
echo Problem Test
echo Data %1
time<enter
lift
time<enter
fc lift.out lift%1.out
del lift.in
del lift.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
