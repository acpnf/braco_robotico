## Braço Robótico
O trabalho consiste em um jogo, no qual o jogador deve usar um braço mecânico, controlado por um controle sem fio, para separar objetos em lugares específicos em um determinado intervalo de tempo, que varia dependendo da dificuldade escolhida pelo usuário.

## Integrantes do Grupo:
- André Polo Norte 
- Ikelvys Kauê
- João Pedro Lima
- Pablo Nunes
- Roni Nicolau Oliveira
- Théo Marcos Do Egito

## 1. Idealização do Projeto 
Num primeiro momento, reunimos o grupo a fim de definir o que seria feito no projeto. Nessa fase inicial, o fator "Criatividade e Inovação" fez com que nós ficássemos muito pensativos sobre o que fazer no nosso trabalho, visto que a ideia seria que montássemos algo que explorasse novas atuações do Arduíno ou algo que resolvesse problemas do cotidiano.
A partir disso, depois de muito pensar acerca do que poderia ser feito, chegamos à conclusão de que iríamos fazer um braço robótico (com peças oriundas de impressão 3D), com visão computacional que faria a separação automatizada de objetos por meio de uma webcam que reconheceria e separaria os objetos em categorias.
Diante disso, escrevemos a documentação inicial da nossa ideia e enviamos para que ela passasse pelo processo de aprovação pelos monitores das matérias. Infelizmente, nesse primeiro momento a proposta foi recusada, visto que a visão computacional e a automatização do processo deixariam a utilização do Arduíno, que em tese deveria ser o foco do projeto, de forma subutilizada. Ou seja, o que era para ser o foco do projeto virou uma parte pequena da realização do projeto, fazendo com que os monitores reprovassem nossa ideia.
Num momento posterior, nos reunimos novamente para definir qual seria nossa ideia para a realização do projeto e decidimos por manter a ideia da construção do braço robótico, mas dessa vez ele seria utilizado para a realização de um jogo, no qual o intuito seria utilizar um joystick que controlasse o braço mecânico com a finalidade de separar alguns objetos que estariam misturados dentro de um recipiente. Isso tudo aconteceria em um tempo pré-determinado que estaria sendo contabilizado por um visor LCD.
Depois disso, enviamos a documentação referente a esse novo projeto e, dessa vez, nós tivemos a nossa ideia aprovada. Com isso, partiríamos para a segunda parte do projeto: o desenvolvimento do projeto.

## 2. Desenvolvimento 
### Material Necessário:
Peças necessárias para o braço:
- Arduino Leonardo (1 unidade);
- Servo motor tipo MG995 180º (4 unidades);
- MG90 Servo (3 unidades);
- 608 Bearing (1 unidade);
- 6203 Bearing (2 unidades);
- Display LCD (1 unidade);
- LED (1 unidade);
- Resistor 225 ohm (1 unidade).
### Peças necessárias para o braço (Impressão 3D): Link para o arquivo 3D
Peças necessárias para o controle:
- Arduino Nano (1 unidade);
- Joystick (1 unidade);
- Push button (4 unidades);
- Interruptor (1 unidade);
- LED (1 unidade);
- Resistor 225 ohm (1 unidade).

## Funcionamento do Projeto
A ideia do projeto é desenvolver um jogo em que o participante possua um tempo determinado, a depender do nível de dificuldade escolhido por ele (Fácil, Médio, Difícil). Funcionará da seguinte forma: O jogador escolherá a dificuldade e em seguida o tempo passará a ser contabilizado no visor LCD, a partir disso o objetivo do jogo é utilizar o braço robótico desenvolvido para pegar objetos específicos e subdividir em recipientes diferentes. 

## Montagens Individuais 
Após a aprovação do projeto pelos monitores organizadores, nos juntamos novamente para começar o desenvolvimento do projeto. Como nossa ideia era fazer um braço robótico com peças feitas em impressão 3D, nos juntamos com os representantes do robô CIn para que pudéssemos realizar as impressões das peças.
Após dar início à produção das peças, nos juntamos no Laboratório de Hardware para dar início ao desenvolvimento dos códigos e fazer testes necessários com a utilização do joystick, peça que seria fundamental para a atuação do nosso jogo.
Além disso, paralelamente à produção do joystick, começamos a elaboração do modelo do molde de soldagem (feito no software KiCad 8), que seria utilizado para a montagem das peças do joystick. Decidimos pela utilização da técnica da soldagem pelo fato de que o nosso projeto irá ficar exposto e a má manipulação do joystick poderia ocasionar uma desconexão entre as peças.

## Dificuldades Enfrentadas
- A comunicação sem fio (NRF, etc.) resultou em falhas no envio de dados;
- Demora da entrega das peças;
- Linguagem de Programação diferente da que estávamos habituados. 

## Mudanças que ocorreram
- Modificamos as modalidades de dificuldade com o intuito de se encaixar mais na dinâmica do nosso projeto. Em vez de colocar: Fácil, Médio e Difícil; colocamos: Modo Livre e um modo de jogo com tempo único;
- Módulo de comunicação sem fio trocamos por comunicação Serial entre arduinos.

## O que não foi implementado e por quê:
- O NRF não chegou a ser implementado no resultado final do trabalho pela a equipe devido a dificuldade de implementação;
- Não conseguimos completar o projeto, pois houve um grande problema na parte da comunicação sem fio, o que nos obrigou a utilizar a comunicação serial entre os arduinos, além de consumir muito tempo;
- O envio das coordenadas entre o sistema e os joysticks estava gerando muito ruído, o que comprometeu a precisão dos movimentos e impossibilitou o trabalho de se completar.

## Possíveis Soluções:
- Trocar o microcontrolador atual por um ESP 32, o que permitiria maior flexibilidade e estabilidade na comunicação sem fio;
- Identificar a melhor forma de integrar o NRF ao Arduino sem gerar erros;
- Investigar mais a fundo se o melhor caminho seria utilizar Wi-Fi ou comunicação via rádio, de forma a garantir uma solução mais eficiente e sem interferências;
- Testar códigos que tentam suavizar mais os movimentos dos servos;
- Troca do display por um modelo menor, o que contribuiria para tornar o controle mais compacto e portátil.

