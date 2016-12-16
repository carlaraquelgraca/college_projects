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
public class Raquete extends Rectangle2D.Double implements Serializable{

    public Raquete(Coordenadas p, int largura, int altura) {//constrói a raquete dadas as sua posição na tela,largura e altura
        super(p.getX(), p.getY(), largura, altura);

    }

    public void moveRaquete(int x) {//move a raquete para uma nova posição nos eixo dos xx
        this.x = x;
    }

    public void expandeRaquete() {//aumenta a raquete
        this.width = this.width * 2;
    }

    public void encolheRaquete() {//diminui a raquete
        this.width = (this.width *2)/3;
    }
}
