@echo off
if "%1"=="" goto loop
copy format%1.in format.in >nul
echo Problem Test
echo Data %1
time<enter
format
time<enter
fc format.out format%1.out
del format.in
del format.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
