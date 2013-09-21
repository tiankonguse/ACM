@echo off
if "%1"=="" goto loop
copy gene%1.in gene.in >nul
echo Problem Test
echo Data %1
time<enter
gene
time<enter
fc gene.out gene%1.out
del gene.in
del gene.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
