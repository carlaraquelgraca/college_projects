/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class BolaLivre extends State {

    public BolaLivre(Bola b) {//chama constructor da classe mae e inicializa-o com uma bola
        super(b);
    }

    public void mover(Arkanoid ar) {//indica para a bola mover-se livremente
        getBola().moverLivre(ar);

    }
}
