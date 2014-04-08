/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdr;

import java.util.Scanner;
import java.util.StringTokenizer;

/**
 *
 * @author Administrateur
 */
public class NoeudRecuperation extends Noeud {
    
    public String nom;
    
    public String suite;
    
    public NoeudRecuperation(Scanner sc) {
        super(sc);
        while(sc.hasNextLine()) {
            StringTokenizer st = new StringTokenizer(sc.nextLine(), "=");
            String cle = st.nextToken();
            String valeur = st.nextToken();
            switch(cle) {
                case "nom":
                    this.nom = valeur;
                    break;
                case "suite":
                    this.suite = valeur;
                    break;    
            }
        }
        sc.close();
    }
    
    public String action(Joueur j) {
        j.besace.add(this.nom);
        System.out.println(j.prenom + ", vous récupérez l'objet : " + this.nom);
        return this.suite;
    }
    
}
