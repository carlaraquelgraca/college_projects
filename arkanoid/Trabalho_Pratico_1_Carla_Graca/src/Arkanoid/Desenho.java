/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.io.Serializable;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;

/**
 *
 * @author morphes
 */
public class Desenho extends JPanel implements Constantes, Serializable {

    private ModeloArkanoid ar; //contém o Modelo Arkanoid como membro

    public Desenho(ModeloArkanoid ar) { //recebe o Modelo do Arkanoid,modificando as dimensões e cor da tel
        this.ar = ar;
        setBackground(Color.BLACK);
        setPreferredSize(new Dimension((int) ar.getDimx(), (int) ar.getDimy()));
        setBorder(new LineBorder(Color.BLACK));
    }

    @Override
    public void paintComponent(Graphics g) { //pinta na tela uma bola,um conjunto de tijolos e uma raquete
        super.paintComponent(g);

        Bola bola = ar.getB();
        ArrayList<Tijolo> t = ar.getT();
        Raquete r = ar.getR();
        Tijolo tij;
        int nTijVisivel = 0;
        ArrayList<Bonus> b = ar.getBonus();
        int vidas;


        g.setColor(Color.WHITE);
        for (int i = 0; i < t.size(); i++)//prenche os tijolos com cor
        {
            tij = t.get(i);
            g.setColor(Cores.getCor(tij));
            if (t.get(i).isVisivel()) {
                g.fillRect((int) tij.x, (int) tij.y, (int) tij.width, (int) tij.height);
            }
        }

        g.setColor(Color.BLACK);
        for (int i = 0; i < t.size(); i++) {
            tij = t.get(i);     //delimita os tijolos para não parecer uma mancha branca
            if (t.get(i).isVisivel()) { //se a bola não bateu ainda no tijolo,desenha-o
                g.drawRect((int) tij.x, (int) tij.y, (int) tij.width, (int) tij.height);
            }
        }


        for (int i = 0; i < b.size(); i++) {
            Bonus bi = b.get(i);     //desenha bonus conforme o tipo
            if (bi instanceof BonusCalma) {
                g.setColor(Color.red);
                System.out.println(bi.getClass().getName());
            } else if (bi instanceof BonusCola) {
                g.setColor(Color.PINK);

            } else if (bi instanceof BonusExpansao) {
                g.setColor(Color.ORANGE);


            } else if (bi instanceof BonusVida) {
                g.setColor(Color.CYAN);

            } else {
                g.setColor(Color.DARK_GRAY);
            }
            g.fillOval((int) bi.x, (int) bi.y, (int) bi.width, (int) bi.height);

        }

        if (ar.isBonusApanhado()) {//coloca a cor nos bónus conforme o tipo de bónus apanhado
            if (ar.getBn() instanceof BonusCalma) {
                g.setColor(Color.red);
            } else if (ar.getBn() instanceof BonusCola) {
                g.setColor(Color.PINK);
            } else if (ar.getBn() instanceof BonusExpansao) {
                g.setColor(Color.ORANGE);
            } else if (ar.getBn() instanceof BonusVida) {
                g.setColor(Color.CYAN);
            } else if (ar.getBn() instanceof BonusMau) {
                g.setColor(Color.DARK_GRAY);
            }

        } else {
            g.setColor(Color.YELLOW); //dá cor à raquete numa determinada posição
        }
        g.fillRect((int) r.x, (int) r.y, (int) r.width, (int) r.height);


        g.setColor(Color.CYAN); //dá cor à bola numa determinada posição
        g.fillOval((int) bola.x, (int) bola.y, (int) bola.width, (int) bola.height);
        
        g.drawString("Life: " + ar.getnVidas(), (int) ar.getDimx() / 2 - 245, (int) ar.getDimy() - 25);
        g.drawString("Score: " + ar.getPontuacao(), (int) ar.getDimx() / 2 - 180, (int) ar.getDimy() - 25);
        g.drawString("Level: " + ar.getNivel(), (int) ar.getDimx() / 2 - 100, (int) ar.getDimy() - 25);
        g.drawString("Velocity: " + ar.getVelocidade(), (int) ar.getDimx() / 2 - 20, (int) ar.getDimy() - 25);

        if (ar.isPerdeJogo()) {

            g.drawString("Game Over!Click no botão para começar de novo!", (int) ar.getDimx() / 2 - centroString, (int) ar.getDimy() / 2);

        } else if (ar.isPerdeVida()) {

            g.drawString("Perdeu uma vida!Ja so tem " + ar.getnVidas() + " vidas", (int) ar.getDimx() / 2 - centroString, (int) ar.getDimy() / 2);
        } else if (ar.isPassouNivel()) {
            g.drawString("Parabéns,Passou de Nível!Prima Iniciar para passar ao nivel seguinte", (int) ar.getDimx() / 2 - centroString, (int) ar.getDimy() / 2);
        } else if (ar.getNivel() == nivelMaximo) {
            g.drawString("Parabéns,Ganhou o Jogo!Prima Iniciar para recomeçar o jogo do inicio", (int) ar.getDimx() / 2 - centroString, (int) ar.getDimy() / 2);
        }

    }
}
