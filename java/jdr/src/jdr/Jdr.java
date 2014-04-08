/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdr;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import jdr.NoeudTexte;

/**
 *
 * @author Administrateur
 */
public class Jdr {

    /**
     * Analyse le fichier passé en argument et renvoie un objet dont le type
     * dépend du contenu du fichier
     *
     * @param chemin Chemin du fichier à analyser
     * @return \Object
     */
    public static Noeud analyse(String chemin) {
        try {
            // J'ouvre en lecture le fichier passé en argument
            Scanner sc = new Scanner(new File(chemin));
            // Je lis la première ligne
            String type = sc.nextLine();
            // En fonction de la première ligne
            switch(type) {
                case "TEXTE":
                    return new NoeudTexte(sc);
                case "FIN":
                    return new NoeudFin(sc);
                case "RECUPERATION":
                    return new NoeudRecuperation(sc);
            }
        } catch(FileNotFoundException fnfe) {
            System.err.println(fnfe);
        }
        return null;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        String repertoireData = "";
        String fichierCourant = ""; 
        Joueur joueur = new Joueur("Serge");
        
        if (2 == args.length) {
            repertoireData = args[0];
            fichierCourant = args[1];
        } else {
            System.out.println("usage : <repdata> <fichierdépart>");
            System.exit(0);
        }

        while(!fichierCourant.equals("")) {
            Noeud noeud = Jdr.analyse(repertoireData + File.separator  + fichierCourant);
            fichierCourant = noeud.action(joueur);
        } 
        System.out.println("Le jeu est fini...");
    }
    
}
