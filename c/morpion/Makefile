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

morpion.exe: morpion.o plateau.o detection.o affichage.o partie.o random.o ia.o
	$(GCCE) $(REPLIB)\morpion.o $(REPLIB)\plateau.o $(REPLIB)\detection.o $(REPLIB)\affichage.o $(REPLIB)\partie.o $(REPLIB)\random.o $(REPLIB)\ia.o -o $(REPBUILD)\morpion.exe

random.o: $(REPSRC)\random.c
	$(GCCC) $(REPSRC)\random.c -o $(REPLIB)\random.o

ia.o: $(REPSRC)\ia.c
	$(GCCC) $(REPSRC)\ia.c -o $(REPLIB)\ia.o
	
run: morpion.exe 
	$(REPBUILD)\morpion.exe $(ARGS)
	
clean:
	del $(REPBUILD)\morpion.exe
	del $(REPLIB)\*.o