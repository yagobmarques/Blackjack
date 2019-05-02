## Trabalho da disciplina de LP1 2019.1

Utilizando classes, implemente em C++ um jogo de dados hipotético, no qual cada
jogador (de vários) deve lançar dois dados em sua vez. A soma dos valores dos dados
deve ser acumulada para cada jogador. O objetivo é ficar o mais próximo e abaixo do
valor N a ser estabelecido como configuração geral do jogo e visível a todos os
jogadores. Ao obter um valor agregado superior a N, o jogador é considerado excluído
da rodada. A cada vez de jogar, o jogador pode optar por jogar os dados ou parar (e
não jogar mais na rodada). Uma rodada é finalizada quando: (1) resta apenas um
jogador, uma vez que os outros foram excluídos; (2) quando não há mais jogadores a
jogar, ou seja, todos os jogadores “ativos” decidiram parar, ou; (3) quando um dos
jogadores atinge exatamente o valor N. Vence a rodada o jogador que permanecer na
rodada (ou seja, não for excluído) e obtiver o número de pontos agregados mais
próximo de N. Ao final de cada rodada, o programa deverá listar os pontos agregados
obtidos por cada jogar e declarar o campeão da rodada.

### Como compilar
Vá para o diretório raiz do projeto e digite no terminal o comando: 
```
make
```
### Documentação
A documentação está em no camilho ./Codigos-Fonte/documentation-page/html/annotated.html.
Mas também, se quiser execurtar o Doxygen basta digitar o seguinte comando na raiz do projeto:
```
doxygen
```
