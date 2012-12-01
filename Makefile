CC=g++
CFLAGS=-W -Wall -ansi -pedantic -Iinclude -O3
LDFLAGS=
EXEC=VC
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

VC: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f src/*.o

mrproper: clean
	rm -f $(EXEC)
