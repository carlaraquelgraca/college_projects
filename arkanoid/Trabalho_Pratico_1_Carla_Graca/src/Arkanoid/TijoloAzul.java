/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class TijoloAzul extends Tijolo {

    Bonus b;

    public TijoloAzul(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid ar) {
        ar.aumentaPontuacao(pDefault);//aumenta a pontuacao em 100 pontos
        ar.lancaBonus(this);//lanca um bonus
    }
}
