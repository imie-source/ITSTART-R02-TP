-- Configuration du jeu "en commun"

-- Oblige à dialoguer en UTF8
DEFAULT CHARSET 'utf8';

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
	
-- Ajout des évenements

-- Evènement 1
UPDATE evenement SET TexteEvenement = 'Mes homages votre majesté, votre seigneurie venez d''atteindre le pays des 6 royaumes, vous vous dirigez vers le royaume de Brocéliande...' WHERE IdEvenement = 1;
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES (1, 'Vous vous rendez en Brocéliande', 2);
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES (1, 1, 1);

-- Evènement 2
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (2, 'Vous prenez séance auprès de Morgane, qui vous explique qu''un dragon terrorise le pays des 6 royaumes et qu''aucun des 6 rois ou reine ne réussit à s''en débarraser. Vous êtes leur dernière chance de survie. Elle vous propose de vous filer le gourdin', 1);
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES 
	(2, 'Vous prenez le gourdin', 3),
	(3, 'Vous ne prenez pas le gourdin', 4),
	(4, 'Vous testez votre art du combat contre un rat', 5),
	(5, 'Vous rejoignez le périph SE', 9);
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES 
	(2, 2, 1),
	(2, 3, 1),
	(2, 4, 1),
	(2, 5, 1);

-- Evènement 3	 
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (3, 'La reine Morgane vous file le gourdin, qui vous emplie de joie', 4);
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES (6, 'Vous vous rafraichissez...', 4);
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES (3, 6, 1);
SET FOREIGN_KEY_CHECKS = 1;	
	