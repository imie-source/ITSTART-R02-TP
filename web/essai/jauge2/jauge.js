function confJauge(w, h, bc, fc, tc) {
	var cj = document.getElementById('cJauge');
	var jauge = document.getElementById('jauge');
	var tj = document.getElementById('tJauge');
	jauge.style.width = w + 'px';
	tj.style.width = jauge.style.width;
	jauge.style.height = h + 'px';
	cj.style.height = jauge.style.height;
	tj.style.height = jauge.style.height;
	tj.style.lineHeight = jauge.style.height;
	jauge.style.backgroundColor = bc;
	cj.style.backgroundColor = fc;
	tj.style.color = tc;
}

function setPct(pct) {
	var cj = document.getElementById('cJauge');
	var jauge = document.getElementById('jauge');
	var tj = document.getElementById('tJauge');
	/*for(k in cj) {
		console.log(k + "=>" + cj[k]);
	}*/	
	var w = jauge.offsetWidth;
	cj.style.width = (w*pct/100) + 'px';
	tj.innerHTML = pct + ' %';
}