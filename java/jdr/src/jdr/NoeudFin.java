/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdr;

import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

/**
 *
 * @author Administrateur
 */
public class NoeudFin extends Noeud {
    
    public String texte;
    
    public NoeudFin(Scanner sc) {
        super(sc);
        while(sc.hasNextLine()) {
            StringTokenizer st = new StringTokenizer(sc.nextLine(), "=");
            String cle = st.nextToken();
            String valeur = st.nextToken();
            switch(cle) {
                case "texte":
                    this.texte = valeur;
                    break;
            }
        }
        sc.close();
    }
    
    public String action(Joueur j) {
        // Afficher le texte
        System.out.println(this.texte);
        return "";
    }
    
}
