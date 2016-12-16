/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class TijoloAmarelo extends Tijolo implements Constantes {

    public TijoloAmarelo(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid ar) {
        ar.aumentaPontuacao(pAmarelo);//aumenta em 150 pontos a pontuacao
    }
}
