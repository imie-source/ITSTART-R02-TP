/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdr;

import java.util.StringTokenizer;

/**
 *
 * @author Administrateur
 */
public class Choix {
    
    public String libelle;
    
    public String fichierCible;
    
    public Choix(String ligne) {
        StringTokenizer st = new StringTokenizer(ligne, ";");
        this.libelle = st.nextToken();
        this.fichierCible = st.nextToken();
    }
    
}
