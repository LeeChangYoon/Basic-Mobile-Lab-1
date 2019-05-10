int L_EN = PIN_D0;
int L_DIR_A = PIN_D1; // 00, 01, 10, 11 --> 01, 10 일때만 굴러간다. 00 바로 멈춤, 11 감속하면서 정지
int L_DIR_B = PIN_D2; // 00, 01, 10, 11 --> 01, 10 일때만 굴러간다. 00 바로 멈춤, 11 감속하면서 정지
int R_EN = PIN_B7;
int R_DIR_A = PIN_B2; // 00, 01, 10, 11 --> 01, 10 일때만 굴러간다. 00 바로 멈춤, 11 감속하면서 정지
int R_DIR_B = PIN_B3; // 00, 01, 10, 11 --> 01, 10 일때만 굴러간다. 00 바로 멈춤, 11 감속하면서 정지


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_B2, OUTPUT);
  pinMode(PIN_B3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_D0, HIGH);
  digitalWrite(PIN_D1, HIGH);
  // digitalWrite(PIN_D2, HIGH);
  /*
  digitalWrite(PIN_D1, LOW);
  digitalWrite(PIN_D2, LOW);
  digitalWrite(PIN_D0, LOW);

  
  digitalWrite(PIN_B7, HIGH);
  digitalWrite(PIN_B2, HIGH);
  digitalWrite(PIN_B3, HIGH);
  digitalWrite(PIN_B2, LOW);
  digitalWrite(PIN_B3, LOW);
  digitalWrite(PIN_B7, LOW);
  */
}
