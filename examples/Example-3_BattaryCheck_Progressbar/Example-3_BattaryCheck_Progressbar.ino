/* After your libraries */
#include <M5_UI.h>

/* RootVar's for UI elements (note: not edit manually) */
String UIProgressbar_1mlmhcu = "0";
String UITextbox_f2hpjlm = "Example #3. BatteryCheck";
String UITextbox_1g50hx5 = "Percentage";
String UITextbox_wm0ptf8 = "Voltage, mV:";
String UITextbox_gtaetjh = "0";

/* Function for layer default: */
void LayerFunction_default(String* rootVar) {
 /* UI Elements */
 UIProgressbar(15,85,290,"default","Battary tester",&UIProgressbar_1mlmhcu);
 UITextbox(15,15,290,20,0x0000,"default",&UITextbox_f2hpjlm);
 UITextbox(15,40,290,20,0x0000,"default",&UITextbox_1g50hx5);
 UITextbox(15,175,150,20,0x0000,"default",&UITextbox_wm0ptf8);
 UITextbox(185,175,80,20,0x0000,"default",&UITextbox_gtaetjh);
 /* To open this layer use: */
 UILayer("default");
 // BattaryCheck
 while(true) {
  int voltage = analogRead(35) * 3400 / 4096;
  int percentage = voltage * 100 / 1600;
  UISet(&UIProgressbar_1mlmhcu, percentage);
  UISet(&UITextbox_gtaetjh, voltage);
  delay(500);
 }
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

