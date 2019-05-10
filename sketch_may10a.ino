int L_EN = PIN_B7;
int L_DIR_A = PIN_B2; // Forward --> Left Motor
int L_DIR_B = PIN_B3; // Backward --> Left Motor
int R_EN = PIN_D0;
int R_DIR_A = PIN_D1; // Forward --> Right Motor
int R_DIR_B = PIN_D2; // Backward --> Right Motor


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


  // Make it go forward
  digitalWrite(PIN_D0, HIGH);
  digitalWrite(PIN_D1, HIGH);

   digitalWrite(PIN_B7, HIGH);
   digitalWrite(PIN_B2, HIGH);
}
