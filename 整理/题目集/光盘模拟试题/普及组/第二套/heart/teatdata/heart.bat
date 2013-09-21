@echo off
if "%1"=="" goto loop
copy heart%1.in heart.in >nul
echo Problem Test
echo Data %1
heart
fc heart.out heart%1.out
del heart.in
del heart.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
