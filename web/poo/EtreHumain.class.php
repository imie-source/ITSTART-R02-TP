<?php

	class EtreHumain {
	
		public $taille;
		private $poids;
		public $age;
		public $sexe;
		public $nom;
		
		public function __construct($nom = NULL, $taille = NULL, $poids = NULL, $age = NULL, $sexe = NULL) {
			$this->nom = $nom;
			$this->taille = $taille;
			$this->setPoids($poids);
			$this->age = $age;
			$this->sexe = $sexe;
		}
		
		public function marcher() {
			echo "Je marche (seul...)<br />";
		}
		
		public function parler($phrase) {
			echo "Je dois dire " . $phrase . "<br />";
		}
		
		public function rire() {
			echo "je me (théoreme de )gausse...<br />";
		}
		
		public function getPoids() {
			//$this->parler("Je vais te donner mon poids : ");
			if (empty($this->poids)) {
				return "inconnu";
			}	
			return $this->poids . "kg";
		}
		
		public function setPoids($p) {
			if (is_numeric($p)) 
				$this->poids = $p;
		}
		
		public function getTaille() {
			if (empty($this->taille)) {	
				return "inconnue";
			}	
			return $this->taille . "m";
		}
		
		public function getAge() {
			if (empty($this->age)) {
				return "inconnu";
			}	
			return $this->age . "ans";
		}

		public function getSexe() {
			if (empty($this->sexe)) {
				return "inconnu";
			}	
			return strtolower($this->sexe) == "m" ? "masculin" : "f&eacute;minin";
		}	
		
		public function __toString() {
			return $this->nom . " (" . $this->getAge() . ")";
		}
	}