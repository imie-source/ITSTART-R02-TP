-- Initialisation des données de la base

-- Oblige à dialoguer en UTF8
CHARSET 'utf8';

-- On utilise la base jdr
USE jdr;


-- On désactive les contraintes d'intégrité
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

-- On crée un personnage par défaut pour le joueur (id : 1)
INSERT INTO personnage (IdPersonnage, PvPersonnage, NomPersonnage) VALUES (1, 20, "Joueur");

-- On crée un évènement de départ par déaut
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (1, "Texte de départ", 1);

-- On réactive les contraintes d'intégrité
SET FOREIGN_KEY_CHECKS = 1;