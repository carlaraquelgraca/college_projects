/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.io.Serializable;

/**
 *
 * @author Carla Raquel
 */
public abstract class State implements Serializable{

    private Bola bola;

    public State(Bola b) {
        bola = b;
    }

    public Bola getBola() {
        return bola;
    }

    public void setBola(Bola bola) {
        this.bola = bola;
    }

    public void mover(Arkanoid ar) {
    }
}
