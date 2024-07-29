#include <Arduino.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include "image1.h"
#include "image2.h"
#include "image3.h"
#include "image4.h"

TFT_eSPI tft = TFT_eSPI();
// Invoke custom library
const uint16_t *images[] = {image_data_image1, image_data_image2, image_data_image3, image_data_image4};
// Add other images as needed
const int num_images = sizeof(images) / sizeof(images[0]);
const int display_duration = 5000; // Display each image for 5000 milliseconds (5 seconds)

void setup(void)
{
  Serial.begin(115200);
  delay(1000); // Give time to establish the connection
  Serial.println("Starting...");

  // Initialize the display
  Serial.println("Initializing display...");
  tft.init();
  Serial.println("Display initialized.");

  // Set up the backlight control pin
  // Attach the pin to a channel
  ledcAttachPin(BACKLIGHT_PIN, 1);
  // Set up the channel with 5 kHz frequency and 8-bit resolution
  ledcSetup(1, 5000, 8);
  // Set the brightness to 50% (128 out of 255)
  ledcWrite(1, 128);

  // Fill screen with black
  Serial.println("Filling screen with black...");
  tft.fillScreen(TFT_BLACK);
  Serial.println("Screen filled with black.");
}

void loop()
{
  for (int i = 0; i < num_images; i++)
  {
    // Display the current image
    Serial.println("Displaying image...");
    tft.pushImage(0, 0, 240, 240, images[i]);
    Serial.println("Image displayed.");

    // Wait for the specified duration
    delay(display_duration);
  }
}
