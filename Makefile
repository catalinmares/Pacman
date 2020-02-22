CC = gcc
CFLAGS = -Wall

SRC = pacman.c
EXE = pacman

build: $(EXE)

$(EXE): 
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE) *~
