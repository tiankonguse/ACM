@echo off
if "%1"=="" goto loop
copy search%1.in search.in >nul
echo Problem Test
echo Data %1
time<enter
search
time<enter
fc search.out search%1.out
del search.in
del search.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
