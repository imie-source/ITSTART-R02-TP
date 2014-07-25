<?php

	require_once("Mammifere.class.php");

	class EtreHumain extends Mammifere {
	
		public $nom;
		
		public function __construct($nom = NULL, $taille = NULL, $poids = NULL, $age = NULL, $sexe = NULL) {
			parent::__construct($taille, $poids, $age, $sexe);
			$this->nom = $nom;
		}
		
		private function marcher() {
			echo "Je marche (seul...)<br />";
		}
		
		private function parler($phrase) {
			echo "Je dois dire " . $phrase . "<br />";
		}
		
		public function rire() {
			echo "je me (théoreme de )gausse...<br />";
		}
		
		public function getSexe() {
			if (empty($this->sexe)) {
				return "inconnu";
			}	
			return strtolower($this->sexe) == "m" ? "masculin" : "f&eacute;minin";
		}	
		
		public function seDeplacer() {
			$this->marcher();
		}
		
		public function communiquer($phrase) {
			$this->parler($phrase);
		}
		
		public function __toString() {
			return $this->nom . " (" . $this->getAge() . ")";
		}
	}