/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class TijoloVermelho extends Tijolo {

    public TijoloVermelho(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid ar) {
        ar.setVizinhos(this);//destrói tijolos adjacentes
        ar.aumentaPontuacao(pDefault);//aumenta a pontuacao em 100 pontos
    }
}
