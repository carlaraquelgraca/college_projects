/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class BonusVida extends Bonus {

    public BonusVida(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid ar) {//aumenta numero de vidas
        ar.setnVidas(ar.getnVidas()+1);
    }
}
