<?php

	// Liste des donn�es dont on a besoin
	// A reconfigurer si besoin
	
	// H�te h�bergeant le serveur de base de donn�es
	$bddHost = "127.0.0.1";
	// Port d'�coute du serveur de base de donn�es
	$bddPort = 3306;
	// Compte utilisateur pour se connecter � la base de donn�es
	$bddUser = "root";
	// Mot de passe du compte utilisateur pour se connecter � la base de donn�es
	$bddPassword = "";
	// Nom de la base de donn�es
	$bddName = "jdr";
	// Type du serveur de base de donn�es
	$bddType = "mysql";
	
	// Ne pas toucher ;-)
	// DSN : Data Source Name
	$dsn = "$bddType:host=$bddHost;port=$bddPort;dbname=$bddName";
	// Premi�re requ�te pour avoir l'ensemble des personnages
	$requete = "select * from personnage";
	// Deuxi�me requ�te pour avoir un personnage pr�cis
	$requete2 = "select * from personnage where IdPersonnage = :idp";