/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;
import javax.swing.Timer;

/**
 *
 * @author morphes
 */
public class Tempo implements Serializable{

    private ModeloArkanoid modelo;
    private Timer timer;

    /** Creates a new instance of Tempo */
    public Tempo(ModeloArkanoid modelo, int ms) {
        this.modelo = modelo;
        criarTimer(ms);
    }

    public synchronized void criarTimer(int ms) {

        timer = new Timer(ms, new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                modelo.mover();
                if (modelo.isPassouNivel()|| modelo.isPerdeJogo() || modelo.isPerdeVida()) {
                    pararTimer();
                }
            }
        });

        timer.setInitialDelay(0);
        timer.setCoalesce(true);
//        timer.start();
    }

    // reinicia o timer
    public synchronized void continuarTimer() {

        if (!timer.isRunning()) {
            timer.start();
        }
    }

    // Para o timer
    public synchronized void pararTimer() {

        if (timer.isRunning()) {
            timer.stop();
        }
    }
}
