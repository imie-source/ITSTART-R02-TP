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
public class NoeudDonation extends Noeud {
    
public String nom;
    
    public String suiteO;
    
    public String suiteN;
    
    public NoeudDonation(Scanner sc) {
        super(sc);
        while(sc.hasNextLine()) {
            StringTokenizer st = new StringTokenizer(sc.nextLine(), "=");
            String cle = st.nextToken();
            String valeur = st.nextToken();
            switch(cle) {
                case "nom":
                    this.nom = valeur;
                    break;
                case "suiteO":
                    this.suiteO = valeur;
                    break;    
                case "suiteN":
                    this.suiteN = valeur;
                    break;    
                    
            }
        }
        sc.close();
    }
    
    public String action(Joueur j) {
        if (j.besace.contains(this.nom)) {
            j.besace.remove(this.nom);
            System.out.println(j.prenom + ", vous donnez l'objet : " + this.nom);
            return this.suiteO;
        } else {
            System.out.println(j.prenom + ", vous ne possédez pas l'objet : " + this.nom);
            return this.suiteN;
        }    
    }    
    
}
