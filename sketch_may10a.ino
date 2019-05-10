int L_EN = PIN_B7;
int L_DIR_A = PIN_B2; // Forward --> Left Motor
int L_DIR_B = PIN_B3; // Backward --> Left Motor
int R_EN = PIN_D0;
int R_DIR_A = PIN_D1; // Forward --> Right Motor
int R_DIR_B = PIN_D2; // Backward --> Right Motor

int L_SW;             // Left pin of the Switch
int R_SW;             // Right pin of the Switch


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(R_DIR_A, OUTPUT);
  pinMode(R_DIR_B, OUTPUT);
  pinMode(L_DIR_A, OUTPUT);
  pinMode(L_DIR_B, OUTPUT);
  pinMode(L_SW, INPUT_PULLUP);
  pinMode(R_SW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Make it go forward
  /*
  digitalWrite(L_EN, HIGH);
  digitalWrite(L_DIR_A, HIGH);

  digitalWrite(R_EN, HIGH);
  digitalWrite(R_DIR_A, HIGH);
  */

  digitalWrite(L_EN, HIGH);
  digitalWrite(R_EN, HIGH);
    
  // Switch fuction
  if (digitalWrite(L_SW) == 0) {    
    digitalWrite(L_DIR_B, LOW);
    digitalWrite(L_DIR_A, HIGH);
  }
  else {
    digitalWrite(L_DIR_A, LOW);
    digitalWrite(L_DIR_B, HIGH);
  }

  if (digitalWrite(R_SW) == 0) {    
    digitalWrite(R_DIR_B, LOW);
    digitalWrite(R_DIR_A, HIGH);
  }
  else {
    digitalWrite(R_DIR_A, LOW);
    digitalWrite(R_DIR_B, HIGH);
  }
  
}
