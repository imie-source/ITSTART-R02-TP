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
public class NoeudTexte extends Noeud {
    
    public String texte;
    
    public Vector tabChoix;
    
    public NoeudTexte(Scanner sc) {
        super(sc);
        this.tabChoix = new Vector();
        while(sc.hasNextLine()) {
            StringTokenizer st = new StringTokenizer(sc.nextLine(), "=");
            String cle = st.nextToken();
            String valeur = st.nextToken();
            switch(cle) {
                case "texte":
                    this.texte = valeur;
                    break;
                case "choix":
                    this.tabChoix.add(new Choix(valeur));
                    break;
            }
        }
        sc.close();
    }
    
    public String action(Joueur j) {
        // Afficher le texte
        System.out.println(this.texte);
        // Proposer les choix
        int lechoix = 0;
        while (0 == lechoix) {
            System.out.println("\nQue souhaitez-vous faire ?");
            System.out.println("\t0: Voir le contenu de ma besace");
            for(int i = 0; i < tabChoix.size(); i++) {
                Choix c = (Choix)tabChoix.elementAt(i);
                System.out.println("\t" + (i+1) + ": " + c.libelle);
            }
            Scanner sc = new Scanner(System.in);
            String saisie = sc.nextLine();
            lechoix  = Integer.parseInt(saisie);
            if (0 == lechoix) {
                j.afficheBesace();
            } else {
                Choix c = (Choix)tabChoix.elementAt(lechoix-1);
                return c.fichierCible;
            }
        }
        return "";
    }
    
}
