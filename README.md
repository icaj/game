<b>Space Invaders</b>

Implementação do famoso Space Invaders usando a linguagem C.

<b>Equipe:</b><br>
Fernando Cyreno<br>
Ivo Caetano<br>
Marcello Fernandes<br>
<br>
![Printscreen da tela do jogo](https://github.com/icaj/game/blob/master/game.jpg)<br>

Este jogo Space Invaders, implementado em C, recria a mecânica clássica do arcade em um ambiente de terminal em modo texto (80 colunas por 25 linhas). No jogo, o jogador controla uma nave localizada na parte inferior central da tela e enfrenta ondas de invasores que se movem de cima para baixo na tela, descendo gradualmente depois de alguns segundos. O objetivo é eliminar todos os invasores antes que eles cheguem à nave, movendo-se lateralmente e atirando contra eles. A pontuação do jogador aumenta com cada acerto bem-sucedido.

Na implementação, foram usadas funções da biblioteca <b>cli-lib</b> para controlar a tela, gerenciar entradas de teclado e configurar o cronômetro do jogo, criando uma experiência responsiva e interativa em modo texto. As operações de tela atualizam a posição dos invasores, nave e tiros, enquanto o teclado permite mover a nave e atirar. O sistema de temporizador controla a movimentação dos invasores e gera o avanço deles, criando a pressão típica do jogo original.

O jogo possui 8 fases, cada fase o jogador vai ter que enfrentar cada vez mais invasores que ele tem que destruir com projeteis que podem ser disparados através da tecla de espaços. Cada invasor destruido aumentará em 10 pontos sua pontuação. Quanto maior a pontuação obtida, mais possibilidade do jogador aparecer na lista das 10 maiores pontuaçõs que serão registradas pelo jogo.

<b>Pontuação do Jogo</b><br>
O jogo Space Invaders armazena o nome e a pontuação do jogador, inserindo essas informações no arquivo scores.txt. Este arquivo irá concentrar todos os jogadores e suas respectivas pontuações. Também foram implementadas funções para retornar os top 5 jogadores com maior pontuação registrados no arquivo scores.txt. Foi adotada uma arquitetura modular para o processo de armazenamento e leitura da pontuação. O arquivo score.h contém a declração das funções e as definições do tipo utilizadas no processo, enquanto o arquivo score.c contém o código fonte real das funções.

O programa possui os seguintes fontes:

src-\ <br>
    |-game.c  : programa principal do jogo com a logica de funcionamento e controles principais <br>
    |-score.c : funções para salvar e ler a lista de maiores pontuadores gravada no arquivo scores.txt <br>
    |-util.c  : rotinas de apoio <br>
    |-keyboard.h, screen.h, timer.h : biblioteca cli-lib para interface com teclado, display e temporizador <br>


<b>Compilação:</b><br>

O jogo poderá ser compilado baixando o repositório para uma pasta no computador e nesta pasta digitando-se o comando:

<b>make</b><br>

Caso náo possua o comando make disponível, poderá digitar o comando:

<b>gcc src/*.c -I include/ -o build/game</b><br>




