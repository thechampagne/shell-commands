@echo off
 
set /p cmd=Choose a command to compile : 

if not exist %cmd%\ (
	echo Command not exist
	echo.
	pause
	exit
)

cd %cmd%

gcc -o ../bin/%cmd% %cmd%.c