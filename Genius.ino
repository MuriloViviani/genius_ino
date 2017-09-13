//[0] = verde,[1] = amarelo,[2] = vermelho,[3] = azul
int leds[] {10,11,12,13};
//[0] = verde,[1] = amarelo,[2] = vermelho,[3] = azul
int botoes[] {2,3,4,5};
int buzzer = 9;
int btnApertar[7];
//sequencia de leds para acender
int seq[15];

int posiAtual = 0,posiFinal = 1;
int reset = 0,btn = 0,btnPress = 9;
bool mostrarSeq = true,rodaJogo = true;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i<4;i++)
  {
    pinMode(botoes[i],INPUT);
  }
  for(int i = 0; i<4;i++)
  {
    pinMode(leds[i],OUTPUT);
  }
  pinMode(buzzer,OUTPUT);
}

void loop() {
  reset = 0;
  btn = 0;
  btnPress = 9;
  posiFinal = 1;
  posiAtual = 0;
  rodaJogo = true;
  mostrarSeq = true;
  
  for(int k=0;k<15;k++)//Gera a sequencia aleatoria
  {
    seq[k] = random(0,4);
    btnApertar[k] = seq[k];
  }
  while(rodaJogo == true){//timer_1
    while(posiAtual < posiFinal && mostrarSeq == true)
    {
      digitalWrite(leds[seq[posiAtual]],HIGH);
      if(seq[posiAtual] == 0)
        tone(buzzer,200);
      else if(seq[posiAtual] == 1)
        tone(buzzer,400);
      else if(seq[posiAtual] == 2)
        tone(buzzer,600);
      else
        tone(buzzer,800);
      delay(500);
      digitalWrite(leds[seq[posiAtual]],LOW);
      noTone(buzzer);
      delay(500);
      posiAtual++;
    }
    posiAtual = 0;
    mostrarSeq = false;
    while(rodaJogo == true){
      if(digitalRead(botoes[0]) == HIGH){
        btnPress = 0;
        digitalWrite(leds[0],HIGH);
        tone(buzzer,200);
        delay(200);
        digitalWrite(leds[0],LOW);
        noTone(buzzer);
        delay(200);
      }
      if(digitalRead(botoes[1]) == HIGH){
        btnPress = 1;
        digitalWrite(leds[1],HIGH);
        tone(buzzer,400);
        delay(200);
        digitalWrite(leds[1],LOW);
        noTone(buzzer);
        delay(200);
      }
      if(digitalRead(botoes[2]) == HIGH){
        btnPress = 2;
        digitalWrite(leds[2],HIGH);
        tone(buzzer,600);
        delay(200);
        digitalWrite(leds[2],LOW);
        noTone(buzzer);
        delay(200);
      }
      if(digitalRead(botoes[3]) == HIGH){
        btnPress = 3;
        digitalWrite(leds[3],HIGH);
        tone(buzzer,800);
        delay(200);
        digitalWrite(leds[3],LOW);
        noTone(buzzer);
        delay(200);
      } 
      if(btnPress != btnApertar[posiAtual] && btnPress != 9){
        btn = 99;
        break;
      }
      else{
        if(posiAtual == posiFinal){
          for(int j=0;j<2;j++){
            for(int i=0;i<4;i++){
            digitalWrite(leds[i],HIGH);
            }
            delay(100);
            for(int i=0;i<4;i++){
            digitalWrite(leds[i],LOW);
            }
          delay(100);
          }
          mostrarSeq = true;
          delay(500);
          break;
        }
        else if(btnPress != 9){
          posiAtual++;
          btnPress = 9;
        }
      }
    }
    if(btn == 99)//Checa o fim de jogo
      break;
    else
      posiAtual = 0;
    if(posiFinal == 14)//Checa se o jogador terminou a sequencia
    {
      for(int j=0;j<10;j++){
        for(int i=0;i<4;i++){
          digitalWrite(leds[i],HIGH);
        }
        delay(100);
        for(int i=0;i<4;i++){
          digitalWrite(leds[i],LOW);
        }
        delay(100);
      }
      break;
    }
    else
      posiFinal++;
    btnPress = 9;
  }//Fim Timer_1
  for(int i=0;i<4;i++)
    digitalWrite(leds[i],HIGH);
  
  delay(2000);
  
  while(digitalRead(botoes[reset]) != HIGH){//Aguarda o jogador apertar um botão para reiniciar o jogo
    delay(1);
    if(reset >= 3){
      reset = 0;
    }
    else{
      reset++;
    }
  }
  for(int i=0;i<4;i++)
    digitalWrite(leds[i],LOW);
  delay(1000);
}
