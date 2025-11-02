/*
 * ╔════════════════════════════════════════════════════════╗
 * ║   ESP32 → STM32F4 via UART (NO RESISTORS NEEDED!)     ║
 * ║              SIMPLE & RELIABLE                         ║
 * ╚════════════════════════════════════════════════════════╝
 * 
 * Wiring (Only 2 wires!):
 * -----------------------
 * ESP32 GPIO17 (TX) ───> STM32 PA3 (USART2_RX)
 * ESP32 GND         ───> STM32 GND
 * 
 * That's it! NO resistors needed!
 * 
 * Upload Instructions:
 * --------------------
 * 1. Open Arduino IDE
 * 2. Tools → Board → ESP32 Dev Module
 * 3. Upload this code
 * 4. Open Serial Monitor (115200 baud)
 * 
 * Testing:
 * --------
 * Press BOOT button → STM32 LED turns ON
 * Release button → LED turns OFF
 */

#define BUTTON_PIN 0          // BOOT button
#define TX_PIN 17             // UART TX to STM32
#define RX_PIN 16             // UART RX (optional)
#define BAUD_RATE 9600

// Button state
int lastButtonState = HIGH;
int currentButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  // USB Serial for debugging
  Serial.begin(115200);
  delay(500);
  
  Serial.println("\n╔════════════════════════════════════╗");
  Serial.println("║  ESP32 → STM32 UART (Simple!)     ║");
  Serial.println("╚════════════════════════════════════╝\n");
  
  // UART to STM32
  Serial2.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
  
  // Button
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  Serial.println("✓ UART: 9600 baud");
  Serial.println("✓ TX: GPIO17 → STM32 PA3");
  Serial.println("✓ Button: GPIO0\n");
  Serial.println("Press BOOT button!\n");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentButtonState) {
      currentButtonState = reading;
      
      if (currentButtonState == LOW) {
        // Button PRESSED
        Serial.println("🔘 PRESSED!");
        Serial2.write('L');  // Send LED ON
        Serial.println("  → Sent: 'L' (LED ON)\n");
      }
      else {
        // Button RELEASED
        Serial.println("🔘 RELEASED!");
        Serial2.write('F');  // Send LED OFF
        Serial.println("  → Sent: 'F' (LED OFF)\n");
      }
    }
  }
  
  lastButtonState = reading;
  
  // Heartbeat
  static unsigned long lastHeart = 0;
  if (millis() - lastHeart > 10000) {
    lastHeart = millis();
    Serial.print("💓 Running (");
    Serial.print(millis() / 1000);
    Serial.println(" sec)");
  }
  
  delay(10);
}
