@echo off
if "%1"=="" goto loop
copy power%1.in power.in >nul
echo Problem Test
echo Data %1
time<enter
power
time<enter
fc power.out power%1.out
del power.in
del power.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
