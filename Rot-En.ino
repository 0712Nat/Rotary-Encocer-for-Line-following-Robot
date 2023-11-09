// Define pins
#define CLK 12
#define DT 11
#define SW 10

// Initialize variables
int counts = 0;
float distance = 0;
float wheel_circumference = 20.0; // in cm
float counts_per_revolution = 20.0;

void setup() {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int CLK_state = digitalRead(CLK);
  int DT_state = digitalRead(DT);
  int SW_state = digitalRead(SW);

  if (CLK_state != DT_state) {
    counts++;
  }

  if (SW_state == LOW) {
    distance = (wheel_circumference * counts) / counts_per_revolution;
    Serial.print("Distance traveled: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}
