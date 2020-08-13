#include <Arduino_FreeRTOS.h>

// Các lệnh I/O của arduino
// digitalRead, digitalWrite,Serial.Print,pinMode

void Task_Controlled(void *param);
void Task_print(void *param);



void setup()
{
  Serial.begin(9600);
  pinmode(8,INPUT_PULLUP);
  pinmode(13,OUTPUT);
  vTaskCreate(Task_Controlled,"Task_Controlled",100,NULL,1,NuLL);
  vTaskCreate(Task_print,"Task_Print",100,NULL,1,NuLL);  
}
}


void loop()
{
  // DO nothing
}

void Task_Controlled(void *param)
{
  while (1)
  {
    if (digitalRead(8) == 0)
    {
      while (digitalRead(8)==0)
      {
        digitalWrite((13),LOW);
      }
    
    }
    else digitalWrite((13),HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);//Délay 1s
  }
  
  void Task_print(void *param)
  {
    void *param;
    while (1)
    {
      Serial.print('Task_print')
      vTaskDelay(1000/portTICK_PERIOD_MS);//Delay 1s
    }
    
  }
    
}

