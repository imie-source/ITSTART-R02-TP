function confJauge(w, h, tc) {
	var cj = document.getElementById('cJauge');
	var jauge = document.getElementById('jauge');
	var tj = document.getElementById('tJauge');
	jauge.style.width = w + 'px';
	cj.style.width = jauge.style.width;
	tj.style.width = jauge.style.width;
	jauge.style.height = h + 'px';
	cj.style.height = jauge.style.height;
	tj.style.height = jauge.style.height;
	tj.style.lineHeight = jauge.style.height;
	tj.style.color = tc;
	tj.style.fontSize = parseInt(h/5) + 'px';
}

function updateJauge(j) {
	var cj = document.getElementById('cJauge');
	var tj = document.getElementById('tJauge');	
	var pct = j.value;
	cj.style.height = (parseInt(jauge.style.height) * (1 - (pct/100))) + 'px';
	tj.innerHTML = pct + ' %';
}