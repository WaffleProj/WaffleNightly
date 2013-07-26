@echo off
pushd	%~dp0
call	Kill.cmd

cd	..
cd	..

cd	Waffle
call	Build_Waffle.cmd
call	Build_Waffle.cmd AMD64
cd	..

cd	Mojibake
call	Build_Mojibake.cmd
call	Build_Mojibake.cmd AMD64
cd	..

popd
pause