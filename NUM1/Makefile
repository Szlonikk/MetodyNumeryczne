WYKRESAD = wykresd
WYKRESBD = wykresBd
WYKRESAF = wykresf
WYKRESBF = wykresBf

WYKRESADEXE= $(WYKRESAD).x
WYKRESBDEXE= $(WYKRESBD).x
WYKRESAFEXE= $(WYKRESAF).x
WYKRESBFEXE= $(WYKRESBF).x

WYKRESADOBJ= $(WYKRESAD).o
WYKRESBDOBJ= $(WYKRESBD).o
WYKRESAFOBJ= $(WYKRESAF).o
WYKRESBFOBJ= $(WYKRESBF).o

CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean runAd runAf runBd runBf

all: $(WYKRESADEXE) $(WYKRESBDEXE) $(WYKRESAFEXE) $(WYKRESBFEXE)

$(WYKRESADEXE): $(WYKRESADOBJ)
		$(LD) -o $@ $(LFLAGS) $^

$(WYKRESBDEXE): $(WYKRESBDOBJ)
		$(LD) -o $@ $(LFLAGS) $^

$(WYKRESAFEXE): $(WYKRESAFOBJ)
		$(LD) -o $@ $(LFLAGS) $^

$(WYKRESBFEXE): $(WYKRESBFOBJ)
		$(LD) -o $@ $(LFLAGS) $^

run: $(WYKRESADEXE) $(WYKRESBDEXE) $(WYKRESAFEXE) $(WYKRESBFEXE)
	./$(WYKRESADEXE) > dane.txt
	./$(WYKRESBDEXE) > daneBd.txt
	./$(WYKRESAFEXE) > danef.txt
	./$(WYKRESBFEXE) > daneBf.txt
	
clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe *.txt