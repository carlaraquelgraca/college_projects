/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class BonusCola extends Bonus {

    public BonusCola(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid ar) {//cola a bola à raquete
        ar.getB().setCola(true);
        ar.getB().setEstado(new BolaCola(ar.getB()));
    }
}
