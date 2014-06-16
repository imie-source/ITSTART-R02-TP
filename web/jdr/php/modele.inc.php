<?php

/*
 * Fichier modele.inc.php
 * Contient l'ensemble des fonctions pour jouer au jeu
 */
 
 include(__DIR__ . "/../config/config.inc.php");
 
 function cnxBDD() {
	global $dsn, $bddUser, $bddPassword;
	try {
		$pdo = new PDO($dsn, $bddUser, $bddPassword);
		return $pdo;
	} catch(PDOException $e) {
		$msg = "Erreur : ";
		switch($e->getCode()) {
			case 1045: $msg .= "votre couple identifiant/mot de passe est incorrect...";
				break;
			case 1049: $msg .= "la base demand&eacute;e est incorrect...";
				break;	
			case 2002: $msg .= "le serveur est inaccessible...";
				break;		
			default:
				$msg .= "probl&egrave;me avec la bdd... (" . $e->getCode() . ")";
				break;
		}		
		die($msg);
	}
}

 function demarrePartie($prenom) {
	$pdo = cnxBDD();
	$requete = "UPDATE Personnage SET NomPersonnage=:np WHERE IdPersonnage = 1";
	$stmt = $pdo->prepare($requete);
	if ($stmt->bindparam(':np', $prenom, PDO::PARAM_STR)) {
		$stmt->execute();
	}	
	die("Bonjour (demarrePartie) : $prenom");
 }