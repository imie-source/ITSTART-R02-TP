# D�claration des variables utilis�es dans le Makefile
REPSRC=src
REPLIB=lib
REPBUILD=build
GCCC=gcc -c

# Format d'une cible :
# cible: d�pendance1 d�pendance2 ...
# <tab> instruction 1
# <tab> instruction 2
# ...		

# Premi�re cible par d�faut
all: ex7.exe

verification.o: $(REPSRC)/verification.c
	$(GCCC) $(REPSRC)/verification.c -o $(REPLIB)/verification.o
	
affichernotes.o: $(REPSRC)/affichernotes.c
	$(GCCC) $(REPSRC)/affichernotes.c -o $(REPLIB)/affichernotes.o
	
ex7.o: $(REPSRC)/ex7.c
	$(GCCC) $(REPSRC)/ex7.c -o $(REPLIB)/ex7.o
	
ex7.exe: verification.o affichernotes.o ex7.o
	gcc $(REPLIB)/verification.o $(REPLIB)/affichernotes.o $(REPLIB)/ex7.o -o $(REPBUILD)/ex7.exe
	
# Efface tous les fichiers interm�diaires et l'ex�cutable	
clean:
	del $(REPLIB)\*.o
	del $(REPBUILD)\*.exe

# Ex�cute l'ex�cutable	
run: ex7.exe
	$(REPBUILD)\ex7.exe
	