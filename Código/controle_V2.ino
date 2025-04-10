#include <LiquidCrystal_I2C.h>

// Definições de pinos
const int botao_esquerdo = 5;
const int botao_direito = 6;
const int potenciometro_esquerdo_verti_A0 = A0;
const int potenciometro_esquerdo_horizo_A1 = A1;
const int potenciometro_direito_verti_A2 = A2;
const int potenciometro_direito_horizo_A3 = A3;

// Definição do LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C do LCD

// Variáveis de controle
int x = 0;
int y = 0;
int selecao = 0;
bool escolha = false;
bool estado_botao_esquerdo_1 = false;

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial para debug

  // Configura os pinos de entrada
  pinMode(botao_esquerdo, INPUT);
  pinMode(botao_direito, INPUT);

  // Inicializa o LCD
  lcd.init();
  lcd.backlight();

  displayMenu();
}

// Função para exibir o menu de seleção
void displayMenu() { 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selecione uma opcao:");
  lcd.setCursor(0, 1);
  lcd.print("> jogar");
  lcd.setCursor(0, 2);
  lcd.print("  Modo Livre");

  // Loop de escolha de opção
  while (escolha == false) {
    y = analogRead(potenciometro_esquerdo_horizo_A1);

    if (y < 495) {
      lcd.setCursor(0, 0);
      lcd.print("Selecione uma opcao:");
      lcd.setCursor(0, 1);
      lcd.print("> jogar");
      lcd.setCursor(0, 2);
      lcd.print("  Modo Livre");
      selecao = 0;
    } else if (y > 515) {
      lcd.setCursor(0, 0);
      lcd.print("Selecione uma opcao:");
      lcd.setCursor(0, 1);
      lcd.print("  jogar");
      lcd.setCursor(0, 2);
      lcd.print("> Modo Livre");
      selecao = 1;
    }

    estado_botao_esquerdo_1 = digitalRead(botao_esquerdo);
    if (estado_botao_esquerdo_1) {
      escolha = true;
      lcd.clear();
      if (selecao == 0) {
        Serial.println("Jogo Iniciado");
      } else {
        lcd.setCursor(0, 0);
        modolivre();
      }
    } 
  }
}

// Função para o modo livre
void modolivre() {
  int parou = 1; 
  while(parou == 1) {
    int a_esquerdo = analogRead(potenciometro_esquerdo_verti_A0);
    int b_esquerdo = analogRead(potenciometro_esquerdo_horizo_A1);
    int c_direito = analogRead(potenciometro_direito_verti_A2);
    int d_direito = analogRead(potenciometro_direito_horizo_A3);

    if (a_esquerdo < 500) {
      Serial.print("1");
      Serial.print(",");
      Serial.println(a_esquerdo);
    } else if (a_esquerdo > 530) {
      Serial.print("1");
      Serial.print(",");
      Serial.println(a_esquerdo);
    } else if (b_esquerdo < 500) {
      Serial.print("2");
      Serial.print(",");
      Serial.println(b_esquerdo);
    } else if (b_esquerdo > 518) {
      Serial.print("2");
      Serial.print(",");
      Serial.println(b_esquerdo);
    } else if (c_direito < 515) {
      Serial.print("3");
      Serial.print(",");
      Serial.println(c_direito);
    } else if (c_direito > 540) {
      Serial.print("3");
      Serial.print(",");
      Serial.println(c_direito);
    } else if (d_direito < 495) {
      Serial.print("4");
      Serial.print(",");
      Serial.println(d_direito);
    } else if (d_direito > 520) {
      Serial.print("4");
      Serial.print(",");
      Serial.println(d_direito);
    } else {
      Serial.println("0");
    }
  }
}

void loop() {
  // O loop agora está vazio porque a interação ocorre no menu e no modo livre.
}
