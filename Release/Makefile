CC=gcc
CFLAGS=-I.
DEPS = MM.h
OBJ = game.o zxscumm.o ObjectScripts.o RoomScripts.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o game
