$CC="g++"
$FLAGS="-Wall -g"

build: lib/*.o src/main.o

all: build
