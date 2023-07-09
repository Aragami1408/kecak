@echo off

SetLocal EnabledDelayedExpansion
IF NOT EXIST bin mkdir bin
IF NOT EXIST bin\int mkdir bin\int

call vcvarsall.bat x64
SET cc=cl.exe

SET c_filenames=src\main.c src\base\base_math.c src\base\base_memory.c

if %cc% == cl.exe (
  SET compiler_flags=/Zc:preprocessor /wd4090 /wd5105
  SET include_flags=/I.\src\ 
  SET linker_flags=/link /DEBUG shell32.lib user32.lib winmm.lib userenv.lib gdi32.lib
  SET output=/Fe.\bin\codebase /Fo.\bin\int\
  SET defines=/D_DEBUG /D_CRT_SECURE_NO_WARNINGS 
)

if %cc% == clang (
  SET compiler_flags=-Wall -Wextra -Wpedantic -Wstrict-aliasing=3 -Wwrite-strings -Wvla -Wcast-align=strict -Wstrict-prototypes -Wstringop-overflow=4 -Wno-logical-op-parentheses -O0
  SET include_flags=-Isrc
  SET linker_flags=-g -lshell32 -luser32 -lwinmm -luserenv -lgdi32 
  SET output=-o bin/codebase.exe
  SET defines=-D_DEBUG -D_CRT_SECURE_NO_WARNINGS 
)

ECHO Building codebase.exe...
ECHO %cc% %compiler_flags% %c_filenames% %defines% %include_flags% %output% %linker_flags%
%cc% %compiler_flags% %c_filenames% %defines% %include_flags% %output% %linker_flags%

