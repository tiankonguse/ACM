@echo off
if "%1"=="" goto loop
copy loan%1.in loan.in >nul
echo Problem Test
echo Data %1
time<enter
loan
time<enter
fc loan.out loan%1.out
del loan.in
del loan.out
pause
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
