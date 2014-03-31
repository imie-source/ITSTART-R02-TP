REPSRC=src
REPLIB=lib
REPBUILD=build
GCCC=gcc -c
GCCE=gcc

all: morpion.exe

affichage.o: $(REPSRC)\affichage.c
	$(GCCC) $(REPSRC)\affichage.c -o $(REPLIB)\affichage.o

detection.o: $(REPSRC)\detection.c
	$(GCCC) $(REPSRC)\detection.c -o $(REPLIB)\detection.o

plateau.o: $(REPSRC)\plateau.c
	$(GCCC) $(REPSRC)\plateau.c -o $(REPLIB)\plateau.o
	
partie.o: $(REPSRC)\partie.c
	$(GCCC) $(REPSRC)\partie.c -o $(REPLIB)\partie.o	
	
morpion.o: $(REPSRC)\morpion.c
	$(GCCC) $(REPSRC)\morpion.c -o $(REPLIB)\morpion.o

morpion.exe: morpion.o plateau.o detection.o affichage.o partie.o
	$(GCCE) $(REPLIB)\morpion.o $(REPLIB)\plateau.o $(REPLIB)\detection.o $(REPLIB)\affichage.o $(REPLIB)\partie.o -o $(REPBUILD)\morpion.exe

run: morpion.exe 
	$(REPBUILD)\morpion.exe $(ARGS)
	
clean:
	del $(REPBUILD)\morpion.exe
	del $(REPLIB)\*.o