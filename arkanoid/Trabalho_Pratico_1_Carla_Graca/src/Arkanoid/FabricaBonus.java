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
public class FabricaBonus implements Serializable{

    public static Bonus getBonus(int n, Tijolo t) {//cria bónus gerado aleatoriamente

        if (n == 1) {
            return new BonusCola(new Coordenadas((int) t.x, (int) t.y));


        } else if (n == 2) {
            return new BonusVida(new Coordenadas((int) t.x, (int) t.y));


        } else if (n == 3) {
            return new BonusCalma(new Coordenadas((int) t.x, (int) t.y));

        } else if (n == 4){
            return new BonusExpansao(new Coordenadas((int) t.x, (int) t.y));
        }
         else
             return new BonusMau(new Coordenadas((int) t.x, (int) t.y));
    }
}
