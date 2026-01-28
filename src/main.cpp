#include <Arduino.h>



void maTache(void *parametres)
{
  int v1 = 0;
  static int v2 = 0;
  while (1) // boucle infinie
  {
    Serial.printf("%s : v1=%d v2=%d\n", pcTaskGetName(NULL), v1, v2);
    v1++;
    v2++;
    delay(500);
  }
}

void maTache2(void *parametres)
{
  int v1 = 4;
  static int v3 = 4;
  while (1) // boucle infinie
  {
    Serial.printf("%s : v1=%d v3=%d\n", pcTaskGetName(NULL), v1, v3);
    v1++;
    v3++;
    delay(500);
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.printf("Initialisation\n");

  // Création de la tâche maTache
  xTaskCreate(maTache2, "maTache2", 10000, NULL, 2, NULL);
  xTaskCreate(maTache, "maTache", 10000, NULL, 2, NULL);
  
}


void loop()
{
  static int i = 0;
  Serial.printf("Boucle principale : %d\n", i++);
  delay(1000);
}
