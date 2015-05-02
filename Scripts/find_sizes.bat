echo off
set PATH=%PATH%;C:\cygwin64\bin
getregions.exe ../obj/*.axf -s -o../obj/function_sizes.txt
sort /R ..\obj\function_sizes.txt /O ..\obj\sorted_function_sizes.txt
