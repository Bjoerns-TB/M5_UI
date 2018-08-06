/* After your libraries */
#include <M5_UI.h>

/* RootVar's for UI elements (note: not edit manually) */
String UITextbox_5265gga = "Example #5. SmartDrill";
String UITextbox_rro45u = "Check, Rangebox, Button";
String UICheckbox_1n9gs0b = "true";
String UIRangebox_ztj619h = "75";
String UIButton_enhu9fc = "";

// User's variables
bool startStatus = false;

void Drill(String* rootVar) {
  startStatus = (startStatus) ? false : true;
  if (startStatus)
  {
    int power = UIRangebox_ztj619h.toInt() * 255 / 100;
    dac_out_voltage(DAC_CHANNEL_1, power);
    if (UICheckbox_1n9gs0b == "true")
    {
      UICaption("WAIT", &UIButton_enhu9fc);
      delay(25000);
      Drill(0);
      return;  
    }
    UICaption("STOP", &UIButton_enhu9fc);
  }
  else
  {
    dac_out_voltage(DAC_CHANNEL_1, 0);
    UICaption("START", &UIButton_enhu9fc);
  }
}

/* Function for layer default: */
void LayerFunction_default(String* rootVar) {
 /* UI Elements */
 UITextbox(15,15,290,20,0x0000,"default",&UITextbox_5265gga);
 UITextbox(15,40,290,20,0x0000,"default",&UITextbox_rro45u);
 UIButton(75,200,170,"default","START",(uint16_t*)ICON_16_24,Drill,&UIButton_enhu9fc);
 UIRangebox(15,85,290,0,100,5,"default","Power",&UIRangebox_ztj619h);
 UICheckbox(15,150,290,"default","Autostop after 25 s",0,&UICheckbox_1n9gs0b);
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
