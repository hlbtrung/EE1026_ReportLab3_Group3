#define BTNLED_H
#define LED4 10
#define LED2 6
#define LED3 2
#define BTN1 A0
#define BTN2 A1
#define BTN3 A2
#define BUZZER 11
// function init Gpio button and led
void initGpio(void);

//function onoff led
void controlLed(int ledNumber, int stt);

// function button press return true
bool btnPush(int btnNumber);

void buzzer(int time_ms);
