int stop_distance = 12;// Kho?ng cách phát hi?n v?t c?n
//K?t n?i SRF 05 OR 04
const int trigPin = 11; // k?t n?i chân trig c?a HFSR-04 v?i chân 11 arduino
const int echoPin = 12; // k?t n?i chân echo c?a HFSR-04 v?i chân 12 arduino

//L298 k?t n?i arduino
const int motorA1      = 3;  // k?t n?i chân IN1 v?i chân 3 arduino
const int motorA2      = 4;  // k?t n?i chân IN2 v?i chân 4 arduino
const int motorAspeed  = 5;  // k?t n?i chân ENA v?i chân 5 arduino
const int motorB1      = 7; // k?t n?i chân IN3 v?i chân 7 arduino
const int motorB2      = 8; // k?t n?i chân IN4 v?i chân 8 arduino
const int motorBspeed  = 6;  // k?t n?i chân ENB v?i chân 6 arduino

//k?t n?i c?a 3 c?m bi?n h?ng ngo?i (dò line )
const int L_S = 9; // cb dò line ph?i
const int S_S = 2; // cb dò line gi?a
const int R_S = 10; //cb dò line trái

int left_sensor_state;// bi?n luu c?m bi?n h?ng ngo?i line trái
int s_sensor_state;   // bi?n luu c?m bi?n h?ng ngo?i line gi?a
int right_sensor_state;// bi?n luu c?m bi?n h?ng ngo?i line ph?i

long duration; //
int distance;  // bi?n kho?ng cách
void setup() {
  pinMode(L_S, INPUT); // chân c?m bi?n khai báo là d?u vào
  pinMode(R_S, INPUT);
  pinMode(S_S, INPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorAspeed, OUTPUT);
  pinMode(motorBspeed, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  analogWrite(motorAspeed, 110); // t?c d? d?ng co a ban d?u 120 ( 0 - 255)
  analogWrite(motorBspeed, 110);// t?c d? d?ng co b ban d?u 120 ( 0 - 255)
  delay(2000);

}

void loop() {
  //khai báo s? d?ng c?a HC-SR04 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  // Cam bien do` line
  left_sensor_state = digitalRead(L_S);
  s_sensor_state = digitalRead(S_S);
  right_sensor_state = digitalRead(R_S);

      //Cam Bien Trai             //Cam Bien Giua            //Cam bien Phai
  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
    forword(); // di ti?n
  }

  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
    turnLeft(); // r? trái
  }
  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 0)) {
    turnLeft(); // r? trái
  }

  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
    turnRight(); // r? ph?i
  }
  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 1)) {
    turnRight(); // r? ph?i
  }

  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
    Stop(); // stop
  }



  if (distance < stop_distance) // n?u kho?ng cách nh? hon gi?i h?n
  {

    digitalWrite (motorA1, HIGH); // cho xe robot ch?y lùi 1 do?n
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    delay(350);

    digitalWrite (motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(300);


    digitalWrite (motorA1, HIGH); // cho xe robot xoay sang trái
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    delay(400);
    digitalWrite (motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(200);

    digitalWrite (motorA1, LOW); //cho xe robot di th?ng 1 do?n
    digitalWrite(motorA2, HIGH);
    digitalWrite (motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    delay(600);
    digitalWrite (motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(200);


    digitalWrite (motorA1, LOW); // cho xe robot xoay ph?i 1 do?n
    digitalWrite(motorA2, HIGH);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(550);
    digitalWrite (motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(200);

    ///////////////////
    digitalWrite (motorA1, LOW); //cho xe robot di th?ng 1 do?n
    digitalWrite(motorA2, HIGH);
    digitalWrite (motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    delay(600); 
    digitalWrite (motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(200);

    ////////////////////////
    digitalWrite (motorA1, LOW); //cho xe robot xoay ph?i 1 do?n
    digitalWrite(motorA2, HIGH);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(500);
    digitalWrite (motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, LOW);
    delay(200);

    digitalWrite (motorA1, LOW); //cho xe robot di th?ng 1
    digitalWrite(motorA2, HIGH);
    digitalWrite (motorB1, HIGH);
    digitalWrite(motorB2, LOW);

    while (left_sensor_state == LOW) {

      left_sensor_state = digitalRead(L_S);
      s_sensor_state = digitalRead(S_S);
      right_sensor_state = digitalRead(R_S);
      Serial.println("in the first while");

    }

  }
}

void forword() { // chuong trình con xe robot di ti?n

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite (motorB1, HIGH);
  digitalWrite(motorB2, LOW);


void turnRight() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnLeft() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void Stop() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, LOW);
}