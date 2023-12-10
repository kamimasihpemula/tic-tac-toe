CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lwinmm
SRCDIR = ../src
TESTDIR = .
OBJDIR = ../build
BINDIR = ../bin

UNIT_TEST_EXECUTABLE = $(BINDIR)/unit_test.exe

SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/features/cover/*.c) $(wildcard $(SRCDIR)/features/menu/*.c) $(wildcard $(SRCDIR)/features/guide/*.c) $(wildcard $(SRCDIR)/features/game/*.c) $(wildcard $(SRCDIR)/features/game/board/*.c) $(wildcard $(SRCDIR)/features/game/computer/*.c) $(wildcard $(SRCDIR)/features/game/player/*.c) $(wildcard $(SRCDIR)/features/game/validators/*.c) $(wildcard $(SRCDIR)/features/shop/*.c) $(wildcard $(SRCDIR)/features/game/states/*.c) $(wildcard $(SRCDIR)/features/setting/*.c)
TEST_SRC = $(wildcard $(TESTDIR)/*.c) $(wildcard $(TESTDIR)/unity/src/*.c)

OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
TEST_OBJ = $(patsubst $(TESTDIR)/%.c, $(OBJDIR)/%.o, $(TEST_SRC))

-include $(OBJ:.o=.d)

all: directories $(UNIT_TEST_EXECUTABLE)

directories:
	mkdir -p $(OBJDIR) $(BINDIR) $(OBJDIR)/features/cover $(OBJDIR)/features/menu $(OBJDIR)/features/guide $(OBJDIR)/features/game/board $(OBJDIR)/features/game/computer $(OBJDIR)/features/game/player $(OBJDIR)/features/game/validators $(OBJDIR)/features/shop $(OBJDIR)/features/game/states $(OBJDIR)/features/setting $(OBJDIR)/unity/src

$(UNIT_TEST_EXECUTABLE): $(TEST_OBJ) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	rm -f $(OBJ) $(OBJ:.o=.d)
	rm -f $(TEST_OBJ) $(TEST_OBJ:.o=.d)
	rm -rf ../build/features
	rm -rf ../build/unity

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

.PHONY: all clean directories

clean:
	rm -rf $(OBJDIR) $(BINDIR)
