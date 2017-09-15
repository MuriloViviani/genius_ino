# GENIUS_INO
A versão para Arduino do jogo Genius!

# Itens necessários
para este projeto serão necessários:

*Hardware*
- Arduino/Genuino UNO (ou derivada)
- Cabo USB
- Protoboard
- 4 LEDs de cores diferentes
- 4 Resistores de 220 Ohms ou 330 Ohms (para as LEDs)
- 4 Botões
- 4 Resistores de 10K Ohms (para os botões)
- Jumper Cables
- Buzzer

*Software*
- [IDE Arduino](https://www.arduino.cc/en/Main/Software)

# Montagem
Em sua protoboard, realize as ligações elétricas assim como mostrado na imagem abaixo

![Montagem Elétrica](https://github.com/MuriloViviani/genius_ino/blob/master/Sketch_Genius_Ino.png)


Sendo as portas:
```
-> 13 - Ligada ao pino positivo do Led Azul
-> 12 - Ligada ao pino positivo do Led Vermelho
-> 11 - Ligada ao pino positivo do Led Amarelo
-> 10 - Ligada ao pino positivo do Led Verde
```
E as portas
```
-> 5 - Ligada a uma das pernas do Botão do LED Azul
-> 4 - Ligada a uma das pernas do Botão do LED Vermelho
-> 3 - Ligada a uma das pernas do Botão do LED Amarelo
-> 2 - Ligada a uma das pernas do Botão do LED Verde
```
e por fim as portas
```
-> GND - Ligada a uma das trilhas laterais, de preferencia a com o risco azul (Negativo)
-> 5 - Ligada a outra linha lateral, de preferencia a com o risco vermelho (Positivo)
```

Lembre-se de colocar tambem os devidos resistores nos LEDs (resistores de 220 ou 330 Ohms) e nos Botões (resistores de 10K Ohms)

