@echo off
if "%1"=="" goto loop
copy marica%1.in marica.in >nul
echo Problem Test
echo Data %1
time<enter
marica
time<enter
fc marica.out marica%1.out
del marica.in
del marica.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
