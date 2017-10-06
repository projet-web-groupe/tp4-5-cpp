CC = g++
CCFLAGS= -Wall -pedantic -ggdb
EXTC = cpp
EXTH = h
EXECUTABLE = tp4-5

SRC = $(wildcard *.$(EXTC))
HDR = $(wildcard *.$(EXTH))
OBJ = $(SRC:.$(EXTC)=.o)

.PHONY:all

all: $(EXECUTABLE)
$(EXECUTABLE):$(OBJ)
	@$(CC) -o $@ $^
%.o:%.$(EXTC) %.$(EXTH)
	@$(CC) $(CCFLAGS) -o $@ -c $<
clean:
	@rm -rf *.o
	@rm -f $(EXECUTABLE)
	@echo "Clean ok"
