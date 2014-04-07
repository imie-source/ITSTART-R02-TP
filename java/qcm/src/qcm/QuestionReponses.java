/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package qcm;

/**
 *
 * @author Administrateur
 */
public class QuestionReponses {
    
    public String question;
    
    public String bonneReponse;
    
    public String reponse2;
    
    public String reponse3;
    
    public QuestionReponses(String q, String br, String r2, String r3) {
        this.question = q;
        this.bonneReponse = br;
        this.reponse2 = r2;
        this.reponse3 = r3;
    }
    
}
