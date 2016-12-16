/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.awt.Color;
import java.awt.geom.Rectangle2D;
import java.io.Serializable;

/**
 *
 * @author Carla Raquel
 */
public abstract class Tijolo extends Rectangle2D.Double implements Constantes , Serializable{

    private boolean visivel;

    public Tijolo(Coordenadas p) {//constrói um tijolo numa determinada posição com uma certa altura e largura
        super(p.getX(), p.getY(), tLargura, altura);
        visivel = true;
    }

    public void setVisivel(boolean visivel) {//define a visibilidade do tijolo
        this.visivel = visivel;
    }

    public boolean isVisivel() {//verifica se um tijoloe stá visível
        return visivel;
    }

    public abstract void agir(Arkanoid ar);//função que manda u tijolo agir redefinida nas funções membro das classes derivadasS
}
