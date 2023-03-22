NUM3 = num3

NUM3EXEC = $(NUM3).x



NUM3OBJS  = $(NUM3).o



CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean run

all: $(NUM3EXEC) 
$(NUM3EXEC): $(NUM3OBJS)
		$(LD) -o $@ $(LFLAGS) $^
run: $(NUM3EXEC)
	./$(NUM3EXEC)
clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 