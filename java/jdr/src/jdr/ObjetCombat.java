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
public class ObjetCombat {
    
    public String nom;
    
    public int force;
    
    public ObjetCombat(String ligne) {
        StringTokenizer st = new StringTokenizer(ligne, ";");
        this.nom = st.nextToken();
        this.force = Integer.parseInt(st.nextToken());
    }
    
}
