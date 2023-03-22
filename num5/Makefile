NUMG = NUM5_G
NUMJ=NUM5_J

NUMGEXEC = $(NUMG).x
NUMJEXEC = $(NUMJ).x



NUMGOBJS  = $(NUMG).o
NUMJOBJS  = $(NUMJ).o


CXXFLAGS = -Wall -pedantic -O
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CXXFLAGS) -c $<

.PHONY: all clean run

all: $(NUMGEXEC) $(NUMJEXEC)
$(NUMGEXEC): $(NUMGOBJS)
		$(LD) -o $@ $(LFLAGS) $^
$(NUMJEXEC): $(NUMJOBJS)
		$(LD) -o $@ $(LFLAGS) $^
rung: $(NUMGEXEC)
	./$(NUMGEXEC)
runj: $(NUMJEXEC)
	./$(NUMJEXEC)
clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 
