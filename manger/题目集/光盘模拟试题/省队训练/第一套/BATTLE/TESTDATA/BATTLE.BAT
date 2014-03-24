@echo off
if "%1"=="" goto loop
copy battle%1.in battle.in >nul
echo Problem Test
echo Data %1
time<enter
battle
time<enter
fc battle.out battle%1.out
del battle.in
del battle.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
