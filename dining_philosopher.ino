#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define EATING_LIMIT 2

//the binary semaphores for each of the resources
SemaphoreHandle_t xResourceOneSemaphore;
SemaphoreHandle_t xResourceTwoSemaphore;
SemaphoreHandle_t xResourceThreeSemaphore;
SemaphoreHandle_t xResourceFourSemaphore;
SemaphoreHandle_t xResourceFiveSemaphore;

void processOne(void *pvParameters);
void processTwo(void *pvParameters);
void processThree(void *pvParameters);
void processFour(void *pvParameters);
void processFive(void *pvParameters);

//define the pins for each LED
uint8_t process_1 = 11;
uint8_t process_2 = 9;
uint8_t process_3 = 7;
uint8_t process_4 = 5;
uint8_t process_5 = 13;

uint8_t resource_1 = 10;
uint8_t resource_2 = 8;
uint8_t resource_3 = 6;
uint8_t resource_4 = 4;
uint8_t resource_5 = 12;

void setup()
{
    //opening the serial port
    Serial.begin(9600);
    while (!Serial)
    {
        ;
    }
    //setting all LEDs to OUTPUT
    pinMode(process_1, OUTPUT);
    pinMode(process_2, OUTPUT);
    pinMode(process_3, OUTPUT);
    pinMode(process_4, OUTPUT);
    pinMode(process_5, OUTPUT);

    pinMode(resource_1, OUTPUT);
    pinMode(resource_2, OUTPUT);
    pinMode(resource_3, OUTPUT);
    pinMode(resource_4, OUTPUT);
    pinMode(resource_5, OUTPUT);

    if (xResourceOneSemaphore == NULL)
    {
        xResourceOneSemaphore = xSemaphoreCreateMutex();
        if (xResourceOneSemaphore != NULL)
            xSemaphoreGive(xResourceOneSemaphore);
    }
    if (xResourceTwoSemaphore == NULL)
    {
        xResourceTwoSemaphore = xSemaphoreCreateMutex();
        if (xResourceTwoSemaphore != NULL)
            xSemaphoreGive(xResourceTwoSemaphore);
    }
    if (xResourceThreeSemaphore == NULL)
    {
        xResourceThreeSemaphore = xSemaphoreCreateMutex();
        if (xResourceThreeSemaphore != NULL)
            xSemaphoreGive(xResourceThreeSemaphore);
    }
    if (xResourceFourSemaphore == NULL)
    {
        xResourceFourSemaphore = xSemaphoreCreateMutex();
        if (xResourceFourSemaphore != NULL)
            xSemaphoreGive(xResourceFourSemaphore);
    }
    if (xResourceFiveSemaphore == NULL)
    {
        xResourceFiveSemaphore = xSemaphoreCreateMutex();
        if (xResourceFiveSemaphore != NULL)
            xSemaphoreGive(xResourceFiveSemaphore);
    }

    xTaskCreate(processOne, "process One", 104, NULL, 1, NULL);
    xTaskCreate(processTwo, "process Two", 104, NULL, 1, NULL);
    xTaskCreate(processThree, "process Three", 104, NULL, 1, NULL);
    xTaskCreate(processFour, "process Four", 104, NULL, 1, NULL);
    xTaskCreate(processFive, "For process Five", 104, NULL, 1, NULL);
}

void loop() {}

void processOne(void *pvParamaters __attribute__((unused)))
{
    for (;;)
    {
        if (xSemaphoreTake(xResourceOneSemaphore, (TickType_t)5) == pdTRUE)
        {
            digitalWrite(resource_1, HIGH);
            //Serial.print("P-1 got R-1 ");
            //Serial.println(uxSemaphoreGetCount(xResourceOneSemaphore));
            vTaskDelay(100);
            if (xSemaphoreTake(xResourceFiveSemaphore, (TickType_t)5) == pdTRUE)
            {
                //Serial.print("P-1 to R-5 ");
                //Serial.println(uxSemaphoreGetCount(xResourceFiveSemaphore));
                digitalWrite(resource_5, HIGH);
                digitalWrite(process_1, HIGH);
                vTaskDelay(100);
                digitalWrite(process_1, LOW);
                digitalWrite(resource_5, LOW);
                xSemaphoreGive(xResourceFiveSemaphore);
            }
            digitalWrite(resource_1, LOW);
            xSemaphoreGive(xResourceOneSemaphore);
            vTaskDelay(250);
        }
    }
}
void processTwo(void *pvParamaters __attribute__((unused)))
{
    for (;;)
    {
        if (xSemaphoreTake(xResourceOneSemaphore, (TickType_t)5) == pdTRUE)
        {
            digitalWrite(resource_1, HIGH);
            //Serial.print("P-2 got R-1 ");
            //Serial.println(uxSemaphoreGetCount(xResourceOneSemaphore));
            vTaskDelay(100);
            if (xSemaphoreTake(xResourceTwoSemaphore, (TickType_t)5) == pdTRUE)
            {
                //Serial.print("P-2 to R-2 ");
                //Serial.println(uxSemaphoreGetCount(xResourceTwoSemaphore));
                digitalWrite(resource_2, HIGH);
                digitalWrite(process_2, HIGH);
                vTaskDelay(100);
                digitalWrite(process_2, LOW);
                digitalWrite(resource_2, LOW);
                xSemaphoreGive(xResourceTwoSemaphore);
            }
            digitalWrite(resource_1, LOW);
            xSemaphoreGive(xResourceOneSemaphore);
            vTaskDelay(250);
        }
    }
}
void processThree(void *pvParamaters __attribute__((unused)))
{
    for (;;)
    {
        if (xSemaphoreTake(xResourceThreeSemaphore, (TickType_t)5) == pdTRUE)
        {
            digitalWrite(resource_3, HIGH);
            //Serial.print("P-3 got R-3 ");
            //Serial.println(uxSemaphoreGetCount(xResourceThreeSemaphore));
            vTaskDelay(100);
            if (xSemaphoreTake(xResourceTwoSemaphore, (TickType_t)5) == pdTRUE)
            {
                //Serial.print("P-3 to R-2 ");
                //Serial.println(uxSemaphoreGetCount(xResourceTwoSemaphore));
                digitalWrite(resource_2, HIGH);
                digitalWrite(process_3, HIGH);
                vTaskDelay(100);
                digitalWrite(process_3, LOW);
                digitalWrite(resource_2, LOW);
                xSemaphoreGive(xResourceTwoSemaphore);
            }
            digitalWrite(resource_3, LOW);
            xSemaphoreGive(xResourceThreeSemaphore);
            vTaskDelay(250);
        }
    }
}
void processFour(void *pvParamaters __attribute__((unused)))
{
    for (;;)
    {
        if (xSemaphoreTake(xResourceThreeSemaphore, (TickType_t)5) == pdTRUE)
        {
            digitalWrite(resource_3, HIGH);
            //Serial.print("P-4 got R-3 ");
            //Serial.println(uxSemaphoreGetCount(xResourceThreeSemaphore));
            vTaskDelay(100);
            if (xSemaphoreTake(xResourceFourSemaphore, (TickType_t)5) == pdTRUE)
            {
                //Serial.print("P-4 to R-4 ");
                //Serial.println(uxSemaphoreGetCount(xResourceFourSemaphore));
                digitalWrite(resource_4, HIGH);
                digitalWrite(process_4, HIGH);
                vTaskDelay(100);
                digitalWrite(process_4, LOW);
                digitalWrite(resource_4, LOW);
                xSemaphoreGive(xResourceFourSemaphore);
            }
            digitalWrite(resource_3, LOW);
            xSemaphoreGive(xResourceThreeSemaphore);
            vTaskDelay(250);
        }
    }
}
void processFive(void *pvParamaters __attribute__((unused)))
{
    for (;;)
    {
        if (xSemaphoreTake(xResourceFiveSemaphore, (TickType_t)5) == pdTRUE)
        {
            digitalWrite(resource_5, HIGH);
            //Serial.print("P-5 got R-5 ");
            //Serial.println(uxSemaphoreGetCount(xResourceFiveSemaphore));
            vTaskDelay(100);
            if (xSemaphoreTake(xResourceFourSemaphore, (TickType_t)5) == pdTRUE)
            {
                //Serial.print("P-5 to R-4 ");
                //Serial.println(uxSemaphoreGetCount(xResourceFourSemaphore));
                digitalWrite(resource_4, HIGH);
                digitalWrite(process_5, HIGH);
                vTaskDelay(100);
                digitalWrite(process_5, LOW);
                digitalWrite(resource_4, LOW);
                xSemaphoreGive(xResourceFourSemaphore);
            }
            digitalWrite(resource_5, LOW);
            xSemaphoreGive(xResourceFiveSemaphore);
            vTaskDelay(250);
        }
    }
}
