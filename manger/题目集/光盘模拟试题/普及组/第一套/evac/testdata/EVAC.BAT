@echo off
if "%1"=="" goto loop
copy evac%1.in evac.in >nul
echo Problem Test
echo Data %1
time<enter
evac
time<enter
fc evac.out evac%1.out
del evac.in
del evac.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
