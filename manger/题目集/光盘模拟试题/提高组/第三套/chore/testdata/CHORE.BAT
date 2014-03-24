@echo off
if "%1"=="" goto loop
copy chore%1.in chore.in >nul
echo Problem Test
echo Data %1
time<enter
chore
time<enter
fc chore.out chore%1.out
del chore.in
del chore.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
