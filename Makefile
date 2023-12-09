CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lwinmm
SRCDIR = src
OBJDIR = build
BINDIR = build
EXECUTABLE = $(BINDIR)/tictactoe.exe

# Define the source files
SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/features/cover/*.c) $(wildcard $(SRCDIR)/features/menu/*.c) $(wildcard $(SRCDIR)/features/guide/*.c) $(wildcard $(SRCDIR)/features/game/*.c) $(wildcard $(SRCDIR)/features/game/board/*.c) $(wildcard $(SRCDIR)/features/game/computer/*.c) $(wildcard $(SRCDIR)/features/game/player/*.c) $(wildcard $(SRCDIR)/features/game/validators/*.c) $(wildcard $(SRCDIR)/features/shop/*.c) $(wildcard $(SRCDIR)/features/game/states/*.c) $(wildcard $(SRCDIR)/features/setting/*.c)

# Define the object files
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Include dependency files
-include $(OBJ:.o=.d)

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(OBJDIR) $(BINDIR) $(OBJDIR)/features/cover $(OBJDIR)/features/menu $(OBJDIR)/features/guide $(OBJDIR)/features/game/board $(OBJDIR)/features/game/computer $(OBJDIR)/features/game/player $(OBJDIR)/features/game/validators $(OBJDIR)/features/shop $(OBJDIR)/features/game/states $(OBJDIR)/features/setting

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	rm -f $(OBJ) $(OBJ:.o=.d)
	rm -rf build/features


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<


.PHONY: all clean directories
