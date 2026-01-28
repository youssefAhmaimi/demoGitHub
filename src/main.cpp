#include <Arduino.h>

SemaphoreHandle_t mutex;  // Récupération du Handle du Mutex

void tache1(void *parametres)
{
  int i = 0;
  while (1)
  {
    xSemaphoreTake(mutex, portMAX_DELAY); // Prise du Mutex
    Serial.printf("Dans la tâche 1 : ");
    delay(1);
    Serial.printf("%d\n", i);
    xSemaphoreGive(mutex); // Libération du Mutex
    i++;
    delay(1000);

  }
}
void tache2(void *parametres)
{
  int i = 100;
  while (1)
  {
    xSemaphoreTake(mutex, portMAX_DELAY); // Prise du Mutex
    Serial.printf("Dans la tâche 2 : ");
    delay(1);
    Serial.printf("%d\n", i);
    xSemaphoreGive(mutex); // Libération du Mutex
    i++;
    delay(1000);

  }
}

void setup()
{
  Serial.begin(115200);
  mutex = xSemaphoreCreateMutex(); // Création du Mutex
  while (!Serial)
    ;
  Serial.printf("Départ\n");
  xTaskCreate(
      tache1,    /* Fonction de la tâche. */
      "Tâche 1", /* Nom de la tâche. */
      10000,     /* Taille de la pile de la tâche */
      NULL,      /* Paramètres de la tâche, NULL si pas de paramètre */
      1,         /* Priorité de la tâche */
      NULL);     /* Pointeur pour récupérer le « handle » de la tâche, optionnel */
  xTaskCreate(
      tache2,    /* Fonction de la tâche. */
      "Tâche 2", /* Nom de la tâche. */
      10000,     /* Taille de la pile de la tâche */
      NULL,      /* Paramètres de la tâche, NULL si pas de paramètre */
      1,         /* Priorité de la tâche */
      NULL);     /* Pointeur pour récupérer le « handle » de la tâche, optionnel */
  vTaskDelete(NULL);
}

void loop()
{
  // Ne s'exécute pas
}








