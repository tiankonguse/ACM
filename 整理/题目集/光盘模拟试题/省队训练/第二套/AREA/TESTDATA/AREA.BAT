@echo off
if "%1"=="" goto loop
copy area%1.in area.in >nul
echo Problem Test
echo Data %1
time<enter
area
time<enter
fc area.out area%1.out
del area.in
del area.out
pause
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
