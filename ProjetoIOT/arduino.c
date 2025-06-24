const int sensor1Pin = A0;     // Sensor 1 (umidade) no pino A0
const int sensor2Pin = A1;     // Sensor 2 (umidade) no pino A1
const int rele1Pin = 7;        // Relé 1 no pino digital 7 (controlado por A0)
const int rele2Pin = 8;        // Relé 2 no pino digital 8 (controlado por A1)
 
void setup() {
  Serial.begin(9600);
 
  pinMode(rele1Pin, OUTPUT);
  pinMode(rele2Pin, OUTPUT);
 
  // Inicializa os relés desligados (HIGH se relé for ativo em LOW)
  digitalWrite(rele1Pin, HIGH);
  digitalWrite(rele2Pin, HIGH);
 
  Serial.println("🌱 Sistema de Irrigação com 2 sensores pronto!");
}
 
void loop() {
  int leitura1 = analogRead(sensor1Pin);
  int leitura2 = analogRead(sensor2Pin);
 
  Serial.print("Sensor A0 (zona 1): ");
  Serial.println(leitura1);
 
  Serial.print("Sensor A1 (zona 2): ");
  Serial.println(leitura2);
 
  // Controle do relé 1 com base na leitura do sensor A0
  if (leitura1 > 10) {
    Serial.println("💧 Zona 1 molhada");
    digitalWrite(rele1Pin, HIGH);  // Desliga a bomba/solenoide da zona 1
  } else {
    Serial.println("🌵 Zona 1 seca");
    digitalWrite(rele1Pin, LOW);   // Liga a bomba/solenoide da zona 1
  }
 
  // Controle do relé 2 com base na leitura do sensor A1
  if (leitura2 < 300) {
    Serial.println("💧 Zona 2 molhada");
    digitalWrite(rele2Pin, HIGH);  // Desliga a bomba/solenoide da zona 2
  } else {
    Serial.println("🌵 Zona 2 seca");
    digitalWrite(rele2Pin, LOW);   // Liga a bomba/solenoide da zona 2
  }
 
  Serial.println("------------------");
  delay(1000);
}


consigo colocar um servidor para parar uma bomba manualmente ?