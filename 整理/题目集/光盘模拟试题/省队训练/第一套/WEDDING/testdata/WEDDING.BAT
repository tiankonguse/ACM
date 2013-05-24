@echo off
if "%1"=="" goto loop
copy wedding%1.in wedding.in >nul
echo Problem Test
echo Data %1
time<enter
wedding
time<enter
copy wedding%.out wedding.ans >nul
check
del wedding.in
del wedding.out
del wedding.ans
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
