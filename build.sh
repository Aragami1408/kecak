if [ ! -d ./bin/linux ]; then
	mkdir -p bin/linux
fi

cc=gcc

c_filenames="src/main.c src/base/base_math.c src/base/base_memory.c"

compiler_flags="-Wall -Wextra -Wpedantic -Wstrict-aliasing=3 -Wwrite-strings -Wvla -Wcast-align=strict -Wstrict-prototypes -Wstringop-overflow=4 -Wno-logical-op-parentheses -Wno-missing-braces -O0 -std=c11"
include_flags="-Isrc"
linker_flags="-ggdb -lm"
defines="-DDEBUG -D_CRT_SECURE_NO_WARNINGS"
output="-o bin/linux/codebase"

echo Building codebase...
$cc $c_filenames $compiler_flags $defines $backend $include_flags $linker_flags $output

