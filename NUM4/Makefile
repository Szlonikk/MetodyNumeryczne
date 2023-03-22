NUM4 = num4
NUM4CZAS=num4CZAS
NUM4EXEC = $(NUM4).x
NUM4CZASEXEC = $(NUM4CZAS).x


NUM4OBJS  = $(NUM4).o
NUM4CZASOBJS = $(NUM4CZAS).o


CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean run czas

all: $(NUM4EXEC) $(NUM4CZASEXEC)
$(NUM4EXEC): $(NUM4OBJS)
		$(LD) -o $@ $(LFLAGS) $^
$(NUM4CZASEXEC): $(NUM4CZASOBJS)
		$(LD) -o $@ $(LFLAGS) $^
run: $(NUM4EXEC)
	./$(NUM4EXEC)
czas: $(NUM4CZASEXEC)
	./$(NUM4CZASEXEC)
clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 
