#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#include <WiFi.h>
#include <time.h>

#include "arduino_secrets.h"

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASS;

const char* ntpServer = "pool.ntp.org";
const char* TZ = "AEST-10AEDT,M10.1.0,M4.1.0/3";

#define TFT_SCLK 9
#define TFT_MOSI 10
#define TFT_RST -1
#define TFT_DC 8
#define TFT_CS 6

enum TimeMode {
    AUTO,
    MANUAL
};

TimeMode timeMode = AUTO;

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void updateTime() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
        return;
    }
    char timeStringBuff[50];
    strftime(timeStringBuff, sizeof(timeStringBuff), "%H:%M:%S", &timeinfo);
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(3);
    tft.print(timeStringBuff);
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        attempts++;
        if (attempts > 20) {
            break;
        }
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected to WiFi");
        configTime(0, 0, ntpServer);
        setenv("TZ", TZ, 1);
        tzset();
    } else {
        Serial.println("Failed to connect to WiFi. Please set time manually."); // @TODO: Will add manual time setting later.
        timeMode = MANUAL;
    }

    // ====================== Copied from BLARE guide ======================
    tft.init(76, 284); // Our panel size (portrait)
    tft.setOffsets(82, 18); // Offsets for the weird resolution
    tft.invertDisplay(false); // Invert the colors (This display is flipped from normal)
    tft.setRotation(1); // Landscape, if it's upside down use 3!
    tft.fillScreen(ST77XX_BLACK); // clear the screen
    Serial.println("TFT Initialized!");
    tft.setCursor(0,0); // make the cursor at the top left
    // =====================================================================
}

void loop() {
    if (timeMode == AUTO) {
        updateTime();
    }
    delay(500);
}
