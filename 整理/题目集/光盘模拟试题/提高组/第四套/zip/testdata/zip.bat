@echo off
if "%1"=="" goto loop
copy zip%1.in zip.in >nul
echo Problem Test
echo Data %1
time<enter
zip
time<enter
fc zip.out zip%1.out
del zip.in
del zip.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 0) do call %0 %%i
:end
