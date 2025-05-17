const int sensorPin = A0;    
const int relePin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(relePin, OUTPUT);      
  digitalWrite(relePin, HIGH);   
  Serial.println("🌱 Sensor de Umidade Pronto!");
}

void loop() {
  int leitura = analogRead(sensorPin);
  Serial.print("Valor da umidade: ");
  Serial.println(leitura);

  if (leitura < 500) {
    Serial.println("💧 Solo molhado");
    digitalWrite(relePin, HIGH);  
  } else {
    Serial.println("🌵 Solo seco");
    digitalWrite(relePin, LOW);  
  }

  Serial.println("------------------");
  delay(1000);
}