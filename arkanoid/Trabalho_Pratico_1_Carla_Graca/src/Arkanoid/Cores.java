/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.awt.Color;
import java.io.Serializable;

/**
 *
 * @author morphes
 */
public class Cores implements Serializable{

    public static Color getCor(Tijolo t) {//associa as cores do tijolo com uma instancia tijolo
        if (t instanceof TijoloAzul) {
            return Color.BLUE;
        } else if (t instanceof TijoloVerde) {
            return Color.GREEN;
        } else if (t instanceof TijoloVermelho) {
            return Color.RED;
        } else if (t instanceof TijoloAmarelo) {
            return Color.YELLOW;
        }
        return Color.WHITE;
    }
}
