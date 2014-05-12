-- Configuration du jeu "en commun"

-- Oblige à dialoguer en UTF8
CHARSET 'utf8';

-- On utilise la base jdr
USE jdr;

-- On désactive les contraintes d'intégrité
SET FOREIGN_KEY_CHECKS = 0;

UPDATE personnage SET NomPersonnage = "Link" WHERE IdPersonnage = 1;
INSERT INTO personnage (IdPersonnage, NomPersonnage, PvPersonnage) VALUES 
	(2, "Roi Bens", 20),
	(3, "Roi Stark", 30),
	(4, "Roi Poutine", 25),
	(5, "Roi Baracke", 25),
	(6, "Roi BayR'ou",10),
	(7, "Morgane", 30),
	(8, "Lapin égorgeur", 50),
	(9, "Blob", 1000000),
	(10, "Dragon", 500),
	(11, "Rat", 5),
	(12, "Rat", 5),
	(13, "Rat", 5),
	(14, "Rat", 5),
	(15, "Rat", 5),
	(16, "Troll des Montagnes", 45),
	(17, "Belle-Mère", 666),
	(18, "Ivrogne", 8),
	(19, "Serge COUDÉ", 10);