# script créé le : Mon Apr 28 16:12:27 CEST 2014 -   syntaxe MySQL ;

DROP DATABASE IF EXISTS jdr;

CREATE DATABASE jdr;

USE  jdr ;

DROP TABLE IF EXISTS Personnage ;
CREATE TABLE Personnage (IdPersonnage int AUTO_INCREMENT NOT NULL,
PvPersonnage INT COMMENT 'Point de Vie du personnage',
NomPersonnage VARCHAR(100) COMMENT 'Nom du personnage',
PRIMARY KEY (IdPersonnage) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Statistique ;
CREATE TABLE Statistique (IdStatistique int AUTO_INCREMENT NOT NULL,
LibelleStatistique VARCHAR(100),
ValeurStatistique INT COMMENT 'Positive : attaque, Négative : défense',
DureeStatistique INT COMMENT 'En nombre de jours',
IdPersonnage INT NOT NULL COMMENT 'Lien entre la table Statistique et la table Personnage',
IdObjet INT NOT NULL,
PRIMARY KEY (IdStatistique) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Objet ;
CREATE TABLE Objet (IdObjet int AUTO_INCREMENT NOT NULL,
NomObjet VARCHAR(50),
IdPersonnage INT,
PRIMARY KEY (IdObjet) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Choix ;
CREATE TABLE Choix (IdChoix int AUTO_INCREMENT NOT NULL,
LibelleChoix VARCHAR(255),
IdEvenement INT NOT NULL,
PRIMARY KEY (IdChoix) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Evenement ;
CREATE TABLE Evenement (IdEvenement int AUTO_INCREMENT NOT NULL,
TexteEvenement TEXT,
IdTypeEvenement INT,
PRIMARY KEY (IdEvenement) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS TypeEvenement ;
CREATE TABLE TypeEvenement (IdTypeEvenement int AUTO_INCREMENT NOT NULL,
LibelleTypeEvenement VARCHAR(255),
PRIMARY KEY (IdTypeEvenement) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS TypeChoix ;
CREATE TABLE TypeChoix (IdTypeChoix int AUTO_INCREMENT NOT NULL,
LibelleTypeChoix VARCHAR(50),
PRIMARY KEY (IdTypeChoix) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Propose_le_choix ;
CREATE TABLE Propose_le_choix (IdEvenement int AUTO_INCREMENT NOT NULL,
IdChoix INT NOT NULL,
IdTypeChoix INT NOT NULL,
PRIMARY KEY (IdEvenement,
 IdChoix,
 IdTypeChoix) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Est_utilisé_lors ;
CREATE TABLE Est_utilisé_lors (IdObjet int AUTO_INCREMENT NOT NULL,
IdEvenement INT NOT NULL,
PRIMARY KEY (IdObjet,
 IdEvenement) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Participe_lors ;
CREATE TABLE Participe_lors (IdPersonnage int AUTO_INCREMENT NOT NULL,
IdEvenement INT NOT NULL,
PRIMARY KEY (IdPersonnage,
 IdEvenement) ) ENGINE=InnoDB;

ALTER TABLE Statistique ADD CONSTRAINT FK_Statistique_IdPersonnage FOREIGN KEY (IdPersonnage) REFERENCES Personnage (IdPersonnage);

ALTER TABLE Statistique ADD CONSTRAINT FK_Statistique_IdObjet FOREIGN KEY (IdObjet) REFERENCES Objet (IdObjet);
ALTER TABLE Objet ADD CONSTRAINT FK_Objet_IdPersonnage FOREIGN KEY (IdPersonnage) REFERENCES Personnage (IdPersonnage);
ALTER TABLE Choix ADD CONSTRAINT FK_Choix_IdEvenement FOREIGN KEY (IdEvenement) REFERENCES Evenement (IdEvenement);
ALTER TABLE Evenement ADD CONSTRAINT FK_Evenement_IdTypeEvenement FOREIGN KEY (IdTypeEvenement) REFERENCES TypeEvenement (IdTypeEvenement);
ALTER TABLE Propose_le_choix ADD CONSTRAINT FK_Propose_le_choix_IdEvenement FOREIGN KEY (IdEvenement) REFERENCES Evenement (IdEvenement);
ALTER TABLE Propose_le_choix ADD CONSTRAINT FK_Propose_le_choix_IdChoix FOREIGN KEY (IdChoix) REFERENCES Choix (IdChoix);
ALTER TABLE Propose_le_choix ADD CONSTRAINT FK_Propose_le_choix_IdTypeChoix FOREIGN KEY (IdTypeChoix) REFERENCES TypeChoix (IdTypeChoix);
ALTER TABLE Est_utilisé_lors ADD CONSTRAINT FK_Est_utilisé_lors_IdObjet FOREIGN KEY (IdObjet) REFERENCES Objet (IdObjet);
ALTER TABLE Est_utilisé_lors ADD CONSTRAINT FK_Est_utilisé_lors_IdEvenement FOREIGN KEY (IdEvenement) REFERENCES Evenement (IdEvenement);
ALTER TABLE Participe_lors ADD CONSTRAINT FK_Participe_lors_IdPersonnage FOREIGN KEY (IdPersonnage) REFERENCES Personnage (IdPersonnage);
ALTER TABLE Participe_lors ADD CONSTRAINT FK_Participe_lors_IdEvenement FOREIGN KEY (IdEvenement) REFERENCES Evenement (IdEvenement);
