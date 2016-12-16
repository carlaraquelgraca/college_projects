/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class BolaCola extends State {

    public BolaCola(Bola b) {
        super(b);//chama constructor da classe mae e inicializa-o com uma bola
    }

    public void mover(Arkanoid ar) {
        getBola().moverCola(ar);//indica para a bola mover-se com cola

    }
}
