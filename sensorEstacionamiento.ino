
const int ledPin = 9; //Numero del pin del led
const int triggerPin = 12;
const int echoPin = 11;

long duracion;
int distancia;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //Inicializamos el pin digital como salida

  pinMode(triggerPin, OUTPUT); // el pin de trigger como salida
  pinMode(echoPin, INPUT); // el pin de echo como entrada
  Serial.begin(9600); // Inicia la comunicacion
}

void loop() {
  // put your main code here, to run repeatedly:

  // Limpiamos el triggerPin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Seteamos el pin del trigger en alto por 10s
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
   //Leemos el pin de echo, para retornar la onda sonora en microsegundos
   
  duracion = pulseIn(echoPin, HIGH);
  // calculamos distancia
  distancia= (duracion/2)/29.1;

  if (distancia<10){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  // Imprimimos distancia
  Serial.print("Distancia al objeto = ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(1000);

  
  /*
  Prender el LED
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(500);
  */

  

}
