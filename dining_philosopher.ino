#include <Arduino_FreeRTOS.h>

uint8_t process_0 = 13;
uint8_t process_1 = 11;
uint8_t process_2 = 9;
uint8_t process_3 = 7;
uint8_t process_4 = 5;

uint8_t resource_0 = 12;
uint8_t resource_1 = 10;
uint8_t resource_2 = 8;
uint8_t resource_3 = 6;
uint8_t resource_4 = 4;

void rotatingBlink(void *pvParamaters);

void setup() 
{
    Serial.begin(9600);
    while (!Serial)
    {
        ;
    }

    xTaskCreate (
        rotatingBlink
        , "Testing to see if the lights are wired correctly"
        , 128
        , NULL
        , 1
        , NULL);
}

void loop(){ }

void rotatingBlink(void *pvParamaters __attribute__((unused)) ) {
    pinMode(process_0, OUTPUT);
    pinMode(process_1, OUTPUT);
    pinMode(process_2, OUTPUT);
    pinMode(process_3, OUTPUT);
    pinMode(process_4, OUTPUT);

    pinMode(resource_0, OUTPUT);
    pinMode(resource_1, OUTPUT);
    pinMode(resource_2, OUTPUT);
    pinMode(resource_3, OUTPUT);
    pinMode(resource_4, OUTPUT);

    digitalWrite(process_0, HIGH);
    digitalWrite(process_1, HIGH);
    digitalWrite(process_2, HIGH);
    digitalWrite(process_3, HIGH);
    digitalWrite(process_4, HIGH);

    digitalWrite(resource_0, HIGH);
    digitalWrite(resource_1, HIGH);
    digitalWrite(resource_2, HIGH);
    digitalWrite(resource_3, HIGH);
    digitalWrite(resource_4, HIGH);

    Serial.println("here!");

}