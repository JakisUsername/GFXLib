@echo off

cmake --build out --config debug
gdb out\App.exe
exit 0
