/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.awt.geom.Rectangle2D;
import java.io.Serializable;

/**
 *
 * @author Carla Raquel
 */
public abstract class Bonus extends Rectangle2D.Double implements Constantes,Serializable {

    public Bonus(Coordenadas p) {
        super(p.getX(), p.getY(), bLargura, bAltura);//incializa a classe mae Rectangle2D com dimensoes
    }

    public void mover(Arkanoid ar) {//move o bonus
        y += 2;

    }

    public abstract void agir(Arkanoid ar);//manda o bonus agir consoante o tipod e bónus redefinido nas classes derivadas
}
