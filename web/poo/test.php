<?php
	
	require("EtreHumain.class.php");
	require("Cetace.class.php");
	
	$moi = new EtreHumain("Moi", 1.82, "coucou", 41, "M");
	$mobydick = new Cetace(20, 2500, 25, "M");
	$unmam = new Mammifere(3, 60, 12, "F");
	
	$moi->communiquer("444719");
	$moi->rire();
	
	
	echo "<pre>";
	var_dump($moi);
	var_dump($mobydick);
	var_dump($unmam);
	echo "</pre>";
	
	echo $moi . "<br />";
	echo $mobydick . "<br />";
	echo $unmam . "<br />";
	
	echo $moi->seDeplacer() . "<br />";
	echo $mobydick->seDeplacer() . "<br />";
	
	echo $mobydick->communiquer("coucou") . "<br />";
	echo $unmam->seDeplacer() . "<br />";
	echo $unmam->communiquer("coucou") . "<br />";
	