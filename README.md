<b>Space Invaders</b>

Implementação do famoso Space Invaders usando a linguagem C.

<b>Equipe:</b><br>
Fernando Cyreno<br>
Ivo Caetano<br>
Marcello Fernandes<br>
<br>
![Printscreen da tela do jogo](https://github.com/icaj/game/game.jpg)<br>

Este jogo Space Invaders, implementado em C, recria a mecânica clássica do arcade em um ambiente de terminal em modo texto (80 colunas por 25 linhas). No jogo, o jogador controla uma nave localizada na parte inferior central da tela e enfrenta ondas de invasores que se movem de cima para baixo na tela, descendo gradualmente depois de alguns segundos. O objetivo é eliminar todos os invasores antes que eles cheguem à nave, movendo-se lateralmente e atirando contra eles. A pontuação do jogador aumenta com cada acerto bem-sucedido.

Na implementação, foram usadas funções da biblioteca <b>cli-lib</b> para controlar a tela, gerenciar entradas de teclado e configurar o cronômetro do jogo, criando uma experiência responsiva e interativa em modo texto. As operações de tela atualizam a posição dos invasores, nave e tiros, enquanto o teclado permite mover a nave e atirar. O sistema de temporizador controla a movimentação dos invasores e gera o avanço deles, criando a pressão típica do jogo original.

O jogo possui 8 fases, cada fase o jogador vai ter que enfrentar cada vez mais invasores que ele tem que destruir com projeteis que podem ser disparados através da tecla de espaços. Cada invasor destruido aumentará em 10 pontos sua pontuação. Quanto maior a pontuação obtida, mais possibilidade do jogador aparecer na lista das 10 maiores pontuaçõs que serão registradas pelo jogo.


