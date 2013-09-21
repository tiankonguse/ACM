@echo off
if "%1"=="" goto loop
copy paste%1.in paste.in >nul
echo Problem Test
echo Data %1
time<enter
paste
time<enter
fc paste.out paste%1.out
del paste.in
del paste.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
