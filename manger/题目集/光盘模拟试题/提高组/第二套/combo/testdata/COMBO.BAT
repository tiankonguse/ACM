@echo off
if "%1"=="" goto loop
copy combo%1.in combo.in >nul
echo Problem Test
echo Data %1
combo
fc combo.out combo%1.out
del combo.in
del combo.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7) do call %0 %%i
:end
