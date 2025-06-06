const int SENSOR_NIVEL_PIN = A0; 
const int LED_VERDE_PIN = 2;    
const int LED_AMARELO_PIN = 3;  
const int LED_VERMELHO_PIN = 4; 
const int BUZZER_PIN = 5;       

// definição dos limites de nível de água (em metros simulados)
// estes valores são ajustados para o range do potenciômetro e são baseados
// nas regras de negócio do Rio Seguro (2.0m para crítico).
const float NIVEL_NORMAL_MAX = 1.0;  // Até 1.0m: Nível Normal (LED Verde)
const float NIVEL_ATENCAO_MAX = 1.9; // Entre 1.0m e 1.9m: Nível de Atenção (LED Amarelo)
const float NIVEL_CRITICO_MIN = 2.0; // De 2.0m em diante: Nível Crítico (LED Vermelho + Buzzer)

void setup() {
  
  pinMode(LED_VERDE_PIN, OUTPUT);
  pinMode(LED_AMARELO_PIN, OUTPUT);
  pinMode(LED_VERMELHO_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  
  Serial.begin(9600);
}

void loop() {
  int valor_sensor = analogRead(SENSOR_NIVEL_PIN);

  // map() converte o valor_sensor (0-1023) para um range de 0-300.
  // dividimos por 100.0 para obter um valor float em metros (0.0 a 3.0m).
  float nivel_agua_metros = map(valor_sensor, 0, 1023, 0, 300) / 100.0;

  
  // imprime o nível da água atual no Serial Monitor, útil para verificar as leituras.
  Serial.print("Nível da Água: ");
  Serial.print(nivel_agua_metros);
  Serial.println(" m");

  
  // compara o nível atual da água com os limites definidos para ativar os alertas.
  if (nivel_agua_metros < NIVEL_NORMAL_MAX) {
    //Acende o LED Verde, apaga os outros e desliga o buzzer.
    digitalWrite(LED_VERDE_PIN, HIGH);  
    digitalWrite(LED_AMARELO_PIN, LOW);  
    digitalWrite(LED_VERMELHO_PIN, LOW);
    noTone(BUZZER_PIN);                 
  } else if (nivel_agua_metros >= NIVEL_NORMAL_MAX && nivel_agua_metros < NIVEL_CRITICO_MIN) {
    //Acende o LED Amarelo, apaga os outros e desliga o buzzer.
    digitalWrite(LED_VERDE_PIN, LOW);
    digitalWrite(LED_AMARELO_PIN, HIGH);
    digitalWrite(LED_VERMELHO_PIN, LOW);
    noTone(BUZZER_PIN);
  } else { // Se o nível_agua_metros for igual ou maior que NIVEL_CRITICO_MIN
    // Nível Crítico: Acende o LED Vermelho e liga o Buzzer.
    digitalWrite(LED_VERDE_PIN, LOW);
    digitalWrite(LED_AMARELO_PIN, LOW);
    digitalWrite(LED_VERMELHO_PIN, HIGH);
    tone(BUZZER_PIN, 1000);               
  }

  // Pequeno atraso para estabilizar as leituras e evitar leituras muito rápidas.
  delay(500); 
}