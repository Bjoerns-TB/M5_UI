/* After your libraries */
#include <M5_UI.h>

/* RootVar's for UI elements (note: not edit manually) */
String UIButton_b7sbmlh = "";
String UIInputbox_pxf2xjc = "";
String UIInputbox_0wfkvpf = "";
String UITextbox_kz6cc2s = "Hello,";

/* Function for layer default: */
void LayerFunction_default(String* rootVar) {
 /* UI Elements */
 UIInputbox(20,10,150,"default","Name",0,&UIInputbox_pxf2xjc);
 UIInputbox(20,70,150,"default","Surname",0,&UIInputbox_0wfkvpf);
 UIButton(200,59,80,"default","OK",(uint16_t*)ICON_27_24,LayerFunction_second,&UIButton_b7sbmlh);
 /* To open this layer use: */
 UILayer("default");
}

/* Function for layer second: */
void LayerFunction_second(String* rootVar) {
 UISet(&UITextbox_kz6cc2s, UITextbox_kz6cc2s + " " + UIInputbox_pxf2xjc + " " + UIInputbox_0wfkvpf + "!");
 /* UI Elements */
 UITextbox(10,35,300,20,0x0000,"second",&UITextbox_kz6cc2s);
 /* To open this layer use: */
 UILayer("second");
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
