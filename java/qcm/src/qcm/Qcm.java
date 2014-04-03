/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package qcm;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Administrateur
 */
public class Qcm {

    /**
     * Chiffre une chaîne de caractères avec un décalage (Algorithme de César)
     * 
     * @param cle Décalage de caractères
     * @param chaine Chaîne de caractères à chiffrer
     * @return string Chaîne de caractères chiffrée
     */
    public static String chiffre(int cle, String chaine) {
        String res = "";
        int decalage = (cle % 50)+1;
        for(int i = 0; i < chaine.length(); i++) {
            char c = chaine.charAt(i);
            c = (char)((int)c+decalage);
            res += c;
        }
        return res;
    }
    
    /**
     * Renvoie le contenu d'un fichier sous forme de chaîne de caractères
     * 
     * @param chemin Chemin du fichier à parcourir
     * @return Contenu sous forme de chaîne de caractères du fichier
     */
    public static String lireFichierClaire(String chemin) {
        String res = "";
        Scanner scanner;
        try {
            scanner = new Scanner(new File(chemin));
            // On boucle sur chaque champ detecté
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                res += line + "\n";
            }
            scanner.close();
        } catch (FileNotFoundException ex) {
            //Logger.getLogger(Qcm.class.getName()).log(Level.SEVERE, null, ex);
        }
        return res;
    }

    /**
     * Chiffre le contenu d'un fichier source dans un fichier cible
     * 
     * @param cheminSource Chemin du fichier source
     * @param cheminCible Chemin du fichier cible
     * @param cle Décalage des caractères
     * @return Vrai si le fichier cible a été créé, faux sinon
     */
    public static boolean chiffreFichier(String cheminSource, String cheminCible, int cle){
        Scanner scanner;
        PrintWriter ecriture;
        try {
            scanner = new Scanner(new File(cheminSource));
            ecriture = new PrintWriter(new File(cheminCible));
            while (scanner.hasNextLine()) {
                // line : chaîne "claire"
                String line = scanner.nextLine();
                // ligne : chaîne chiffrée
                String ligne = Qcm.chiffre(cle, line);
                ecriture.println(ligne);
            }
            scanner.close();
            ecriture.close();
            return true;
        } catch (FileNotFoundException ex) {
            return false;
        }    
    }
    
    public static void lireQCM() {
        String fichier = "C:\\dev\\ITSTART-R02-TP\\java\\qcm\\build\\qcmchiffre.txt";
        Scanner scanner;
        try {
            scanner = new Scanner(new File(fichier));
            int i = 1;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String ligne = Qcm.chiffre(-5, line);
                StringTokenizer st = new StringTokenizer(ligne, ";");
                System.out.println(i + " " + st.nextToken());
                i++;
            }
            scanner.close();
        } catch (FileNotFoundException ex) {
            //Logger.getLogger(Qcm.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //System.out.println("Serge : " + Qcm.chiffre(-5, "Serge"));
        //System.out.println("data.txt : " + Qcm.lireFichierClaire("C:\\dev\\ITSTART-R02-TP\\java\\qcm\\build\\data.txt"));
        /*if (Qcm.chiffreFichier("C:\\dev\\ITSTART-R02-TP\\java\\qcm\\build\\CGI",
                               "C:\\dev\\ITSTART-R02-TP\\java\\qcm\\build\\CGIchiffre",
                               3)) {
            System.out.println("Le fichier a bien été chiffré !");
        } else {
            System.out.println("Le fichier n'a pas été chiffré...");
        }*/
        Qcm.lireQCM();
    }
    
}
