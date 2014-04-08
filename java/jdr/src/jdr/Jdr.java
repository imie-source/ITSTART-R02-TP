/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdr;

import java.io.File;

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
    public static Object analyse(String chemin) {
        return null;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        String repertoireData;
        String fichierCourant; 
        
        if (2 == args.length) {
            repertoireData = args[0];
            fichierCourant = args[1];
        } else {
            System.out.println("usage : <repdata> <fichierdépart>");
            System.exit(0);
        }

        while(true) {
            Object noeud = Jdr.analyse(repertoireData + File.pathSeparator  + fichierCourant);
            fichierCourant = noeud.action();
        }    
    }
    
}
