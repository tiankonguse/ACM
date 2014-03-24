@echo off
if "%1"=="" goto loop
echo Program Test
echo Case %1
copy well%1.in well.in>nul
time<enter
well
time<enter
fc well%1.out well.out
del well.in
del well.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end