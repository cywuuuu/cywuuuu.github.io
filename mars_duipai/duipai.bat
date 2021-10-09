@echo off
set/p a=
gcc %a%.c -o std.exe
gcc rand.c -o rand.exe
:loop
rand.exe %random% > data.in
java -jar mars.jar nc me %a%.asm < data.in 1> a.out 2>err.txt
std.exe < data.in > b.out
::type data.in
fc a.out b.out >nul
if not errorlevel 1 goto loop
echo Input:
type data.in
echo std output:
type b.out
echo=
echo your output:
type a.out
echo=
pause