@echo off
if "%1"=="" goto loop
copy polygon%1.in polygon.in >nul
echo Problem Test
echo Data %1
time<enter
polygon
time<enter
fc polygon.out polygon%1.out
del polygon.in
del polygon.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
