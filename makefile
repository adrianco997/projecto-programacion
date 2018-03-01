################################################################
# (X)GameLoop       # (X)Command   # (X)Game     # (_)Set      #
# (X)GameReader     # (X)Player    # (X)Object   # (_)Die      #
# (X)GraphicEngine  # (X)Screen    # (X)Space    # (_)Link     #
# (_)GameManagement # (_)GameRules # (_)Dialogue # (_)Inventory#
################################################################
CC     = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJS = $(patsubst %.c,%.o,$(wildcard *.c))
TARGET= OCA
################################################################
.PHONY: all run gdb valg clean clear test
################################################################
all: $(OBJS)
	@echo ">>>>>>Creating $(TARGET)";$(CC) -o $(TARGET) $^
	#@echo ">>>>>>Creating set_test";$(CC) -o set_test set_test.o set.o
	#@echo ">>>>>>Creating dice_test";$(CC) -o dice_test dice_test.o dice.o
%.o: %.c %.h
	@echo ">>>>>>Creating $@";$(CC) $(CFLAGS) -c -o $@ $<
%.o: %.c
	@echo ">>>>>>Creating main file$@";$(CC) $(CFLAGS) -c -o $@ $<
################################################################
run: all
	@echo ">>>>>>Running $(TARGET)"; ./$(TARGET) data.dat
gdb: all
	$(eval pantalla1=$(shell echo `tty`))
	$(eval pantalla2=$(shell echo `tty` | tr 0-9 1-10 ))
	@echo ">>>>>>Running gdb Command"
	@echo "Asegurate de tener abiertas las pantallas $(pantalla1) y $(pantalla2)"; sleep 5
	@echo ">>>>>> Running gdb p2_e1";sleep 1;gdb -tui -tty=$(pantalla) --args ./$(TARGET) data.dat;
valg:
	@echo ">>>>>>Running $(TARGET) with valgrind";valgrind --leak-check=full ./$(TARGET) data.dat
################################################################
clean:
	@echo ">>>>>>Eliminating files.o and temporals";rm -f *.o *~
clear: clean
	@echo ">>>>>>Eliminating files.o, temporals and $(TARGET)";rm -f $(TARGET) $(TARGET).exe
################################################################
test: all
	">>>>>>Running set_test"; ./set_test
	">>>>>>Running dice_test"; ./dice_test
################################################################
