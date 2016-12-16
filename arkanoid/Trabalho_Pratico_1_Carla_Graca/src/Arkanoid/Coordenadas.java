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
public class Coordenadas implements Serializable {

    private int x;
    private int y;

    Coordenadas(int xx, int yy) {
        x = xx;
        y = yy;
    }

    //funções get
    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    //funções set
    public void setX(int xx) {
        x = xx;
    }

    public void setY(int yy) {
        y = yy;
    }
}
