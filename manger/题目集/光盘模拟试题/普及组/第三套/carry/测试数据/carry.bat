@echo off
if "%1"=="" goto loop
copy carry%1.in carry.in >nul
echo Problem Test
echo Data %1
time<enter
carry
time<enter
fc carry.out carry%1.out
del carry.in
del carry.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
