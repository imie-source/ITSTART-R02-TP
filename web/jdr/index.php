<?php

	require_once("php/modele.inc.php");

	$titre = "";
	$nomJeu = "Zozor : la qu&ecirc;te interdite";
	if(isset($_POST["prenom"])) {
		demarrePartie($_POST["prenom"]);
	} else {	
		include("html/start.html");
	}	
?>	