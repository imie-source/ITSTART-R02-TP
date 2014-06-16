<?php

	// Liste des données dont on a besoin
	// A reconfigurer si besoin
	
	// Hôte hébergeant le serveur de base de données
	$bddHost = "127.0.0.1";
	// Port d'écoute du serveur de base de données
	$bddPort = 3306;
	// Compte utilisateur pour se connecter à la base de données
	$bddUser = "root";
	// Mot de passe du compte utilisateur pour se connecter à la base de données
	$bddPassword = "";
	// Nom de la base de données
	$bddName = "jdr";
	// Type du serveur de base de données
	$bddType = "mysql";
	
	// Ne pas toucher ;-)
	// DSN : Data Source Name
	$dsn = "$bddType:host=$bddHost;port=$bddPort;dbname=$bddName";
	