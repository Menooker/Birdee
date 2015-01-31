set Path=c:\bin
"c:\GnuWin32\bin\bison.exe" --yacc -dv diksam.y
"c:\GnuWin32\bin\flex.exe" diksam.l
pause