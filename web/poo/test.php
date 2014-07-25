<?php
	
	require("EtreHumain.class.php");
	require("Cetace.class.php");
	
	$moi = new EtreHumain("Moi", 1.82, "coucou", 41, "M");
	$mobydick = new Cetace(20, 2500, 25, "M");
	
	$moi->parler("444719");
	$moi->rire();
	
	
	echo "<pre>";
	var_dump($moi);
	var_dump($mobydick);
	echo "</pre>";
	
	echo $moi . "<br />";
	echo $mobydick . "<br />";
	
	echo $moi->marcher() . "<br />";
	echo $mobydick->nager() . "<br />";
	