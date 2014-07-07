<?php

/*
 * Fichier modele.inc.php
 * Contient l'ensemble des fonctions pour jouer au jeu
 */
 
 include(__DIR__ . "/../config/config.inc.php");
 
 /**
  * Se connecte à la base de données suivant les paramètres définis dans config.inc.php
  *
  * @return \PDO Objet PDO de connexion à la base de données
  */
 function cnxBDD() {
	//global : permet d'indiquer à la fonction qu'elle a également la visibilité sur les 
	// variables externes énumérées
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

 function demarrePartie($prenom, $nomJeu) {
	$pdo = cnxBDD();
	$requete = "UPDATE Personnage SET NomPersonnage=:np WHERE IdPersonnage = 1";
	$stmt = $pdo->prepare($requete);
	if ($stmt->bindparam(':np', $prenom, PDO::PARAM_STR)) {
		$stmt->execute();
	}
	// Démarrer une session côté serveur
	session_start();
	// Ajouter dans la session le couple prenom / $prenom
	$_SESSION["prenom"] = $prenom;
	chargeEvenement(1, $nomJeu);
 }
 
 function getPersonnagesFromEvenement($id) {
	$pdo = cnxBDD();
	$requete = "SELECT * FROM personnage, participe_lors WHERE participe_lors.IdEvenement = :id AND personnage.IdPersonnage = participe_lors.IdPersonnage AND personnage.IdPersonnage > 1";
	$stmt = $pdo->prepare($requete);
	$res = array();
	if ($stmt->bindparam(':id', $id, PDO::PARAM_INT)) {
		$stmt->execute();
		// Je récupère l'ensemble des enregistrements
		$tabPersonnages = $stmt->fetchAll(PDO::FETCH_ASSOC);
		if (!empty($tabPersonnages)) {
			foreach($tabPersonnages as $personnage) {
				$res[$personnage["IdPersonnage"]] = array( "nom" => $personnage["NomPersonnage"],
														   "pdv" => $personnage["PvPersonnage"] );
			}	
		}
	}
	// Je retourne le tableau créé
	return $res;
 }
 
 function chargeEvenement($id, $nomJeu) {
	$titre = $nomJeu;
	$pdo = cnxBDD();
	$requete = "SELECT * FROM Evenement WHERE IdEvenement = :id";
	$stmt = $pdo->prepare($requete);
	$texte = "non &eacute;crit";
	if ($stmt->bindparam(':id', $id, PDO::PARAM_INT)) {
		$stmt->execute();
		// Je récupère le premier (et unique) enregistrement
		$tabEvenement = $stmt->fetch(PDO::FETCH_ASSOC);
		if (!empty($tabEvenement)) {
			$texte = $tabEvenement["TexteEvenement"];
		}
	}
	$tabPersonnages = getPersonnagesFromEvenement($id);
	$personnages = "";
	foreach($tabPersonnages as $idPerso => $tabPerso) {
		$personnages .= $tabPerso["nom"] . " (" . $tabPerso["pdv"] . ")<br />";
	}
	$pdvJoueur = getPDV();
	include("html/main.html"); 
 }
 
 function getPDV($id = 1) {
	$pdo = cnxBDD();
	$requete = "SELECT PvPersonnage FROM personnage WHERE IdPersonnage = :id";
	$stmt = $pdo->prepare($requete);
	if ($stmt->bindparam(':id', $id, PDO::PARAM_INT)) {
		$stmt->execute();
		// Je récupère l'enregistrement
		$resPersonnage = $stmt->fetch(PDO::FETCH_ASSOC);
		if (!empty($resPersonnage)) {
			return $resPersonnage["PvPersonnage"];
		}	
	}
	return 0;	
 }