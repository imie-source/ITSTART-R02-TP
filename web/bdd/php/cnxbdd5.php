<?php
	include(__DIR__ . "/../config/config.inc.php");
	
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
	
	$idp = "";
	if (!empty($_POST["idpersonnage"])) {
		$idp = $_POST["idpersonnage"];
	} else if (!empty($_GET["idpersonnage"])) {
		$idp = $_GET["idpersonnage"];
	}
	// Si on a sélectionné un choix dans la liste
	// On affiche l'id du choix
	if (!empty($idp)) {
		$stmt = $pdo->prepare($requete2);
		if ($stmt->bindparam(':idp', $idp, PDO::PARAM_INT)) {
			$stmt->execute();
			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
			$row = $result[0];
			$nomPersonnage = $row["NomPersonnage"];
			include(__DIR__ . "/../html/selection.html");
			die();
		} else {
			die("Erreur interne (requ&ecirc;te 2)");
		}
	}
	
	// On affiche le formulaire
	//$result = mysql_query($requete, $link);
	$sth = $pdo->query($requete);
	$result = $sth->fetchAll(PDO::FETCH_ASSOC);
	
	$options = "";
	
	foreach($result as $row) {
		$options .= "<option value=\"";
		$options .= $row["IdPersonnage"] . "\">";
		$options .= $row["NomPersonnage"];
		$options .= " (" . $row["PvPersonnage"] . ")";
		$options .= "</option>\n";
	}
	
	include(__DIR__ . "/../html/form.html");

	
	