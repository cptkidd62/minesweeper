CC = g++
CFLAGS = -Wall -g
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
SRCS = _main.cpp App.cpp Game.cpp Board.cpp Tile.cpp Number.cpp Bomb.cpp Empty.cpp
OBJS = $(SRCS:.c=.o)
MAIN = minesweeper

all: $(MAIN)

$(MAIN): $(OBJS) 
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

.c.o:	$(CC) $(CFLAGS) -c $<  -o $@
