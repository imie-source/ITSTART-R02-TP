/*
 * Script JS commun à l'application
 *
 */

 /**
  * Gère l'affichage du bouton "c'est mon choix"
  */
 function gereAffichageBouton() {
	/*document.getElementById('bChoix').style.visibility = document.getElementById('idpersonnage').selectedIndex > 0 ? "visible" : "hidden";*/
	var styleBChoix = document.getElementById('bChoix').style;
	if (document.getElementById('idpersonnage').selectedIndex > 0) 
		styleBChoix.visibility = 'visible'; 
	else 
		styleBChoix.visibility = 'hidden';	
}

function lZero(n) {
	/*if (n < 10)
		return "0" + n;
	return n;*/
	return n < 10 ? "0"+n : n;
}

function getDateNavigateur() {
	var date = new Date();
	var time = '';
	time += lZero(date.getDate()) + '/' + lZero(date.getMonth()+1) + '/' + date.getFullYear() + ' ';
	time += lZero(date.getHours()) + 'h' + lZero(date.getMinutes()) + '\'' + lZero(date.getSeconds()) + '\'\''; 
	document.getElementById("dateHeureNavigateur").innerHTML = time;
	//setTimeout("getDateNavigateur();", 900);
}
