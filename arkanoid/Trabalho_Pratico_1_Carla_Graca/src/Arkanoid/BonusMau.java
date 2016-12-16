/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class BonusMau extends Bonus {

    public BonusMau(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid a) {//enconlhe a raquete
        a.getR().encolheRaquete();
    }
}