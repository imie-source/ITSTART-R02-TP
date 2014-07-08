<?php

	require_once("php/modele.inc.php");

	$nomJeu = "Zozor : la qu&ecirc;te interdite";
	
	$action = isset($_POST["action"]) ? $_POST["action"] : (isset($_GET["action"]) ? $_GET["action"] : "");
	if (!empty($action)) {
		switch($action) {
			case "goevent":
				chargeEvenement($_POST["idEven"], $nomJeu); 
				break;
			case "affichepersonnage":
				affichePersonnage($_GET["id"]);
				break;
		}		
	} else if(isset($_POST["prenom"])) {
		demarrePartie($_POST["prenom"], $nomJeu);
	} else {
		include("html/start.html");
	}	
?>	