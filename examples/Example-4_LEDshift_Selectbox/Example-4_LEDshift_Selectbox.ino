/* After your libraries */
#include <M5_UI.h>

/* RootVar's for UI elements (note: not edit manually) */
String UITextbox_f2hpjlm = "Example #4. LEDshift";
String UITextbox_1g50hx5 = "Selectbox";
String UISelectbox_6foo6h = "";
// Shift register pinout
int SH_CP = 17;
int ST_CP = 2;
int DS = 5;

/* User functions: */
void SelectColor(String* rootVar) {
  int led = UIOptionValue(&UISelectbox_6foo6h).toInt();
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, MSBFIRST, led);
  digitalWrite(ST_CP, HIGH);
  delay(100);
}

/* Function for layer default: */
void LayerFunction_default(String* rootVar) {
 // add options to Selectbox
 UIOption("OFF", "0", &UISelectbox_6foo6h);
 UIOption("RED", "17", &UISelectbox_6foo6h);
 UIOption("YELLOW", "3", &UISelectbox_6foo6h);
 UIOption("GREEN", "5", &UISelectbox_6foo6h);
 UIOption("ORANGE", "9", &UISelectbox_6foo6h);
 /* UI Elements */
 UITextbox(15,15,290,20,0x0000,"default",&UITextbox_f2hpjlm);
 UITextbox(15,40,290,20,0x0000,"default",&UITextbox_1g50hx5);
 UISelectbox(15,85,290,"default","Select color",0,&UISelectbox_6foo6h);
 UIEnter = SelectColor;
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
 pinMode(SH_CP, OUTPUT);
 pinMode(ST_CP, OUTPUT);
 pinMode(DS, OUTPUT);
 
 /* Prepare UI */
 UIBegin();
 LayerFunction_default(0);
}

void loop() { }

