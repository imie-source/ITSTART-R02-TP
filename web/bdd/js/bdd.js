/*
 * Script JS commun � l'application
 *
 */

 /**
  * G�re l'affichage du bouton "c'est mon choix"
  */
 function gereAffichageBouton() {
	/*document.getElementById('bChoix').style.visibility = document.getElementById('idpersonnage').selectedIndex > 0 ? "visible" : "hidden";*/
	var styleBChoix = document.getElementById('bChoix').style;
	if (document.getElementById('idpersonnage').selectedIndex > 0) 
		styleBChoix.visibility = 'visible'; 
	else 
		styleBChoix.visibility = 'hidden';	
}