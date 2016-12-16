/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class TijoloBranco extends Tijolo {

    public TijoloBranco(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
    }

    public void agir(Arkanoid ar) {
        ar.aumentaPontuacao(pDefault);//aumenta a pontuacao em 100 pontos
    }
}
