<?php

	require_once("php/modele.inc.php");

	$nomJeu = "Zozor : la qu&ecirc;te interdite";
	if(isset($_POST["prenom"])) {
		demarrePartie($_POST["prenom"], $nomJeu);
	} else {	
		include("html/start.html");
	}	
?>	