/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Arkanoid;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.io.Serializable;
import java.util.Observable;
import java.util.Observer;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author Carla Raquel
 */
public class vistaArkanoid extends JFrame implements Observer, Serializable {

    private ModeloArkanoid ar; //liga ao modelo
    private Desenho desenho;
    private Container c;
    private JButton iniciar;
    private JButton novoJogo;
    private JButton carregarJogo;
    private JButton guardarJogo;
    private JButton pausarJogo;
    private JButton sairJogo;
    private Tempo tempo;

    public vistaArkanoid(int ms, ModeloArkanoid a, int largura, int altura) {
        super("Arkanoid por Carla Graça a21150031 e André César a21150076");//define o título da frame
        ar = a;//liga o modelo a esta vista
        ar.addObserver(this);//coloca este objecto como observador do modelo
        c = getContentPane();
        tempo = new Tempo(ar, ms);//cria um timer que coordena o movimento da bola num determinado tempo
        setSize(largura, altura);//define as dimensoes da JFrame
        criaObjectosGraficos(); //cria os objectos gráficos
        disporVista();//coloca os objectos gráficos na tela
        registarListeners();//regista os listeners que ficarão á escuta por interacções do utilizador com a vista
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);//centra no ecrã a jframe
        setVisible(true);//coloca a frame como visível
        update(ar, null);//invoca a função paint component para actualizar e redesenhar os objectos gráficos e as suas novas posições an tela
        validate();
    }

    public void criaObjectosGraficos() {
        desenho = new Desenho(ar);
        iniciar = new JButton("Start");
        carregarJogo = new JButton("Load");
        guardarJogo = new JButton("Save");
        pausarJogo = new JButton("Pause");
         sairJogo = new JButton("Quit");
    }

    protected void disporVista()//desenha objectos na vista
    {
        JPanel fundo = new JPanel();
        c.add(fundo);
        fundo.add(desenho);

        JPanel sul = new JPanel();
        c.add(sul, BorderLayout.SOUTH);
        sul.add(iniciar);


        c.add(sul, BorderLayout.SOUTH);
        sul.add(carregarJogo);

        c.add(sul, BorderLayout.SOUTH);
        sul.add(guardarJogo);

        c.add(sul, BorderLayout.SOUTH);
        sul.add(pausarJogo);

        c.add(sul, BorderLayout.SOUTH);
        sul.add(sairJogo);

    }

    public void registarListeners() {
        iniciar.addActionListener(new IniciarListener());
        desenho.addMouseListener(new BolaListener());
        desenho.addMouseMotionListener(new RaqueteListener());
        carregarJogo.addActionListener(new CarregaJogoListener());
        guardarJogo.addActionListener(new GuardaJogoListener());
        pausarJogo.addActionListener(new PausaJogoListener());
        sairJogo.addActionListener(new SairJogoListener());

    }

    public void update(Observable o, Object arg) {//actualiza a vista
        desenho.repaint();
    }

    class IniciarListener implements ActionListener {//listener que escuta pelo clique do rato no botão para iniciar jogo

        public void actionPerformed(ActionEvent e) {
            ar.iniciaJogo();
            tempo.continuarTimer();
        }
    }

    class SairJogoListener implements ActionListener {//listener que escuta pelo clique do rato no botão para sair do jogo

        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    class CarregaJogoListener implements ActionListener {//listener que escuta pelo clique do rato no botão para carregar jogo

        public void actionPerformed(ActionEvent e) {
            ModeloArkanoid ob = new ModeloArkanoid(ar.carregaJogo());
            update(ob, null);
         tempo.continuarTimer();
        }
    }

    class GuardaJogoListener implements ActionListener {//listener que escuta pelo clique do rato no botão para guarda jogo

        public void actionPerformed(ActionEvent e) {
            ar.salvaJogo();
            tempo.continuarTimer();
        }
    }

    class PausaJogoListener implements ActionListener {//listener que escuta pelo clique do rato no botão para pausar ou continuar jogo

        public void actionPerformed(ActionEvent e) {
            if (e.getActionCommand().equals("Pause")) {
                tempo.pararTimer();
                pausarJogo.setText("Unpause");
            } else {
                tempo.continuarTimer();
                pausarJogo.setText("Pause");

            }
        }
    }

    class RaqueteListener extends MouseMotionAdapter {//listener que está à escuta pelo movimento do rato do utilizador

        public void mouseMoved(MouseEvent e) {
            ar.moveRaquete(e.getX());

        }
    }

    class BolaListener extends MouseAdapter {//listener que estÃ¡ Ã  escuta pelo movimento do rato do utilizador

        public void mouseClicked(MouseEvent e) {
            ar.libertaBola();
        }
    }
}
