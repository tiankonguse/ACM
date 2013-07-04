@echo off
if "%1"=="" goto loop
copy lines%1.in lines.in >nul
echo Problem Test
echo Data %1
time<enter
lines
time<enter
fc lines.out lines%1.out
del lines.in
del lines.out
pause
goto end
:loop
for %%i in (1 2 3 4) do call %0 %%i
:end
