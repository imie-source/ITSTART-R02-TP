<?php

	require_once("Mammifere.class.php");

	class Cetace extends Mammifere {
	
		private function nager() {
			echo "Je nage (en eaux troubles...)<br />";
		}
		
		public function seDeplacer() {
			$this->nager();
		}
		private function chanter($phrase) {
			echo "Je chante " . $phrase . "<br />";
		}
		
		public function communiquer($phrase) {
			$this->chanter($phrase);
		}
		
		public function __toString() {
			return "C&eacute;tac&eacute; (" . $this->getAge() . ")";
		}
		
	}