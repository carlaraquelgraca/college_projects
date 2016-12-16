/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.awt.geom.Rectangle2D;
import java.io.Serializable;
import java.text.DecimalFormat;
import java.util.Random;

/**
 *
 * @author Carla Raquel
 */
public class Bola extends Rectangle2D.Double implements Serializable {

    private State estado;//objecto membro da classe que indica o estado da bola,se cola ou livre
    private double xxDir; //velocidade da bola em xx
    private double yyDir = 3; //velocidade da bola em y
    boolean cola = false;

    public boolean isCola() {
        return cola;
    }

    public void setCola(boolean cola) {
        this.cola = cola;
    }

    public State getEstado() {
        return estado;
    }

    public void setEstado(State estado) {
        this.estado = estado;
    }

    public Bola(Coordenadas c) { //constrói uma bola inscrita num rectangulo com determiandas coordenadas e altura e larguras iguais ao dobro do raiod a bola
        super(c.getX(), c.getY(), 12, 12);
        Random rgen = new Random(); //gera uma velocidade aleatória em xx entre valores de 1 e 2
        xxDir = 1 + rgen.nextInt(3);
        if (rgen.nextBoolean()) {
            xxDir = -xxDir;
        }
        estado = new BolaLivre(this);
    }

    public double getXXDir() { //obtém velocidade em xx
        return xxDir;
    }

    public double getYYDir() { //obtém velocidade em yy
        return yyDir;
    }

    public void setXXDir(double xxD) { //modifica velocidade em xx
        xxDir = xxD;

    }

    public void setYYDir(double yyD) { //modifica velocidade em yy
        yyDir = yyD;

    }

    public void moverLivre(Arkanoid ar) {
        x += xxDir; //modifica o xx e yy da bola conforme nova direcção
        y += yyDir;

        if (x + width > ar.getDimx()) { 
            x = ar.getDimx() - width;
        } else if (x < 0) { 
            x = 0;
        }


        if (y < 0) { 
            y = 0;
        }
    }

    public void moverCola(Arkanoid ar) { // colcoa a bola no centro da raquete como se tivesse cola
        x = ar.getR().x + ar.getR().width / 2 - width / 2;
        y = ar.getR().y - height;
    }

    public void mover(Arkanoid ar) {
        estado.mover(ar);
    }

    public void setDireccao(double alfa) { //modifica a direcção da bola
        double modulo = Math.sqrt(xxDir * xxDir + yyDir * yyDir);
        xxDir = Math.cos(alfa) * modulo;
        yyDir = Math.sin(alfa) * modulo;
    }

    public void setVelocidade(double v) { // modifica  a velocidade da bola
        double alfa = Math.atan2(yyDir, xxDir);
        xxDir = Math.cos(alfa) * v;
        yyDir = Math.sin(alfa) * v;
    }

      public double getVelocidade() { // obtém  a velocidade da bola
            double velocidade;
            velocidade = Math.sqrt((xxDir*xxDir) + (yyDir*yyDir));
          return velocidade;
    }


    public double getAlfa() { //obtém o angulo alfa de reflexão da bola
        return Math.atan2(yyDir, xxDir);
    }

    public void reflecteEsquerdaDireita() {//reflecte a bola e muda direcção conforme o angulo de reflexão

        setDireccao(Math.PI - getAlfa());
    }

    public void reflecteCimaBaixo() { //reflecte a bola e muda de direcção,invertendo-a
        setDireccao(-getAlfa());
    }
}
