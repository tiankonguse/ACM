@echo off
if "%1"=="" goto loop
copy express%1.in express.in >nul
echo Problem Test
echo Data %1
time<enter
express
time<enter
fc express.out express%1.out
del express.in
del express.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
