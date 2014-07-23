<?php
	
	require("EtreHumain.class.php");
	
	$moi = new EtreHumain("Moi", 1.82, "coucou", 41, "M");
	/*$moi->taille = 1.82;
	$moi->setPoids("coucou");
	$moi->age = 41;
	$moi->sexe = "M";*/
	
	$autre = new EtreHumain("Autre", 1.70, 70, 35, "M");
	/*$autre->taille = 1.70;
	$autre->setPoids(70);
	$autre->age = 35;
	$autre->sexe = "M";*/
	
	$tierce = new EtreHumain("Tierce");
	
	$moi->parler("444719");
	$moi->rire();
	
	$autre->parler("je suis l'autre !");
	$autre->rire();
	
	echo "<pre>";
	var_dump($moi);
	var_dump($autre);
	echo "</pre>";
	
	echo $moi . "<br />";
	echo $autre . "<br />";
	echo $tierce . "<br />";
	echo "mon poids est : " . $moi->getPoids() . "<br />";
	echo "le poids de l'autre est : " . $autre->getPoids() . "<br />";
	echo "le poids de tierce est : " . $tierce->getPoids() . "<br />";
	echo "ma taille est : " . $moi->getTaille() . "<br />";
	echo "la taille de l'autre est : " . $autre->getTaille() . "<br />";
	echo "la taille de tierce est : " . $tierce->getTaille() . "<br />";
	echo "mon age est : " . $moi->getAge() . "<br />";
	echo "l'age de l'autre est : " . $autre->getAge() . "<br />";
	echo "l'age de tierce est : " . $tierce->getAge() . "<br />";
	echo "mon sexe est : " . $moi->getSexe() . "<br />";
	echo "le sexede l'autre est : " . $autre->getSexe() . "<br />";
	echo "le sexe de tierce est : " . $tierce->getSexe() . "<br />";