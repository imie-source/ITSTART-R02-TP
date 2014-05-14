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
	(3, "Bouteille", 11),
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
-- la reine Morgane est présente lors de cet évènement
INSERT INTO participe_lors (IdEvenement, IdPersonnage) VALUES (2, 7);	

-- Evènement 3
-- Création de l'évènement de type récupération	 
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (3, 'La reine Morgane vous file le gourdin, qui vous emplie de joie', 4);
-- Création du seul choix après la récup
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES (6, 'Vous vous rafraichissez...', 4);
-- Affecte ce choix à l'évènement
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES (3, 6, 1);
-- indique quel objet est récupéré par le joueur
INSERT INTO est_utilise_lors (IdEvenement, IdObjet) VALUES (3, 7);

-- Evènement 4
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (4, 'Après vous être rafraichi, vous souhaitez...', 1);
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES 
	(7, 'vous entraîner au combat sur un rat', 5),
	(8, 'quitter Brocéliande, direction le Périph SE', 9);
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES 
	(4, 7, 1),
	(4, 8, 1);

-- Evènement 5
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (5, 'Vous vous entraînez au combat sur un redoutable rat velu. L''issue est incertaine...', 2);
-- le rat est présent lors de cet évènement
INSERT INTO participe_lors (IdEvenement, IdPersonnage) VALUES (5, 11);	
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES 
	(9, 'victoire', 6),
	(10, 'défaite', 7); 
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES 
	(5, 9, 2),
	(5, 10, 3);	

-- Evènement 6
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES (6, 'Vous n''en avez fait qu''une bouchée de ce méchant rat... Derrière lui se trouve une bouteille', 1);
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES (11, 'Vous pouvez vous emparer de la bouteille ainsi que l''écu...', 8);
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES (6, 11, 1);
INSERT INTO est_utilise_lors (IdEvenement, IdObjet) VALUES 
	(6, 3),
	(6, 11);

-- Evènement 7
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES 
	(7, 'Oh le noob... Défoncé par un pauvre rat...', 1);
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES 
	(12, 'vous retournez piteux', 4);
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES 
	(7, 12, 1);
INSERT INTO participe_lors (IdEvenement, IdPersonnage) VALUES 
	(7, 11);	

-- Evènement 8
INSERT INTO evenement (IdEvenement, TexteEvenement, IdTypeEvenement) VALUES 
	(8, 'Vous récupérez la bouteille et l''écu', 4);
INSERT INTO choix (IdChoix, LibelleChoix, IdEvenement) VALUES 
	(13, 'vous retournez dans le château', 4);
INSERT INTO propose_le_choix (IdEvenement, IdChoix, IdTypeChoix) VALUES 
	(8, 13, 1);
INSERT INTO est_utilise_lors (IdEvenement, IdObjet) VALUES 
	(8, 3),
	(8, 11);	
	
	
	
SET FOREIGN_KEY_CHECKS = 1;	
	