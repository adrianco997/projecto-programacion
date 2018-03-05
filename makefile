################################################################
# (X)GameLoop       # (X)Command   # (X)Game     # (_)Set      #
# (X)GameReader     # (X)Player    # (X)Object   # (_)Die      #
# (X)GraphicEngine  # (X)Screen    # (X)Space    # (_)Link     #
# (_)GameManagement # (_)GameRules # (_)Dialogue # (_)Inventory#
################################################################
HEAD_DIR= ./Heads
LIBR_DIR= ./Librerias
OBJS_DIR= ./Objetos
################################
CC     = gcc
CFLAGS = -Wall -ansi -pedantic -g -I$(HEAD_DIR)
TARGET = OCA
################################
HEAD= $(patsubst %,%,$(wildcard $(HEAD_DIR)/*.h))
LIBR= $(patsubst %,%,$(wildcard $(LIBR_DIR)/*.c))
OBJS= $(patsubst $(LIBR_DIR)/%.c,$(OBJS_DIR)/%.o,$(wildcard $(LIBR_DIR)/*.c))
################################
.PHONY: DIR gdb run val clean clear gdbtest runtest valtest cl
################################
all: DIR $(OBJS)
	$(eval OBJS2=$(patsubst %_test.o,,$(OBJS)))
	@echo ">>>>>>Creating $(TARGET)";$(CC) -o $(TARGET) $(OBJS2) -lm
$(OBJS_DIR)/%.o: $(LIBR_DIR)/%.c $(HEAD)
	@echo ">>>>>>Creating $@";$(CC) $(CFLAGS) -c -o $@ $<
################################
gdb:
	$(eval pantalla1=$(shell echo `tty`))
	$(eval pantalla2=$(shell echo `tty` | tr 0-9 1-9 ))
	@echo ">>>>>> Running gdb Command"
	@echo "Asegurate de tener abiertas las pantallas $(pantalla1) y $(pantalla2)"; sleep 3
	@echo ">>>>>> Running gdb $(TARGET)";sleep 1;gdb -tui -tty=$(pantalla2) --args ./$(TARGET) data.dat
run:
	@echo ">>>>>>Running $(TARGET)"; ./$(TARGET) data.dat
val:
	@echo ">>>>>>Running $(TARGET) with valgrind";valgrind --leak-check=full ./$(TARGET) data.dat
################################################################
test: $(OBJS_DIR)/set_test.o $(OBJS_DIR)/set.o $(OBJS_DIR)/dice_test.o $(OBJS_DIR)/dice.o
	@echo ">>>>>>Creating set_test";$(CC) -o set_test set_test.o set.o -lm
	@echo ">>>>>>Creating dice_test";$(CC) -o dice_test dice_test.o dice.o -lm
################################
gdbtest: tests
	$(eval pantalla1=$(shell echo `tty`))
	$(eval pantalla2=$(shell echo `tty` | tr 0-9 1-9 ))
	@echo ">>>>>> Running gdb Command"
	@echo "Asegurate de tener abiertas las pantallas $(pantalla1) y $(pantalla2)"; sleep 3
	@echo ">>>>>> Running gdb set_test ";sleep 1;gdb -tui -tty=$(pantalla2) --args ./set_test
	@echo ">>>>>> Running gdb dice_test";sleep 1;gdb -tui -tty=$(pantalla2) --args ./dice_test
runtest: tests
	@echo ">>>>>>Running set_test ";./set_test
	@echo ">>>>>>Running dice_test";./dice_test
valtest: tests
	@echo ">>>>>>Running set_test with valgrind";valgrind --leak-check=full ./set_test
	@echo ">>>>>>Running dice_test with valgrind";valgrind --leak-check=full ./dice_test
################################################################
clean:
	@echo ">>>>>>Eliminating files.o, temporals";rm -f *.o $(OBJS_DIR)/*.o *~ $(HEAD_DIR)/*~ $(LIBR_DIR)/*~ *.gdh $(HEAD_DIR)/*.gdh $(LIBR_DIR)/*.gdh
clear: clean cl
	@echo ">>>>>>Eliminating files.o, temporals and $(TARGET)";rm -f $(TARGET) *.exe set_test dice_test
################################################################
cl:
ifneq ("$(wildcard $(HEAD_DIR))","$(wildcard $(LIBR_DIR))","$(wildcard $(OBJS_DIR))")
	@mv ./*/* .
	@rmdir ./*/
endif
################################################################
DIR:
ifneq ("$(wildcard $(HEAD_DIR))","")
else
	mkdir $(HEAD_DIR)
endif
ifneq ("$(wildcard $(LIBR_DIR))","")
else
	mkdir $(LIBR_DIR)
endif
ifneq ("$(wildcard $(OBJS_DIR))","")
else
	mkdir $(OBJS_DIR)
endif
ifneq ("$(wildcard *.h)","")
	mv ./*.h $(HEAD_DIR)/
endif
ifneq ("$(wildcard *.c)","")
	mv ./*.c $(LIBR_DIR)/
endif
ifneq ("$(wildcard *.o)","")
	mv ./*.o $(OBJS_DIR)/
endif
################################################################
