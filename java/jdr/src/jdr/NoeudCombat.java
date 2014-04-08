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
public class NoeudCombat extends Noeud {
        
/*objet+=Epée;1
objet+=Tiare;2
objet+=Pistolet;5
objetA=Arc*/
    
    public String adversaires;
    
    public String suiteVictoire;
    
    public String suiteDefaite;
    
    public String suiteEgalite = "";
    
    public int nbPdVDefaite = 0;
    
    public int nbPdVVictoire = 0;
    
    public int nbPdVEgalite = 0;
    
    public Vector tabObjetsPos;
    
    public Vector tabObjetsNeg;
    
    public Vector tabObjetsAdversaires;
    
    public NoeudCombat(Scanner sc) {
        super(sc);
        this.tabObjetsPos = new Vector();
        this.tabObjetsNeg = new Vector();
        this.tabObjetsAdversaires = new Vector();
        while(sc.hasNextLine()) {
            StringTokenizer st = new StringTokenizer(sc.nextLine(), "=");
            String cle = st.nextToken();
            String valeur = st.nextToken();
            switch(cle) {
                case "adversaires":
                    this.adversaires = valeur;
                    break;
                case "victoire":
                    this.suiteVictoire = valeur;
                    break;
                case "defaite":
                    this.suiteDefaite = valeur;
                    break;
                case "egalite":
                    this.suiteEgalite = valeur;
                    break;
                case "nbpvV":
                    this.nbPdVVictoire = Integer.parseInt(valeur);
                    break;
                case "nbpvD":
                    this.nbPdVDefaite = Integer.parseInt(valeur);
                    break;
                case "nbpvE":
                    this.nbPdVEgalite = Integer.parseInt(valeur);
                    break;
                case "objet":
                    ObjetCombat oc = new ObjetCombat(valeur);
                    if (oc.force >= 0) {
                        this.tabObjetsPos.add(oc);
                    } else {
                        this.tabObjetsNeg.add(oc);
                    }
                    break;
                case "objetA":
                    this.tabObjetsAdversaires.add(valeur);
                    break;
            }
        }
        sc.close();
    }
    
    public int gagnant(int jdd, boolean egalite) {
      if (egalite) {
          // égalité potentielle
          if (jdd < 5) {
              return 0; // je perds
          } else {
              if (jdd > 8) {
                  return 2; // je gagne
              } else {
                  return 1; // égalité
              }
          }
      }  else {
          // uniquement victoire / défaite
          if (jdd < 7) {
              return 0; // je perds
          }    
          return 2; // je gagne
      }
    }
    
    public String action(Joueur j) {
        int jdd = random(1, 12);
        for(int i = 0; i < this.tabObjetsPos.size(); i++) {
            ObjetCombat oc = (ObjetCombat)this.tabObjetsPos.elementAt(i);
            if (j.besace.contains(oc.nom)) {
                jdd += oc.force;
            }    
        }
        for(int i = 0; i < this.tabObjetsNeg.size(); i++) {
            ObjetCombat oc = (ObjetCombat)this.tabObjetsNeg.elementAt(i);
            if (j.besace.contains(oc.nom)) {
                jdd += oc.force;
            }    
        }
        int res = this.gagnant(jdd, !this.suiteEgalite.equals(""));
        switch(res) {
            case 0: // j'ai perdu
                System.out.println("Malheureusement, vous perdez le combat (" + jdd + "/12)");
                return this.suiteDefaite;
            case 1: // égalité
                System.out.println("Vous êtes de force égale (" + jdd + "/12)");
                return this.suiteEgalite;
            case 2: // victoire
                System.out.println("Heureusement, vous gagnez le combat (" + jdd + "/12)");
                return this.suiteVictoire;
        }
        return "";
    }
    
}
