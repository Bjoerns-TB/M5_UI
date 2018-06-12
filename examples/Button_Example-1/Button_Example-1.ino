#include <M5_UI.h>

int pin = 5;
int state = LOW;
String myLayerButton1 = "";
String myLayerTextbox1 = "UI. Example #1";

void lamp(String *rootVar) {
  if (state == LOW)
  {
    state = HIGH;
    digitalWrite(pin, state);
    UICaption("Turn off", &myLayerButton1);
    UIIcon((uint16_t*)ICON_3_24, &myLayerButton1);
  }
  else
  {
    state = LOW;
    digitalWrite(pin, state);
    UICaption("Turn on", &myLayerButton1);
    UIIcon((uint16_t*)ICON_2_24, &myLayerButton1);
  }
  delay(300);
}

void setup() {
  M5.begin();
  
  // FACES
  Wire.begin();
  pinMode(KEYBOARD_INT, INPUT_PULLUP);
  
  // User
  pinMode(pin, OUTPUT);
  
  // UI Part
  UIBegin();
  UITextbox(60, 50, 200, 50, "myLayer", &myLayerTextbox1, rgbTo565(153, 0, 255));
  UIButton(60, 80, 200, "myLayer", "On", (uint16_t*)ICON_2_24, lamp, &myLayerButton1);
  UILayer("myLayer");
}

void loop() {
  
}
