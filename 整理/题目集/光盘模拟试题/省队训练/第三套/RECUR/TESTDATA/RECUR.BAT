@echo off
if "%1"=="" goto loop
copy recur%1.in recur.in >nul
echo Problem Test
echo Data %1
time<enter
recur
time<enter
fc recur.out recur%1.out
del recur.in
del recur.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
