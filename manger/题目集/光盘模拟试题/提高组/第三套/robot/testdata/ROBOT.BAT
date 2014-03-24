@echo off
if "%1"=="" goto loop
copy robot%1.in robot.in >nul
echo Problem Test
echo Data %1
time<enter
robot
time<enter
fc robot.out robot%1.out
del robot.in
del robot.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
