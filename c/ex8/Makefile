REPSRC=src
REPLIB=lib
REPBUILD=build
GCCC=gcc -c
GCCE=gcc

all: ex8.exe

ex8.o: $(REPSRC)/ex8.c
	$(GCCC) $(REPSRC)/ex8.c -o $(REPLIB)/ex8.o

quelleoperation.o: $(REPSRC)/quelleoperation.c
	$(GCCC) $(REPSRC)/quelleoperation.c -o $(REPLIB)/quelleoperation.o

trouveoperandes.o: $(REPSRC)/trouveoperandes.c
	$(GCCC) $(REPSRC)/trouveoperandes.c -o $(REPLIB)/trouveoperandes.o
	
substring.o: $(REPSRC)/substring.c
	$(GCCC) $(REPSRC)/substring.c -o $(REPLIB)/substring.o	

strndup.o: $(REPSRC)/strndup.c
	$(GCCC) $(REPSRC)/strndup.c -o $(REPLIB)/strndup.o		

calculeoperation.o: $(REPSRC)/calculeoperation.c
	$(GCCC) $(REPSRC)/calculeoperation.c -o $(REPLIB)/calculeoperation.o		

factorielle.o: $(REPSRC)/factorielle.c	
	$(GCCC) $(REPSRC)/factorielle.c -o $(REPLIB)/factorielle.o		

ex8.exe: ex8.o quelleoperation.o substring.o strndup.o trouveoperandes.o calculeoperation.o factorielle.o
	$(GCCE) $(REPLIB)/ex8.o $(REPLIB)/quelleoperation.o $(REPLIB)/substring.o $(REPLIB)/strndup.o $(REPLIB)/calculeoperation.o $(REPLIB)/trouveoperandes.o $(REPLIB)/factorielle.o -o $(REPBUILD)/ex8.exe
	
run: ex8.exe
	$(REPBUILD)/ex8.exe

clean:
	del $(REPBUILD)/ex8.exe
	del $(REPLIB)/*.o