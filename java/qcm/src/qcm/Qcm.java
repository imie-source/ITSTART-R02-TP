/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package qcm;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

import qcm.QuestionReponses;

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
    
    public static QuestionReponses getQRA(Vector t) {
        // générer un nombre aléatoire compris entre 0 et 
        //              nombre d'éléments-1 de t
        int ia = Qcm.random(0, t.size()-1);
        // Récupérer l'élément de cet indice
        QuestionReponses qra = (QuestionReponses)t.elementAt(ia);
        // Retirer l'élément de t
        t.removeElement(qra);
        // Renvoyer l'élément
        return qra;
    }
    
    public static int proposeLes3Reponses(QuestionReponses qr) {
        // Afficher aléatoirement les 3 réponses possibles
        Vector tabChoix = new Vector();
        int iBR = 0;
        tabChoix.add(qr.bonneReponse);
        tabChoix.add(qr.reponse2);
        tabChoix.add(qr.reponse3);
        for(int c = 0; c < 3; c++) {
            int ia = Qcm.random(0, tabChoix.size()-1);
            System.out.println("\t" + (c+1) + " : " + tabChoix.elementAt(ia));
            if (tabChoix.elementAt(ia).equals(qr.bonneReponse)) {
                iBR = c+1;
            }
            tabChoix.removeElementAt(ia);
        }        
        // renvoyer l'indice de la bonne réponse
        return iBR;
    }
    
    public static Vector lireQCM() {
        String fichier = "C:\\dev\\ITSTART-R02-TP\\java\\qcm\\build\\qcmchiffre.txt";
        Vector tab = new Vector();
        try {
            Scanner scanner = new Scanner(new File(fichier));
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String ligne = Qcm.chiffre(-5, line);
                StringTokenizer st = new StringTokenizer(ligne, ";");
                tab.add(new QuestionReponses(st.nextToken(), 
                                             st.nextToken(), 
                                             st.nextToken(), 
                                             st.nextToken()));
            }
            scanner.close();
        } catch (FileNotFoundException ex) {
            //Logger.getLogger(Qcm.class.getName()).log(Level.SEVERE, null, ex);
        }
        return tab;
    }
    
    public static int random(int bInf, int bSup) {
        Random r = new Random();
        return bInf + (Math.abs(r.nextInt()) % (bSup-bInf+1)); 
    }
    
    public static void jouer(Vector t, int nbQ) {
        for(int i = 0; i < nbQ; i++) {
            QuestionReponses qr = Qcm.getQRA(t);
            System.out.println(qr.question);
            int iBR = Qcm.proposeLes3Reponses(qr);
            Scanner sc = new Scanner(System.in);
            System.out.print("Quel est votre choix ? (1/2/3) ");
            String saisie = sc.nextLine();
            if (Integer.parseInt(saisie) == iBR) {
                System.out.println("Bonne réponse !");
            } else {
                System.out.println("Mauvaise réponse...");
            }
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
        Vector tabQR = Qcm.lireQCM();
        Qcm.jouer(tabQR, 3);
    }
    
}
