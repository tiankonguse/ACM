@echo off
if "%1"=="" goto loop
copy Buylow%1.in Buylow.in >nul
echo Problem Test
echo D
time<enterata %1
Buylow
time<enter
fc Buylow.out Buylow%1.out
del Buylow.in
del Buylow.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
