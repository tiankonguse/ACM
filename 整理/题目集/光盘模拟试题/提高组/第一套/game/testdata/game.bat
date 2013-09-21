@echo off
if "%1"=="" goto loop
echo Game
echo Test%1
copy game%1.in game.in >nul
copy game%1.out game.std >nul
time <enter
game
time <enter
test
pause
del game.in
del game.std
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end