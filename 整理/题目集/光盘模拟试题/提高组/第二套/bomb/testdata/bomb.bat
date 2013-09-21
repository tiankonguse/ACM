@echo off
if "%1"=="" goto loop
echo Bomb
echo Test%1
copy bomb%1.in bomb.in >nul
time <enter
bomb
time <enter
fc bomb%1.out bomb.out
pause
del bomb.in
del bomb.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end