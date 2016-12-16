/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;

/**
 *
 * @author Carla Raquel
 */
public class Arkanoid implements Constantes, Serializable {

    private Bola b; //contém uma Bola como membro
    private Raquete r; //contém uma Raquete como membro
    private ArrayList<Tijolo> t; //contém um array de tijolos como membro
    private double dimx, dimy;//contém uma dada dimensão
    private int pontuacao;
    private ArrayList<Bonus> bonus = new ArrayList<Bonus>();
    private boolean passouNivel;
    private boolean perdeJogo;
    private int nivel;
    private int nVidas;
    private boolean bonusApanhado;
    private Bonus bn;
    private boolean perdeVida;

    public Arkanoid(double dx, double dy) { //constructor que inicializa o Arkanoid com determinadas dimensoes e inicia o jogo
        dimx = dx;
        dimy = dy;
        nivel = 2;
        nVidas = 1;
        perdeVida = false;
        passouNivel = false;
        perdeJogo = false;
        pontuacao = 0;
        iniciaJogo();
    }

    public void iniciaJogo() { //cria uma Bola,uma Raquete e um conjunto de tijolos numa determinada posição da frame
        if (nivel == 1 && !perdeVida) {
            pontuacao = 0;
        }
        perdeVida = false;
        passouNivel = false;
        perdeJogo = false;
        b = new Bola(new Coordenadas((int) dimx / 2 - raio, (int) dimy / 2 - raio));
        r = new Raquete(new Coordenadas(100, 500), rLargura, altura);
        t = FabricaNiveis.getNivel(nivel);

    }

    public boolean isPerdeVida() {//verifica se perdeu nivel
        return perdeVida;
    }

    public void setPerdeVida(boolean perdeVida) {//modifica o estado da perda de vida
        this.perdeVida = perdeVida;
    }

    public int getNivel() {//obtém nivel actual
        return nivel;
    }

    public void salvaJogo() {//guarda o estado actual do jogo
        try {


            FileOutputStream fileOut = new FileOutputStream("Arkanoid.ser");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);

            out.writeObject(this);

            out.close();
            fileOut.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Arkanoid carregaJogo() {//carrega um Jogo salvo anteriormente
        Arkanoid ar = null;

        try {


            FileInputStream fileIn = new FileInputStream("Arkanoid.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);


            ar = (Arkanoid) in.readObject();


            in.close();
            fileIn.close();

        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }


        return ar;
    }

    public boolean isPerdeJogo() {//verifica se perdeu o jogo
        return perdeJogo;
    }

    public void setPerdeJogo(boolean perdeJogo) {//modifica estadod a perda de jogo
        this.perdeJogo = perdeJogo;
    }

    public Bonus getBn() {//obtém bónus
        return bn;
    }

    public void setBn(Bonus bn) {//modifica bonus
        this.bn = bn;
    }

    public boolean isBonusApanhado() {//verifica se um bonus foi apanhado
        return bonusApanhado;
    }

    public void setBonusApanhado(boolean bonusApanhado) {//modifica o estado do bonus
        this.bonusApanhado = bonusApanhado;
    }

    public int getnVidas() {//obtém numero de vidas actual
        return nVidas;
    }

    public void setnVidas(int nVidas) {//modifica o numero de vidas
        this.nVidas = nVidas;
    }

    public void setNivel(int nivel) {//modifica o nivel
        this.nivel = nivel;
    }

    public boolean isPassouNivel() {//verifica se passoude  nivel
        return passouNivel;
    }

    public void setPassouNivel(boolean passouNivel) {
        this.passouNivel = passouNivel;
    }

    public int getPontuacao() {//obtém pontuacao actual
        return pontuacao;


    }

    public void setPontuacao(int pontuacao) {//modifica pontuaçãoa ctual
        this.pontuacao = pontuacao;


    }

    public Bola getB() {//devolve uma Bola
        return b;


    }

    public Raquete getR() {//devolve uma raquete
        return r;


    }

    public ArrayList<Tijolo> getT() { //devolve o array de tijolos
        return t;


    }

    public ArrayList<Bonus> getBonus() { //devolve o array de tijolos
        return bonus;
    }

    public void ganha() {//passou de nivel ou se ganhou jogo volta ao principio
        if (nivel < nivelMaximo) {
            nivel++;
            passouNivel = true;
            nVidas = 1;
            bonus.removeAll(bonus);
            bonusApanhado = false;
            bn = null;
        } else {
            nivel = 1;
        }

    }

    public void perdeu() {//perdeu o jogo
        nivel = 1;
        perdeJogo = true;
        pontuacao = 0;
        nVidas = 1;
        bonus.removeAll(bonus);
        bonusApanhado = false;
        bn = null;

    }

    public void libertaBola() {//descola a bola
        b.setCola(false);
        b.setEstado(new BolaLivre(b));
    }

    public void moverBola() {
        boolean vazio = true;

        if (b.intersectsLine(dimx, 0, dimx, dimy)
                || b.intersectsLine(0, 0, 0, dimy)) {
            b.reflecteEsquerdaDireita();//se a bola bater na parede esquerda ou direita



        } else if (b.intersectsLine(0, 0, dimx, 0)) {
            b.reflecteCimaBaixo();//se a bola bater na parede em cima



        }

        if (b.intersectsLine((int) r.x + r.width / 3, (int) r.y, (int) r.x + (int) (r.width / 3) * 2, (int) r.y)) {
            b.reflecteCimaBaixo();//se bater em cima no centro da raquete



        } else if (b.intersectsLine((int) r.x, (int) r.y, (int) r.x + (int) r.width / 3, (int) r.y)) {
            //se bater em cima à esquerda da raquete
            b.setXXDir(b.getXXDir() - 2);
            b.setYYDir(b.getYYDir() - 2);


        } else if (b.intersectsLine((int) r.x + (int) (r.width / 3) * 2, (int) r.y, (int) r.x + (int) r.width, (int) r.y)) {
            //se embater em cima À direita da raquete
            b.setXXDir(b.getXXDir() + 2);
            b.setYYDir(b.getYYDir() - 2);

        } else if (b.intersectsLine((int) r.x, (int) r.y, (int) r.x, (int) r.y + (int) r.height)
                || b.intersectsLine((int) r.x + (int) r.width, (int) r.y, (int) r.x + (int) r.width, (int) r.y + (int) r.height)) {
            b.reflecteEsquerdaDireita(); //se bater nas partes laterais da raquete


        } else if (b.contains((int) r.x, (int) r.y)) {//se embater num dos cantos da raquete
            b.setXXDir(b.getXXDir() - 1);


        } else if (b.contains((int) r.x + (int) r.width, (int) r.y)) {
            b.setXXDir(b.getXXDir() + 1);
        }

        if (b.y > dimy - raio) {//se a bola passu a raquete,perde uma vida.Se já não tiver vidas perde o jogo e começa do inicio

            nVidas--;
            if (nVidas == 0) {

                perdeu();
            } else {
                perdeVida = true;
                bonus.removeAll(bonus);
                bonusApanhado = false;
                bn = null;
            }

        }


        for (int i = 0; i < t.size(); i++) {//se a bola intersecta um tijolo coloca-o invisivel
            if (b.intersects(t.get(i)) && t.get(i).isVisivel()) {
                b.reflecteCimaBaixo();
                t.get(i).setVisivel(false);
                t.get(i).agir(this);
            }
        }


        for (int i = 0; i < t.size(); i++) {
            if (t.get(i).isVisivel())// coloca o tijolo cmo invisivel depois de acertar
            {
                vazio = false;
            }
        }
        if (vazio) {//se não existir mais tijolos visiveischama função ganha d eter apssadod e nivel
            ganha();
        } else {


            if (!b.isCola()) {
                b.mover(this);//envia o próprio objecto Arkanoid à bola
            } else {
                b.moverCola(this);
            }
        }


    }

    public void duplaColisao(Tijolo tj) {//verifica o numero de colisoes com o tijolo e elimina-o após segudna colisao
        if (tj instanceof TijoloVerde) {
            TijoloVerde tij = (TijoloVerde) tj;
            tij.setnColisoes(tij.getnColisoes() + 1);
            if (tij.getnColisoes() < 2) {
                tij.setVisivel(true);
            } else {
                tij.setVisivel(false);
            }
        }

    }

    public void setVizinhos(Tijolo tj) {//verifica tijolos vizinhos de um tijolo e elimina-os
        for (int i = 0; i < t.size(); i++) {
            if (t.get(i) != tj && Math.abs(t.get(i).x - tj.x) <= tj.width && Math.abs(t.get(i).y - tj.y) <= tj.height) {
                t.get(i).setVisivel(false);
            }
        }
    }

    public double getDimx() { //obtém dimensoes em x da frame
        return dimx;




    }

    public double getDimy() {//obtém dimensoes em y da frame
        return dimy;




    }

    public void moveRaquete(int pos) {
        if (pos < dimx - r.width) //coloca a raquete dentro dos boundaries da tela e se for maior que os boundaries não move para além da tela
        {
            r.moveRaquete(pos);

        }
    }

    public void apanhaBonus(Bonus bonus) {//manda o bonus agir conforme o bonus apanhado
        bonus.agir(this);
    }

    public void aumentaPontuacao(int p) {//aumenta a pontuacao actual
        pontuacao = pontuacao + p;


    }

    public void lancaBonus(Tijolo t) {//lanca um bonus
        int n = (int) (Math.random() * nBonus);
        Bonus b;

        b = FabricaBonus.getBonus(n, t);

        bonus.add(b);

    }

    public void moverBonus(Raquete r) {//move um bonus
        ArrayList<Bonus> temp = new ArrayList<Bonus>();
        temp.addAll(bonus);

        for (int i = 0; i
                < temp.size(); i++) {
            //Bonus b = temp.get(i);
            bn = temp.get(i);


            if (bn.y > this.getDimy()) {
                bonus.remove(bn);


            } else {
                if (r.intersects(bn)) {//se a raquete e o bonus se intersectam ela apanha-o
                    bonusApanhado = true;
                    apanhaBonus(bn);

                    bonus.remove(bn);
                } else {
                    bn.mover(this);
                }

            }

        }
    }
}
