-- Initialisation des données de la base

-- Oblige à dialoguer en UTF8
CHARSET 'utf8';

-- On utilise la base jdr
USE jdr;


-- On désactive les contraintes d'intégrité
SET FOREIGN_KEY_CHECKS = 0;

-- table TypeEvenement

-- On supprime l'ensemble des types 
TRUNCATE TypeEvenement;

-- On ajoute les "standards"
INSERT INTO TypeEvenement (LibelleTypeEvenement)
	VALUES ('Texte'),
	       ('Combat'),
		   ('Piège'),
		   ('Récupération'),
		   ('Donation'),
		   ('Fin');

-- On supprime l'ensemble des types		   
TRUNCATE TypeChoix;	   
	
-- On ajoute les "standards"	
INSERT INTO TypeChoix (LibelleTypeChoix)
	VALUES ('Standard'),
		   ('Victoire'),
		   ('Défaite'),
		   ('Nul');

-- On réactive les contraintes
SET FOREIGN_KEY_CHECKS = 1;	
	