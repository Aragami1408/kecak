if [ ! -d ./bin ]; then
	mkdir bin
fi

cc=gcc

c_filenames=
for entry in ./src/*.c
do
	c_filenames="$c_filenames $entry"
done

for entry in ./src/base/*.c
do
	c_filenames="$c_filenames $entry"
done

compiler_flags="-Wall -Wextra -Wpedantic -Wstrict-aliasing=3 -Wwrite-strings -Wvla -Wcast-align=strict -Wstrict-prototypes -Wstringop-overflow=4 -Wno-logical-op-parentheses -O0"
include_flags="-Isrc"
linker_flags="-ggdb -lm -lX11"
defines="-DDEBUG -D_CRT_SECURE_NO_WARNINGS"
output="-o bin/codebase"

echo Building codebase...
$cc $c_filenames $compiler_flags $defines $backend $include_flags $linker_flags $output

