/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Observable;

/**
 *
 * @author Carla Raquel
 */
public class ModeloArkanoid extends Observable implements Serializable {//o modelo Arkanoid será observado pela sua respectiva vista

    private Arkanoid ark;

    public ModeloArkanoid(Arkanoid a) {//constrói o modelo do Arkanoid e notifica os seus observadores de alterações
        ark = a;
        setChanged();
        notifyObservers();
    }

    public Bola getB() {
        return ark.getB();
    }

    public Raquete getR() {
        return ark.getR();
    }

    public ArrayList<Tijolo> getT() {
        return ark.getT();
    }

    public void mover() {//move a bola e notifica os seus observadores(Vista) que ocorreram alterações no modelo
        ark.moverBola();
        ark.moverBonus(ark.getR());

        setChanged();
        notifyObservers();
    }

    public double getDimx() {//devolve as dimensoes em x do ecrã de jogo
        return ark.getDimx();
    }

    public ArrayList<Bonus> getBonus() { //devolve o array de tijolos
        return ark.getBonus();
    }

    public double getDimy() {//devolve as dimensoes em y do ecrã de jogo
        return ark.getDimy();
    }

    public double getPontuacao() {//devolve a pontuação actual
        return ark.getPontuacao();
    }

    public void lancaBonus(Tijolo t) {//lança um bónus
        ark.lancaBonus(t);
    }

    public State getEstado() {//obtém o estado da bola
        return ark.getB().getEstado();
    }

    public void libertaBola() {//solta a bola
        ark.libertaBola();
        setChanged();
        notifyObservers();
    }

    public boolean isPassouNivel() {//verifica se passoud e nível
        return ark.isPassouNivel();
    }

    public boolean isPerdeJogo() {//verifica se perdeu o jogo
        return ark.isPerdeJogo();
    }

    public boolean isPerdeVida() {//verifica se perdeu uma vida
        return ark.isPerdeVida();
    }

    public int getNivel() {//devolve o nível actual
        return ark.getNivel();
    }

    public void iniciaJogo() {//inicia o jogo e notifica os seus observadores(Vista) que ocorreram alterações no modelo
        ark.iniciaJogo();

        setChanged();
        notifyObservers();
    }

    public boolean isBonusApanhado() {//verifica se existe algum bónus apanhado
        return ark.isBonusApanhado();
    }

    public int getnVidas() {// obtém numero de vidas
        return ark.getnVidas();
    }

    public Bonus getBn() {//obtém bónus
        return ark.getBn();
    }

    public double getVelocidade() {//obtém a velocidade actual da bola
        return ark.getB().getVelocidade();

    }

    public void salvaJogo() {//guarda o jogo
        ark.salvaJogo();
    }

    public Arkanoid carregaJogo() {//carrega o jogo guardado
        return ark.carregaJogo();
    }

    public void moveRaquete(int pos) {//move a raquete e notifica os seus observadores(Vista) que ocorreram alterações no modelo
        ark.moveRaquete(pos);

        setChanged();
        notifyObservers();
    }
}
