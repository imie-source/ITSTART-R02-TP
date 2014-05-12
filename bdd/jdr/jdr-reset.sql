-- Initialisation des donn�es de la base

-- Oblige � dialoguer en UTF8
CHARSET 'utf8';

-- On utilise la base jdr
USE jdr;


-- On d�sactive les contraintes d'int�grit�
SET FOREIGN_KEY_CHECKS = 0;

-- On vide les tables pour un nouveau jeu
TRUNCATE choix;
TRUNCATE est_utilise_lors;
TRUNCATE evenement;
TRUNCATE objet;
TRUNCATE participe_lors;
TRUNCATE personnage;
TRUNCATE propose_le_choix;
TRUNCATE statistique;

-- On cr�e un personnage par d�faut pour le joueur (id : 1)
INSERT INTO personnage (IdPersonnage, PvPersonnage, NomPersonnage) VALUES (1, 20, "Joueur");

-- On cr�e un �v�nement de d�part par d�faut
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (1, "Texte de d�part", 1);

-- On r�active les contraintes d'int�grit�
SET FOREIGN_KEY_CHECKS = 1;