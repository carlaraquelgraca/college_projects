/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class TijoloVerde extends Tijolo {

    int nColisoes;

    public TijoloVerde(Coordenadas p) {
        super(p);//incializa o constructor da classe principal
        nColisoes = 0;
    }

    public void agir(Arkanoid ar) {
        ar.aumentaPontuacao(pVerde);//aumenta a pontuacao em 50 pontos por cada colisao
        ar.duplaColisao(this);//destroi tijolo apos segunda colisao
    }

    public int getnColisoes() {
        return nColisoes;
    }

    public void setnColisoes(int nColisoes) {
        this.nColisoes = nColisoes;
    }
}
