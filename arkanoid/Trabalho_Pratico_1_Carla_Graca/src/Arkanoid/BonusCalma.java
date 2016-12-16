/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class BonusCalma extends Bonus {

    public BonusCalma(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid ar) {//coloca a velocidade a metade
      ar.getB().setVelocidade(ar.getB().getVelocidade()/2);
    }
}
