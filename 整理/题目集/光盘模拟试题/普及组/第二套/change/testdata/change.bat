@echo off
if "%1"=="" goto loop
copy change%1.in change.in >nul
echo Problem Test
echo Data %1
change
fc change.out change%1.out
del change.in
del change.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6) do call %0 %%i
:end
