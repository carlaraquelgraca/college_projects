/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.io.Serializable;
import java.util.ArrayList;

/**
 *
 * @author Carla Raquel
 */
public class FabricaNiveis implements Constantes, Serializable {//cria níveis 

    public static ArrayList<Tijolo> tijolo;

    public static ArrayList<Tijolo> getNivel(int nivel) {
        ArrayList<Tijolo> tijolos = new ArrayList<Tijolo>();

        switch (nivel) {

            case 1:
                for (int i = 0; i < linhaTij; i++) {
                    for (int j = 0; j < colTij; j++) {

                        if (i == 0 && j == 0) {
                            tijolos.add(new TijoloAzul(new Coordenadas(j * tLargura, i * altura)));
                        } else {
                            if (i == 1 && j == 1) {
                                tijolos.add(new TijoloVerde(new Coordenadas(j * tLargura, i * altura)));
                            } else {
                                if (i == 2 && j == 2) {
                                    tijolos.add(new TijoloVermelho(new Coordenadas(j * tLargura, i * altura)));
                                } else {
                                    if (i == 3 && j ==8 ) {
                                        tijolos.add(new TijoloVermelho(new Coordenadas(j * tLargura, i * altura)));
                                    } else {
                                        tijolos.add(new TijoloBranco(new Coordenadas(j * tLargura, i * altura)));
                                    }
                                }
                            }
                        }
                    }
                }
                break;

            case 2:
                for (int i = 0; i < linhaTij; i++) {
                    for (int j = 0; j < colTij; j++) {

                        if (i == 3 && j == 1 || i == 3 && j == 7) {
                            tijolos.add(new TijoloAzul(new Coordenadas(j * tLargura, i * altura)));
                        } else {
                            if ((i == 2 && j == 2) || (i == 2 && j == 6)) {
                                tijolos.add(new TijoloVerde(new Coordenadas(j * tLargura, i * altura)));
                            } else {
                                if (i == 0 && j == 4) {
                                    tijolos.add(new TijoloVermelho(new Coordenadas(j * tLargura, i * altura)));
                                } else {
                                    if ((i == 1 && j == 3) || (i == 1 && j == 5)) {
                                        tijolos.add(new TijoloAmarelo(new Coordenadas(j * tLargura, i * altura)));
                                    } else {
                                        tijolos.add(new TijoloBranco(new Coordenadas(j * tLargura, i * altura)));
                                    }
                                }
                            }
                        }
                    }
                }
                break;

            case 3:
                for (int i = 0; i < linhaTij; i++) {
                    for (int j = 0; j < colTij; j++) {

                        if (((i == 0 || i == 3) && (j == 3 || j == 4 || j == 5)) || ((i == 2 || i == 1) && (j == 2 || j == 6))) {
                            tijolos.add(new TijoloVerde(new Coordenadas(j * tLargura, i * altura)));

                        } else {
                            if ((i == 1 && j == 4) || (i == 2 && j == 4)) {
                                tijolos.add(new TijoloAzul(new Coordenadas(j * tLargura, i * altura)));
                            } else {
                                if ((i == 2 && j == 3) || (i == 1 && j == 5)) {
                                    tijolos.add(new TijoloAmarelo(new Coordenadas(j * tLargura, i * altura)));
                                } else {
                                    tijolos.add(new TijoloBranco(new Coordenadas(j * tLargura, i * altura)));
                                }
                            }
                        }
                    }
                }

                break;
        }

        return tijolos;
    }
}
