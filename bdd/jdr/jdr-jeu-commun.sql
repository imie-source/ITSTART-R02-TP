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
	
INSERT INTO objet (IdObjet, NomObjet, IdPersonnage) VALUES
	(1, "Paquet de Riz", 2),
	(2, "Epée", 6),
	(3, "Bouteille", NULL),
	(4, "Bilboquet", 16),
	(5, "Tronçonneuse", 19),
	(6, "Fiole",  NULL),
	(7, "Livres", 5),
	(8, "Armure", NULL),
	(9, "Argents (10 écus)", 10),
	(10, "Argents (5 écus)", NULL),
	(11, "Argents (1 écu)", 11),
	(12, "Bottes magiques", 10),
	(13, "Gourdin", 7),
	(14, "Serviette", NULL),
	(15, "Carte", 15);
	
SET FOREIGN_KEY_CHECKS = 1;	
	