

//Bibliotecas importadas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

//Configuração inicial do display

LiquidCrystal_I2C lcd(0x27, 4, 20);

//Declaração das Variáveis

const int botao_esquerdo = 5;
const int botao_direito = 6;
const int potenciometro_esquerdo_verti_A0 = 14;
const int potenciometro_esquerdo_horizo_A1 = 15; 
const int potenciometro_direito_verti_A2 = 16;
const int potenciometro_direito_horizo_A3 = 17;
int x = 0;
int y = 0;


RF24 radio(7, 8); // CE, CSN]
const byte address[6] = "01987";


//Declaração das funções

void displayMenu();
//void iniciar_jogo(int diculdade);
void selec_dificul();

//Main

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  pinMode(potenciometro_esquerdo_verti_A0, INPUT);
  pinMode(potenciometro_esquerdo_horizo_A1, INPUT);
  pinMode(botao_esquerdo, INPUT);
  pinMode(botao_direito, INPUT);

  displayMenu();


    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
}

//Funções criadas para realizar interações com o usuário e envio de dados para o braço mecânico

//A função a baico inicia o menu

void displayMenu() { 
  //Configurações iniciais do display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selecione uma opcao:");
  lcd.setCursor(0, 1);
  lcd.print("> jogar");
  lcd.setCursor(0, 2);
  lcd.print("  ranking");

  //Variáveis úteis para está função

  int selecao = 0;
  bool escolha = false;
  bool estado_botao_esquerdo_1 = false;

  //Ciclo para escolher entre jogar e olhar o ranking.

  while (escolha == false){

    y = analogRead(potenciometro_esquerdo_horizo_A1);

    if (y < 495) {
      lcd.setCursor(0, 0);
      lcd.print("Selecione uma opcao:");
      lcd.setCursor(0, 1);
      lcd.print("> jogar");
      lcd.setCursor(0, 2);
      lcd.print("  ranking");
      selecao = 0;
    } else if (y > 515) {
      lcd.setCursor(0, 0);
      lcd.print("Selecione uma opcao:");
      lcd.setCursor(0, 1);
      lcd.print("  jogar");
      lcd.setCursor(0, 2);
      lcd.print("> ranking");
      selecao = 1;
      }
    estado_botao_esquerdo_1 = digitalRead(botao_esquerdo);
    if (estado_botao_esquerdo_1){
      escolha == true;
      lcd.clear();
      if(selecao == 0){
        selec_dificul();
      } else {
        lcd.setCursor(0, 0);
        lcd.print("esc. ranking");
      }
    } 
  }
}

//Função para seleção da dificuldade

void selec_dificul() {

  //Configuração do display

  lcd.setCursor(0, 0); // Linha 1
  lcd.print("Selecione:");
  
  lcd.setCursor(0, 1); // Linha 2
  lcd.print("> Facil");

  lcd.setCursor(0, 2); // Linha 3
  lcd.print("  Medio");

  lcd.setCursor(0, 3); // Linha 4
  lcd.print("  Dificil");

  //Variáveis úteis para está função

  bool estado_botao_esquerdo = false;
  int dificuldade = 0;
  int cursor = 0;
  bool esc = false;

  //ciclo para escolha da dificuldade e animação do display

  while(esc == false){

    if (digitalRead(botao_esquerdo) == LOW){
      esc = true;
      iniciar_jogo(dificuldade);

    }

    y = analogRead(potenciometro_esquerdo_horizo_A1);
    Serial.print(y);
    Serial.print("     ");
    Serial.println(estado_botao_esquerdo);
      
    if (y > 515){

      if(cursor == 0){
        cursor = 1;
        lcd.setCursor(0, 1); // Linha 2
        lcd.print("  Facil");

        lcd.setCursor(0, 2); // Linha 3
        lcd.print("> Medio");
    
        lcd.setCursor(0, 3); // Linha 4
        lcd.print("  Dificil");

        dificuldade = 1;
        delay(200);
      } else if(cursor == 1){
        cursor = 2;
        lcd.setCursor(0, 1); // Linha 2
        lcd.print("  Facil");

        lcd.setCursor(0, 2); // Linha 3
        lcd.print("  Medio");
    
        lcd.setCursor(0, 3); // Linha 4
        lcd.print("> Dificil");

        dificuldade = 2;
        delay(200);
      } else if(cursor == 2){
        cursor = 0;
        lcd.setCursor(0, 1); // Linha 2
        lcd.print("> Facil");

        lcd.setCursor(0, 2); // Linha 3
        lcd.print("  Medio");
    
        lcd.setCursor(0, 3); // Linha 4
        lcd.print("  Dificil");

        dificuldade = 0;
        delay(200);
      }
    }
    if(y < 495){

      if(cursor == 0){
        cursor = 1;
        lcd.setCursor(0, 1); // Linha 2
        lcd.print("  Facil");

        lcd.setCursor(0, 2); // Linha 3
        lcd.print("  Medio");
    
        lcd.setCursor(0, 3); // Linha 4
        lcd.print("> Dificil");

        dificuldade = 1;
        delay(200);
      } else if(cursor == 1){
        cursor = 2;
        lcd.setCursor(0, 1); // Linha 2
        lcd.print("  Facil");

        lcd.setCursor(0, 2); // Linha 3
        lcd.print("> Medio");
    
        lcd.setCursor(0, 3); // Linha 4
        lcd.print("  Dificil");

        dificuldade = 2;
        delay(200);
      } else if(cursor == 2){
        cursor = 0;
        lcd.setCursor(0, 1); // Linha 2
        lcd.print("> Facil");

        lcd.setCursor(0, 2); // Linha 3
        lcd.print("  Medio");
    
        lcd.setCursor(0, 3); // Linha 4
        lcd.print("  Dificil");

        dificuldade = 0;
        delay(200);
      }
    }
  }   
}




void iniciar_jogo(int dificuldade){

  int base_horizo = analogRead(potenciometro_esquerdo_horizo_A1);
  int base_verti = analogRead(potenciometro_esquerdo_verti_A0);
  int mao_horizo = analogRead(potenciometro_direito_horizo_A3);
  int mao_verti = analogRead(potenciometro_direito_verti_A2);

  radio.write(&base_horizo, sizeof(base_horizo));
  delay(100);
  radio.write(&base_verti, sizeof(base_verti));
  delay(100);
  radio.write(&mao_horizo, sizeof(mao_horizo));
  delay(100);
  radio.write(&mao_verti, sizeof(mao_verti));
  delay(100);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Iniciando o jogo");
  for(int i = 0; i < 3; i++){
      lcd.setCursor(16+i,0);
      lcd.print(".");
      delay(1000);
  }

  if (dificuldade == 0){
      for (int i=200; i > 0; i-- ){
          lcd.setCursor(0, 0);
          lcd.print(i);
          delay(1000);
      }


  } else if (dificuldade == 1){
      for (int i=250; i > 0; i-- ){
          lcd.setCursor(0, 0);
          lcd.print(i);
          delay(1000);

      }


  } else if (dificuldade == 2){
      for (int i=300; i > 0; i-- ){
          lcd.setCursor(0, 0);
          lcd.print(i);
          delay(1000);

      }


  }}


