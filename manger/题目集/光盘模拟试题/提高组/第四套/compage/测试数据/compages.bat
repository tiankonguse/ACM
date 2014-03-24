@echo off
if "%1"=="" goto loop
copy compages%1.in compages.in >nul
echo Problem Test
echo Data %1
time<enter
compages
time<enter
fc compages.out compages%1.out
del compages.in
del compages.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
