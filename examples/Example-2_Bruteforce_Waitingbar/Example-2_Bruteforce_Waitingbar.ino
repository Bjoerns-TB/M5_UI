/* After your libraries */
#include <M5_UI.h>

/* RootVar's for UI elements (note: not edit manually) */
String UITextbox_su80zbc = "Example #2. Bruteforce";
String UITextbox_7mwlf63l = "Waitingbar";
String UIWaitingbar_yksk2w8 = "";
String UITextbox_sxjzx0g = "00000000"; // okey
String UITextbox_eyar2x = "00000000"; // key

/* User functions: */
void Brutforce(String* rootVar) {
  /* make random original key */
  uint8_t okey = random(0, 256); 
  String okeyString = "";
  for (int i = 0; i < 8; i++) {
    okeyString += String((okey >> i) & 1);
  }
  UISet(&UITextbox_sxjzx0g, okeyString); // set value for Textbox
  
  UIDisable(false, &UIWaitingbar_yksk2w8); // show the Waitingbar

  uint8_t key;
  
  while (true) {
    key++;
    String keyString = String();
    for (int i = 0; i < 8; i++) {
      keyString += String((key >> i) & 1);
    }
    UISet(&UITextbox_eyar2x, keyString);
    Serial.print(key);
    Serial.print(" ");
    Serial.println(okey);
    if (key == okey) break;
    M5.Speaker.tone(800);
    delay(40);
    M5.Speaker.mute();
  }
  UIDisable(true, &UIWaitingbar_yksk2w8);
  M5.Speaker.tone(600);
  delay(75);
  M5.Speaker.mute();
  M5.Speaker.tone(800);
  delay(75);
  M5.Speaker.mute();
  M5.Speaker.tone(500);
  delay(75);
  M5.Speaker.mute();
}

/* Function for layer default: */
void LayerFunction_default(String* rootVar) {
 /* UI Elements */
 UITextbox(15,15,290,20,0x0000,"default",&UITextbox_su80zbc);
 UITextbox(15,40,290,20,0x0000,"default",&UITextbox_7mwlf63l);
 UIWaitingbar(15,161,290,"default","Waitingbar",&UIWaitingbar_yksk2w8);
 UIEnter = Brutforce;
 UITextbox(105,80,110,20,0x0000,"default",&UITextbox_sxjzx0g);
 UITextbox(105,110,110,20,0x0000,"default",&UITextbox_eyar2x);
 UIDisable(true, &UIWaitingbar_yksk2w8);
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
