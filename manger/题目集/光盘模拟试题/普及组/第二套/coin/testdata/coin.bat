@echo off
if "%1"=="" goto loop
copy coin%1.in coin.in >nul
echo Problem Test
echo Data %1
coin
fc coin.out coin%1.out
del coin.in
del coin.out
pause
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
