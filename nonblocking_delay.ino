#define ULONG_MAX 4294967295UL

unsigned long previousTime = 0;
unsigned long delayTime = 1000; // Delay time in milliseconds

void setup() {
  // Your setup code here
  Serial.begin(9600);
}

void loop() {
  // Non-blocking delay
  unsigned long currentTime = millis();
  
  if (currentTime >= previousTime) {
    if (currentTime - previousTime >= delayTime) {
      previousTime = currentTime;
      
      // Your code here
      // Code that you want to execute after the delay
      Serial.println("Delay complete");
    }
  } else {
    if ((ULONG_MAX - previousTime) + currentTime >= delayTime) {
      previousTime = currentTime;
      
      // Your code here
      // Code that you want to execute after the delay
      Serial.println("Delay complete");
    }
  }
  
  // Rest of your loop code here
}
