@echo off
if "%1"=="" goto loop
echo Program Test
echo Case %1
copy bed%1.in bed1in>nul
bed1
fc bed%1.out bed.out
del bed.in
del bed.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end