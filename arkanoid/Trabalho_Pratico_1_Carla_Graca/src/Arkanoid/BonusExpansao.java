/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class BonusExpansao extends Bonus {

    public BonusExpansao(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid a) {//expande a raquete
        a.getR().expandeRaquete();
    }
}
