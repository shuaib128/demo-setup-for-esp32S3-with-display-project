#include <Arduino.h>
#include <TFT_eSPI.h> // Hardware-specific library

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

void setup(void)
{
  Serial.begin(115200);
  delay(1000); // Give time to establish the connection
  Serial.println("Starting...");

  // Initialize the display
  Serial.println("Initializing display...");
  tft.init();
  Serial.println("Display initialized.");

  // Fill screen with red
  Serial.println("Filling screen with red...");
  tft.fillScreen(TFT_RED);
  Serial.println("Screen filled with red.");

  // Set the font color to white with a red background
  tft.setTextColor(TFT_WHITE, TFT_RED);

  // Set text size
  tft.setTextSize(2);

  // Text to display
  String text = "Shuaib Ahamed Sam";

  // Calculate the width of the text using the drawString method
  int16_t textWidth = tft.textWidth(text);

  // Calculate the height of the text
  int16_t textHeight = tft.fontHeight();

  // Calculate coordinates to center the text
  int16_t centerX = (tft.width() - textWidth) / 2;
  int16_t centerY = (tft.height() - textHeight) / 2;

  // Set cursor to the calculated coordinates
  tft.setCursor(centerX, centerY);

  // Print text on the screen
  tft.println(text);
  Serial.println("Text printed.");
}

void loop()
{
  // Nothing to do here
}