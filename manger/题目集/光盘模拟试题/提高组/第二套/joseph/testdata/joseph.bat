@echo off
if "%1"=="" goto loop
echo Joseph
echo Test%1
copy joseph%1.in joseph.in >nul
time <enter
joseph
time <enter
fc joseph%1.out joseph.out
del joseph.in
del joseph.out
pause
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end