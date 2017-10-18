#define NR_PRG        32
#define _100_MS       100
#define _DESCIDA      200
#define _ONE_SEC      1000
#define VERSAO        "2"

#define PONTO_1       22
#define PONTO_2       24
#define PONTO_3       26
#define PONTO_4       28
#define PONTO_5       31
#define PONTO_6       33
#define PONTO_7       35
#define PONTO_8       37
#define PONTO_9       39
#define PONTO_10      41
#define PONTO_11      43
#define PONTO_12      45
#define PONTO_13      47
#define PONTO_14      49
#define PONTO_15      51
#define PONTO_16      53
#define PONTO_17      30
#define PONTO_18      32
#define PONTO_19      34
#define PONTO_20      36
#define PONTO_21      38
#define PONTO_22      40
#define PONTO_23      42
#define PONTO_24      44
#define PONTO_25      46
#define PONTO_26      48
#define PONTO_27      50
#define PONTO_28      52
#define PONTO_29      A11
#define PONTO_30      A8
#define PONTO_31      A9
#define PONTO_32      A10
//#define PONTO_TESTE   A14
#define BOTAO         A15

//tempos dos disparos
#define DISPARO_1     1324
#define DISPARO_2     1580
#define DISPARO_3     1850
#define DISPARO_4     2000
#define DISPARO_5     2500
#define DISPARO_6     3000
#define DISPARO_7     3500
#define DISPARO_8     4000
#define DISPARO_9     4500
#define DISPARO_10    5000
#define DISPARO_11    5500
#define DISPARO_12    6000
#define DISPARO_13    6500
#define DISPARO_14    7000
#define DISPARO_15    7500
#define DISPARO_16    8000
#define DISPARO_17    8500
#define DISPARO_18    9000
#define DISPARO_19    9500
#define DISPARO_20    10000
#define DISPARO_21    10500
#define DISPARO_22    11000
#define DISPARO_23    11500
#define DISPARO_24    12000
#define DISPARO_25    12500
#define DISPARO_26    13000
#define DISPARO_27    13500
#define DISPARO_28    14000
#define DISPARO_29    14500
#define DISPARO_30    15000
#define DISPARO_31    15500
#define DISPARO_32    16000

bool ctrl, sent, liga_desliga;
uint8_t programa_atual;
uint32_t timestamp, subida, descida;
//vetor que recebe todo os 32 tempos, separado por virgula
//o valor eh a quantidade de milisegundos a partir de
//pressionado o botao
uint32_t programa[NR_PRG] = { DISPARO_1, DISPARO_2, DISPARO_3, DISPARO_4,
                              DISPARO_5, DISPARO_6, DISPARO_7, DISPARO_8,
                              DISPARO_9, DISPARO_10, DISPARO_11, DISPARO_12,
                              DISPARO_13, DISPARO_14, DISPARO_15, DISPARO_16,
                              DISPARO_17, DISPARO_18, DISPARO_19, DISPARO_20,
                              DISPARO_21, DISPARO_22, DISPARO_23, DISPARO_24,
                              DISPARO_25, DISPARO_26, DISPARO_27, DISPARO_28,
                              DISPARO_29, DISPARO_30, DISPARO_31, DISPARO_32,
                            };
//carrega a proxima borda de subida
void carrega_programa() {
  //subida = timestamp + programa[programa_atual];
  subida = programa[programa_atual];
  descida = subida + 10;
}
//para e reinicia o programa
void parar_programa() {
  //timestamp = 0;
  //programa_atual = 0;
  //subida = 0;
  //descida = 0;
  OCR0A = 0xFF;
  TIMSK0 &= ~(_BV(OCIE0A));
  digitalWrite(LED_BUILTIN, LOW);
}
//inicializacao mcu
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PONTO_1, OUTPUT);
  pinMode(PONTO_2, OUTPUT);
  pinMode(PONTO_3, OUTPUT);
  pinMode(PONTO_4, OUTPUT);
  pinMode(PONTO_5, OUTPUT);
  pinMode(PONTO_6, OUTPUT);
  pinMode(PONTO_7, OUTPUT);
  pinMode(PONTO_8, OUTPUT);
  pinMode(PONTO_9, OUTPUT);
  pinMode(PONTO_10, OUTPUT);
  pinMode(PONTO_11, OUTPUT);
  pinMode(PONTO_12, OUTPUT);
  pinMode(PONTO_13, OUTPUT);
  pinMode(PONTO_14, OUTPUT);
  pinMode(PONTO_15, OUTPUT);
  pinMode(PONTO_16, OUTPUT);
  pinMode(PONTO_17, OUTPUT);
  pinMode(PONTO_18, OUTPUT);
  pinMode(PONTO_19, OUTPUT);
  pinMode(PONTO_20, OUTPUT);
  pinMode(PONTO_21, OUTPUT);
  pinMode(PONTO_22, OUTPUT);
  pinMode(PONTO_23, OUTPUT);
  pinMode(PONTO_24, OUTPUT);
  pinMode(PONTO_25, OUTPUT);
  pinMode(PONTO_26, OUTPUT);
  pinMode(PONTO_27, OUTPUT);
  pinMode(PONTO_28, OUTPUT);
  pinMode(PONTO_29, OUTPUT);
  pinMode(PONTO_30, OUTPUT);
  pinMode(PONTO_31, OUTPUT);
  pinMode(PONTO_32, OUTPUT);
  pinMode(BOTAO, INPUT);

  parar_programa();
  ctrl = true;
  sent = true;

  Serial.print("Inicio ");
  Serial.print(VERSAO);
  Serial.println();
}
//aciona ou desliga a saida do programa atual
//var liga_desliga controla o sentido
void executa_programa() {
  // Serial.print("Executando programa ");
  // Serial.print(programa_atual);
  // Serial.print(" L/D ");
  // Serial.print(liga_desliga);
  // Serial.println();

  switch (programa_atual) {
    case 0:
      if (liga_desliga) digitalWrite(PONTO_1, HIGH); else digitalWrite(PONTO_1, LOW);
      break;
    case 1:
      if (liga_desliga) digitalWrite(PONTO_2, HIGH); else digitalWrite(PONTO_2, LOW);
      break;
    case 2:
      if (liga_desliga) digitalWrite(PONTO_3, HIGH); else digitalWrite(PONTO_3, LOW);
      break;
    case 3:
      if (liga_desliga) digitalWrite(PONTO_4, HIGH); else digitalWrite(PONTO_4, LOW);
      break;
    case 4:
      if (liga_desliga) digitalWrite(PONTO_5, HIGH); else digitalWrite(PONTO_5, LOW);
      break;
    case 5:
      if (liga_desliga) digitalWrite(PONTO_6, HIGH); else digitalWrite(PONTO_6, LOW);
      break;
    case 6:
      if (liga_desliga) digitalWrite(PONTO_7, HIGH); else digitalWrite(PONTO_7, LOW);
      break;
    case 7:
      if (liga_desliga) digitalWrite(PONTO_8, HIGH); else digitalWrite(PONTO_8, LOW);
      break;
    case 8:
      if (liga_desliga) digitalWrite(PONTO_9, HIGH); else digitalWrite(PONTO_9, LOW);
      break;
    case 9:
      if (liga_desliga) digitalWrite(PONTO_10, HIGH); else digitalWrite(PONTO_10, LOW);
      break;
    case 10:
      if (liga_desliga) digitalWrite(PONTO_11, HIGH); else digitalWrite(PONTO_11, LOW);
      break;
    case 11:
      if (liga_desliga) digitalWrite(PONTO_12, HIGH); else digitalWrite(PONTO_12, LOW);
      break;
    case 12:
      if (liga_desliga) digitalWrite(PONTO_13, HIGH); else digitalWrite(PONTO_13, LOW);
      break;
    case 13:
      if (liga_desliga) digitalWrite(PONTO_14, HIGH); else digitalWrite(PONTO_14, LOW);
      break;
    case 14:
      if (liga_desliga) digitalWrite(PONTO_15, HIGH); else digitalWrite(PONTO_15, LOW);
      break;
    case 15:
      if (liga_desliga) digitalWrite(PONTO_16, HIGH); else digitalWrite(PONTO_16, LOW);
      break;
    case 16:
      if (liga_desliga) digitalWrite(PONTO_17, HIGH); else digitalWrite(PONTO_17, LOW);
      break;
    case 17:
      if (liga_desliga) digitalWrite(PONTO_18, HIGH); else digitalWrite(PONTO_18, LOW);
      break;
    case 18:
      if (liga_desliga) digitalWrite(PONTO_19, HIGH); else digitalWrite(PONTO_19, LOW);
      break;
    case 19:
      if (liga_desliga) digitalWrite(PONTO_20, HIGH); else digitalWrite(PONTO_20, LOW);
      break;
    case 20:
      if (liga_desliga) digitalWrite(PONTO_21, HIGH); else digitalWrite(PONTO_21, LOW);
      break;
    case 21:
      if (liga_desliga) digitalWrite(PONTO_22, HIGH); else digitalWrite(PONTO_22, LOW);
      break;
    case 22:
      if (liga_desliga) digitalWrite(PONTO_23, HIGH); else digitalWrite(PONTO_23, LOW);
      break;
    case 23:
      if (liga_desliga) digitalWrite(PONTO_24, HIGH); else digitalWrite(PONTO_24, LOW);
      break;
    case 24:
      if (liga_desliga) digitalWrite(PONTO_25, HIGH); else digitalWrite(PONTO_25, LOW);
      break;
    case 25:
      if (liga_desliga) digitalWrite(PONTO_26, HIGH); else digitalWrite(PONTO_26, LOW);
      break;
    case 26:
      if (liga_desliga) digitalWrite(PONTO_27, HIGH); else digitalWrite(PONTO_27, LOW);
      break;
    case 27:
      if (liga_desliga) digitalWrite(PONTO_28, HIGH); else digitalWrite(PONTO_28, LOW);
      break;
    case 28:
      if (liga_desliga) digitalWrite(PONTO_29, HIGH); else digitalWrite(PONTO_29, LOW);
      break;
    case 29:
      if (liga_desliga) digitalWrite(PONTO_30, HIGH); else digitalWrite(PONTO_30, LOW);
      break;
    case 30:
      if (liga_desliga) digitalWrite(PONTO_31, HIGH); else digitalWrite(PONTO_31, LOW);
      break;
    case 31:
      if (liga_desliga) digitalWrite(PONTO_32, HIGH); else digitalWrite(PONTO_32, LOW);
      break;
  }
}
//acontece a cada 1ms
//relogio do programa
SIGNAL(TIMER0_COMPA_vect)
{
  if (!(timestamp % _ONE_SEC)) { //heart_beat (programa em execucao)
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }

  if (timestamp == subida) { //ligar saida de acordo com programa
    liga_desliga = true;
    executa_programa();
    descida = timestamp + _DESCIDA;
    Serial.print("Disparo ");
    Serial.print(programa_atual);
    Serial.println();
  }

  if (timestamp == descida) { //desligar a saida
    liga_desliga = false;
    executa_programa();
    descida = 0;
    programa_atual++;

    if (programa_atual == NR_PRG) {//ultimo programa executado
      parar_programa();
      timestamp = 0;
      programa_atual = 0;
      subida = 0;
      descida = 0;
    } else { //ainda existe programas a executar
      carrega_programa();
    }
  }

  timestamp++;
}

void loop() { //le o botao para iniciar/parar programa
  if (digitalRead(BOTAO)) {
    delay(100);//debounce botao

    if (digitalRead(BOTAO)) { //botao pressionado
      if (ctrl) { //trigger do botao
        ctrl = false;

        if (sent) {//inicia o programa
          sent = false;
          carrega_programa();
          OCR0A = 0xAF;
          TIMSK0 |= _BV(OCIE0A);
          Serial.println("Ligado");
        } else { //para o programa
          sent = true;
          parar_programa();
          Serial.println("Desligado");
        }
      }
    }
  } else if (!ctrl) { //botao solto
    ctrl = true; //trigger botao
  }
}
