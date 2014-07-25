<?php

	class Cetace {
	
		public $taille;
		private $poids;
		public $age;
		public $sexe;
		
		public function __construct($taille = NULL, $poids = NULL, $age = NULL, $sexe = NULL) {
			$this->taille = $taille;
			$this->setPoids($poids);
			$this->age = $age;
			$this->sexe = $sexe;
		}
		
		public function nager() {
			echo "Je nage (en eaux troubles...)<br />";
		}
		
		public function chanter($phrase) {
			echo "Je chante " . $phrase . "<br />";
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
			return strtolower($this->sexe) == "m" ? "m&acirc;le" : "fem&egrave;le";
		}	
		
		public function __toString() {
			return "C&eacute;tac&eacute; (" . $this->getAge() . ")";
		}
	}