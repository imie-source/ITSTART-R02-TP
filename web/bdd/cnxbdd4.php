<?php

	// Liste des donn�es dont on a besoin
	
	$bddHost = "127.0.0.1";
	$bddUser = "root";
	$bddPassword = "";
	$bddName = "jdr";
	$requete = "select * from personnage";
	$requete2 = "select * from personnage where IdPersonnage = ";
	
	// Le coeur du script

	// Connexion oblig�e � la base de donn�e
	$link = mysql_connect($bddHost, $bddUser, $bddPassword);
	if (!$link) {
		die("moi pas r�ussi connexion...");
	} 
	echo "c'est cool !<br />\n";
	$bddcnx = mysql_select_db($bddName, $link);
	if (!$bddcnx) {
		die("pas de base jdr � se mettre sous la dent...");
	}
	echo "je me suis connect� � la base '" . $bddName . "'<br />\n";

	// Si on a s�lectionn� un choix dans la liste
	// On affiche l'id du choix
	if (!empty($_POST["idpersonnage"])) {
		$requete2 .=  $_POST["idpersonnage"];
		$result = mysql_query($requete2, $link);
		$row = mysql_fetch_assoc($result);
		die("Vous avez s�lectionn� le personnage : " . $row["NomPersonnage"]);
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
	
	