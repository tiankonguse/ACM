@echo off
if "%1"=="" goto loop
copy heaven%1.in heaven.in >nul
echo Problem Test
echo Data %1
heaven
fc heaven.out heaven%1.out
del heaven.in
del heaven.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
