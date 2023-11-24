TARGET = cw
CC = gcc

CORE = ./core/
HEADER = ./header/
BIN = ./bin/

CFLAGS = -Wall -std=gnu99 -I$(HEADER)

SRC = $(wildcard $(CORE)*.c)
OBJ = $(patsubst $(CORE)%.c, $(BIN)%.o, $(SRC))

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN)%.o : $(CORE)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET) $(BIN)*.o