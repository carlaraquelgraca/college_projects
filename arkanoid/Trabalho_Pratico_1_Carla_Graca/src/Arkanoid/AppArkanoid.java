/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

/**
 *
 * @author Carla Raquel
 */
public class AppArkanoid {

    public static void main(String args[]) {

        ModeloArkanoid ob = new ModeloArkanoid(new Arkanoid(500, 600));//cria um novo modelo Arkanoid
        new vistaArkanoid(10, ob, 600, 700);//cria uma nova vista Arkanoid

    }
}
