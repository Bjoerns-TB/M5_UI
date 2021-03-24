#ifndef M5_UI_H
#define M5_UI_H

#include <M5Stack.h> 
#include <Wire.h>
#include <driver/dac.h>

#define KEYBOARD_I2C_ADDR 0X88
#define KEYBOARD_INT 5
#define Char2Width 12
#define Char3Width 16
#define Char2Height 20
#define UIElementsSize 100
#define ButtonA 39
#define ButtonB 38
#define ButtonC 37

//typedef void (*pfunc)(void);
typedef void (*pFuncInt)(int);
typedef void (*pFuncIntChar)(int, char);
typedef void (*pFuncStrP)(String*);

struct UIElement 
{
  bool autonomous;
  bool disabled;
  int focus; // 0 - false, 1 - true, -1 - unavailable
  int x;
  int y;
  int width;
  int height;
  int colorS; // select
  int colorB; // base
  int color;
  int color2;
  int color3;
  int color4;
  int color5;
  int color6;
  int etcInt;
  int etcInt2;
  int etcInt3;
  int etcInt4;
  String type;
  String layer;
  String caption;
  uint16_t* icon;
  String* rootVar;
  pFuncIntChar callout;
  pFuncInt render;
  pFuncStrP callback;
};

int cntChar(String, char);
String parseString(int, char, String);
void reParseString(int, char, String, String*);
int rgbTo565(int, int, int);
int hexTo565(int);
void UIBegin();
void UIUpdate();
void UILayer(String);
void UIRemoveLayer(String);
void UIEraseLayer();
void UIContollerSubThread(void*);
void UIController(void*);
void UIAddChar(char);
void UIFocus(String*);
void UITab();
void UIBackspace();
void UIEmpty(String* rootVar);
void UIArrows(int);
void UISet(String*, String);
void UISet(String*, int);
//void UILabel(String, String, String);
void UIDisable(bool, String*);
void UIOption(String, String, String*);
//String UIOptionValue(String*);
void UICaption(String, String*);
void UIIcon(uint16_t*, String*);
void UIInputboxCallout(int, char);
void UIInputbox(int, int, int, String, String, pFuncStrP, String*);
void UIInputbox(int, int, int, String, String, String*);
void UIDrawInputbox(int);
void UITextbox(int, int, int, int, int, String, String*);
void UIDrawTextbox(int);
void UIWaitingbar(int, int, int, String, String, String*);
void UIDrawWaitingbar(int, char);
void UIProgressbar(int, int, int, String, String, String*);
void UIDrawProgressbar(int);
void UISelectboxCallout(int, char);
void UISelectbox(int, int, int, String, String, pFuncStrP, String*);
void UISelectbox(int, int, int, String, String, String*);
void UIDrawSelectbox(int);
void UICheckboxCallout(int, char);
void UICheckbox(int, int, int, String, String, pFuncStrP, String*);
void UICheckbox(int, int, int, String, String, String*);
void UIDrawCheckbox(int);
void UIButton(int, int, int, String, String, pFuncStrP, String*);
void UIButton(int, int, int, String, String, uint16_t*, pFuncStrP, String*);
void UIDrawButton(int);
void UIRangeboxCallout(int, char);
void UIRangebox(int, int, int, int, int, int, String, String, pFuncStrP, String*);
void UIRangebox(int, int, int, int, int, int, String, String, String*);
void UIDrawRangebox(int);
extern pFuncStrP UIEnter;

extern const unsigned char ICON_0_24[1152];
extern const unsigned char ICON_1_24[1152];
extern const unsigned char ICON_2_24[1152];
extern const unsigned char ICON_3_24[1152];
extern const unsigned char ICON_4_24[1152];
extern const unsigned char ICON_5_24[1152];
extern const unsigned char ICON_6_24[1152];
extern const unsigned char ICON_7_24[1152];
extern const unsigned char ICON_8_24[1152];
extern const unsigned char ICON_9_24[1152];
extern const unsigned char ICON_10_24[1152];
extern const unsigned char ICON_11_24[1152];
extern const unsigned char ICON_12_24[1152];
extern const unsigned char ICON_13_24[1152];
extern const unsigned char ICON_14_24[1152];
extern const unsigned char ICON_15_24[1152];
extern const unsigned char ICON_16_24[1152];
extern const unsigned char ICON_17_24[1152];
extern const unsigned char ICON_18_24[1152];
extern const unsigned char ICON_19_24[1152];
extern const unsigned char ICON_20_24[1152];
extern const unsigned char ICON_21_24[1152];
extern const unsigned char ICON_22_24[1152];
extern const unsigned char ICON_23_24[1152];
extern const unsigned char ICON_24_24[1152];
extern const unsigned char ICON_25_24[1152];
extern const unsigned char ICON_26_24[1152];
extern const unsigned char ICON_27_24[1152];
extern const unsigned char ICON_28_24[1152];
extern const unsigned char ICON_29_24[1152];
extern const unsigned char ICON_30_24[1152];
extern const unsigned char ICON_31_24[1152];
extern const unsigned char ICON_32_24[1152];
extern const unsigned char ICON_33_24[1152];
extern const unsigned char ICON_34_24[1152];
extern const unsigned char ICON_35_24[1152];
extern const unsigned char ICON_36_24[1152];
extern const unsigned char ICON_37_24[1152];
extern const unsigned char ICON_38_24[1152];
extern const unsigned char ICON_39_24[1152];
extern const unsigned char ICON_40_24[1152];


#endif
