/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdr;

import java.util.Vector;

/**
 *
 * @author Administrateur
 */
public class Joueur {
    
    public String prenom;
    
    public int nbPointsDeVie;
    
    public Vector besace;
    
    public Joueur(String prenom) {
        this.prenom = prenom;
        this.nbPointsDeVie = 20;
        this.besace = new Vector();
    } 
    
}
