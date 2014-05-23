<?php

	include("config.inc.php");
	
	// Le coeur du script

	// Connexion obligée à la base de donnée
	
	try {
		$pdo = new PDO($dsn, $bddUser, $bddPassword);
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
	
	/*
	$link = mysql_connect($bddHost, $bddUser, $bddPassword);
	if ($link === false) {
		die("moi pas réussi connexion...");
	} 
	echo "c'est cool ! : " . $link . "<br />\n";
	$bddcnx = mysql_select_db($bddName, $link);
	if (!$bddcnx) {
		die("pas de base jdr à se mettre sous la dent...");
	} */
	echo "je me suis connect&eacute; &agrave; la base '" . $bddName . "'<br />\n";
	die();
	// Si on a sélectionné un choix dans la liste
	// On affiche l'id du choix
	if (!empty($_POST["idpersonnage"])) {
		$requete2 .=  $_POST["idpersonnage"];
		$result = mysql_query($requete2, $link);
		$row = mysql_fetch_assoc($result);
		die("Vous avez sélectionné le personnage : " . $row["NomPersonnage"]);
	}
	
	// On affiche le formulaire
	$result = mysql_query($requete, $link);
	
	echo "<form method=\"POST\">\n";
	
	echo "<select name=\"idpersonnage\">\n";
	echo "<option></option>\n";
	while($row = mysql_fetch_assoc($result)) {
		$option = "<option value=\"";
		$option .= $row["IdPersonnage"] . "\">";
		$option .= $row["NomPersonnage"];
		$option .= " (" . $row["PvPersonnage"] . ")";
		$option .= "</option>\n";
		echo $option;
	}
	
	echo "</select>\n";
	
	echo "<input type=\"submit\" value=\"C'est mon choix\" />\n";
	
	echo "</form>\n";
	
	