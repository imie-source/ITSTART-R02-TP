/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdr;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Administrateur
 */
public class Noeud {
    
    public Noeud(Scanner sc) {
        
    }
    
    public String action(Joueur j) {
        return "";
    }
    
    public static int random(int bInf, int bSup) {
        Random r = new Random();
        return bInf + (Math.abs(r.nextInt()) % (bSup-bInf+1)); 
    }    
    
}
