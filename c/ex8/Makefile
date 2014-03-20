REPSRC=src
REPLIB=lib
REPBUILD=build
GCCC=gcc -c
GCCE=gcc

all: ex8.exe

ex8.o: $(REPSRC)/ex8.c
	$(GCCC) $(REPSRC)/ex8.c -o $(REPLIB)/ex8.o
	
ex8.exe: ex8.o
	$(GCCE) $(REPLIB)/ex8.o -o $(REPBUILD)/ex8.exe
	
run: ex8.exe
	$(REPBUILD)/ex8.exe

clean:
	del $(REPBUILD)/ex8.exe
	del $(REPLIB)/*.o