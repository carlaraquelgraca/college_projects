/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.io.Serializable;

/**
 *
 * @author Carla Raquel
 */
public class FabricaTijolo implements Constantes, Serializable {//cria os tijolos

    public static Tijolo getTijolo(String s, int j, int i) {
        if (s.equals(tAzul)) {
            return new TijoloAzul(new Coordenadas(j* tLargura, i* altura));
        } else if (s.equals(tVerde)) {
            return new TijoloVerde(new Coordenadas(j * tLargura, i * altura));
        } else if (s.equals(tVermelho)) {
            return new TijoloVermelho(new Coordenadas(j * tLargura, i * altura));
        } else if (s.equals(tAmarelo)) {
            return new TijoloAmarelo(new Coordenadas(j * tLargura, i * altura));
        } else {
            return new TijoloBranco(new Coordenadas(j * tLargura, i * altura));
        }
    }
}
