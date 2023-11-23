CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRCDIR = src
OBJDIR = build
BINDIR = build
EXECUTABLE = $(BINDIR)/tictactoe.exe

# Define the source files
SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/features/menu/*.c) $(wildcard $(SRCDIR)/features/menu/guide/*.c) $(wildcard $(SRCDIR)/features/game/*.c) $(wildcard $(SRCDIR)/features/game/board/*.c) $(wildcard $(SRCDIR)/features/game/computer/*.c) $(wildcard $(SRCDIR)/features/game/player/*.c) $(wildcard $(SRCDIR)/features/game/validators/*.c) $(wildcard $(SRCDIR)/features/shop/*.c) $(wildcard $(SRCDIR)/features/game/states/*.c)

# Define the object files
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Include dependency files
-include $(OBJ:.o=.d)

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(OBJDIR) $(BINDIR) $(OBJDIR)/features/menu $(OBJDIR)/features/menu/guide $(OBJDIR)/features/game/board $(OBJDIR)/features/game/computer $(OBJDIR)/features/game/player $(OBJDIR)/features/game/validators $(OBJDIR)/features/shop $(OBJDIR)/features/game/states

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJ) $(OBJ:.o=.d)
	rm -rf build/features


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<


.PHONY: all clean directories
