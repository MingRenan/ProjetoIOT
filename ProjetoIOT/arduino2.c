const int sensor1Pin = A0;     // Sensor 1 (umidade) no pino A0
const int sensor2Pin = A1;     // Sensor 2 (umidade) no pino A1
const int rele1Pin = 7;        // Relé 1 no pino digital 7 (zona 1)
const int rele2Pin = 8;        // Relé 2 no pino digital 8 (zona 2)

bool modoManual = false;
bool estadoRele1 = false;
bool estadoRele2 = false;

void setup() {
  Serial.begin(9600);

  pinMode(rele1Pin, OUTPUT);
  pinMode(rele2Pin, OUTPUT);

  digitalWrite(rele1Pin, HIGH);
  digitalWrite(rele2Pin, HIGH);

  Serial.println("🌱 Sistema de Irrigação com 2 sensores pronto!");
  Serial.println("Comandos via Serial:");
  Serial.println("  auto         - modo automático");
  Serial.println("  ligar1       - ligar zona 1");
  Serial.println("  desligar1    - desligar zona 1");
  Serial.println("  ligar2       - ligar zona 2");
  Serial.println("  desligar2    - desligar zona 2");
}

void loop() {
  // Leitura de comandos via Serial
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "auto") {
      modoManual = false;
      Serial.println("🔁 Modo automático ativado.");
    } else if (comando == "ligar1") {
      modoManual = true;
      estadoRele1 = true;
      Serial.println("💧 Zona 1 ligada manualmente.");
    } else if (comando == "desligar1") {
      modoManual = true;
      estadoRele1 = false;
      Serial.println("🛑 Zona 1 desligada manualmente.");
    } else if (comando == "ligar2") {
      modoManual = true;
      estadoRele2 = true;
      Serial.println("💧 Zona 2 ligada manualmente.");
    } else if (comando == "desligar2") {
      modoManual = true;
      estadoRele2 = false;
      Serial.println("🛑 Zona 2 desligada manualmente.");
    } else {
      Serial.println("❓ Comando inválido.");
    }
  }

  int leitura1 = analogRead(sensor1Pin);
  int leitura2 = analogRead(sensor2Pin);

  Serial.print("Sensor A0 (zona 1): ");
  Serial.println(leitura1);
  Serial.print("Sensor A1 (zona 2): ");
  Serial.println(leitura2);

  if (modoManual) {
    digitalWrite(rele1Pin, estadoRele1 ? LOW : HIGH);
    digitalWrite(rele2Pin, estadoRele2 ? LOW : HIGH);
  } else {
    // Controle automático dos relés
    if (leitura1 > 10) {
      Serial.println("💧 Zona 1 molhada");
      digitalWrite(rele1Pin, HIGH);  // Desliga a bomba
    } else {
      Serial.println("🌵 Zona 1 seca");
      digitalWrite(rele1Pin, LOW);   // Liga a bomba
    }

    if (leitura2 < 300) {
      Serial.println("💧 Zona 2 molhada");
      digitalWrite(rele2Pin, HIGH);  // Desliga a bomba
    } else {
      Serial.println("🌵 Zona 2 seca");
      digitalWrite(rele2Pin, LOW);   // Liga a bomba
    }
  }

  Serial.println("------------------");
  delay(1000);
}
