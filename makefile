################################################################
# (X)GameLoop       # (X)Command   # (X)Game     # (_)Set      #
# (X)GameReader     # (X)Player    # (X)Object   # (_)Die      #
# (X)GraphicEngine  # (X)Screen    # (X)Space    # (_)Link     #
# (_)GameManagement # (_)GameRules # (_)Dialogue # (_)Inventory#
################################################################
CC     = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJS   = $(patsubst %.c,%.o,$(wildcard *.c))
TARGET = OCA
################################
all: $(OBJS)
	@echo ">>>>>>Creating $(TARGET)";$(CC) -o $(TARGET) $^;rm -f *.o *~
%.o: %.c $(FHEADS)%.h
	@echo ">>>>>>Creating $@";$(CC) $(CFLAGS) -c -o $@ $<
%.o: %.c
	@echo ">>>>>>Creating $@";$(CC) $(CFLAGS) -c -o $@ $<
tests: set_test.o set.o dice_test.o dice.o
	@echo ">>>>>>Creating $@";$(CC) $(CFLAGS) -c -o set_test set_test.o set.o
	@echo ">>>>>>Creating $@";$(CC) $(CFLAGS) -c -o dice_test dice_test.o dice.o
################################
.PHONY: run clean clear gdb val tests
gdb:
	gdb -tui -tty=/dev/pts/5 --args ./$(TARGET) data.dat;run data.dat
run:
	@echo ">>>>>>Running $(TARGET)"; ./$(TARGET) data.dat
clean:
	@echo ">>>>>>Eliminating files.o and temporals";rm -f *.o *~
clear:
	@echo ">>>>>>Eliminating files.o, temporals and $(TARGET)";rm -f *.o *~ $(TARGET) *.exe set_test dice_test
################################################################
val:
	@echo ">>>>>>Running $(TARGET) with valgrind";valgrind --leak-check=full ./$(TARGET) data.dat

#diff:
#	diff -s
