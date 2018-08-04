/* After your libraries */
#include <M5_UI.h>

/* RootVar's for UI elements (note: not edit manually) */
String UIInputbox_v05700a = "";
String UITextbox_wrtmm38 = "Example #1. Morse";
String UITextbox_y7uzm8u = "Textbox and Inputbox";

/* User functions: */
void Morse(String* rootVar) {
 int MorseCodes[] =
 {
  0,1,-1,-1, // A
  1,0,0,0, // B
  1,0,1,0, // C
  1,0,0,-1, // D
  0,-1,-1,-1, // E
  0,0,1,0,  //F
  1,1,0,-1, // G
  0,0,0,0,  // H
  0,0,-1,-1,  // I
  0,1,1,1, // J
  1,0,1,-1, // K
  0,1,0,0, // L
  1,1,-1,-1, // M
  1,0,-1,-1,  // N
  1,1,1,-1, // O
  0,1,1,0,  // P
  1,1,0,1,  // Q
  0,1,0,-1, // R
  0,0,0,-1, // S
  1,-1,-1,-1, // T
  0,0,1,-1, // U
  0,0,0,1,  // V
  0,1,1,-1, // W
  1,0,0,1,  // X
  1,0,1,1, // Y
  1,1,0,0 // Z
 };
 for (int i = 0; i < UIInputbox_v05700a.length(); i++) {
  char chr = UIInputbox_v05700a[i];
  if (chr == ' ')
  {
    M5.Speaker.mute();
    delay(350);
  }
  else
  {
    int chrNum = (chr - 'a') * 4;
    for (int j = chrNum; j < (chrNum + 4); j++)
    {
      M5.Speaker.tone(440);
      if (MorseCodes[j] == 0)
        delay(50);
      else if (MorseCodes[j] == 1)
        delay(200);
      M5.Speaker.mute();
      delay(150);
    }
  }
 }
}

/* Function for layer default: */
void LayerFunction_default(String* rootVar) {
 /* UI Elements */
 UIInputbox(15,85,290,"default","Enter message",0,&UIInputbox_v05700a);
 UITextbox(15,15,290,20,0x0000,"default",&UITextbox_wrtmm38);
 UITextbox(15,40,290,20,0x0000,"default",&UITextbox_y7uzm8u);
 UIEnter = Morse;
 /* To open this layer use: */
 UILayer("default");
}

void setup() {
 /* Prepare M5STACK */
 M5.begin();

 /* Prepare Wire for FACES */
 Wire.begin();
 pinMode(KEYBOARD_INT, INPUT_PULLUP);

 /* Prepare user's I/O. For example pinMode(5, OUTPUT); */

 /* Prepare UI */
 UIBegin();
 LayerFunction_default(0);
}

void loop() { }
