@echo off
if "%1"=="" goto loop
copy list%1.in list.in >nul
echo Problem Test
echo Data %1
time<enter
list
time<enter
check
del list.in
del list.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
