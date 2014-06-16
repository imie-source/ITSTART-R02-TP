
var affichageMenuEnCours = false;

function detecteSurvolMenu(mouseEvent) {
	mouseEvent = mouseEvent || window.event;
	if (!affichageMenuEnCours && !estMenuAffiche()) {
		var div = document.getElementById('main');
		var x = mouseEvent.clientX - div.offsetLeft;
		var y = mouseEvent.clientY - div.offsetTop;
		if (y > (div.offsetHeight*0.9)) {
				afficheMenu(3);
		}	
	}	
}	

function isNumber(n) {
	return !isNaN(parseFloat(n)) && isFinite(n);
}

function isValidCSSNumericValue(n) {
	return !isNaN(parseFloat(n));
}

function estMenuAffiche() {
	var menu = document.getElementById("menu");
	return "block" == menu.style.display;
}
	
function afficheMenu(sens) {
	var menu = document.getElementById("menu");
	affichageMenu = true;
		menu.style.display = "block";
		
	//} else {
		if (!isValidCSSNumericValue(menu.style.top)) {
			menu.style.top = menu.offsetTop;
		}
		if (!isValidCSSNumericValue(menu.style.height)) {
			menu.style.height = menu.offsetHeight;
		}
		menu.style.height = parseInt(menu.style.height) + sens;
		menu.style.top = parseInt(menu.style.top) - sens;
		if (sens > 0) {
			if (parseInt(menu.style.height) < 110) 
				setTimeout("afficheMenu(" + sens + ");", 50);
			else {
				affichageMenuEnCours = false;	
			}
		} else if (sens < 0) {
			if (parseInt(menu.style.height) > 0) 
				setTimeout("afficheMenu(" + sens + ");", 50);
			else {
				affichageMenuEnCours = false;	
				menu.style.display = "none";
			}
		}	
	//}
}
