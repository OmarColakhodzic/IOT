#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

int crvena1 = D0;
int zelena1 = D1;
int plava1 = D2;

int crvena2 = D3;
int zelena2 = D4;
int plava2 = D5;

int crvena3 = D6;
int zelena3 = D7;
int plava3 = D8;

#define FIREBASE_HOST "raskrsnica-7aceb-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "3b52c10583a8c31420fef3c5b876c3f38649393b"
#define WIFI_SSID "WiFi"
#define WIFI_PASSWORD "sifra"

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  pinMode(crvena1, OUTPUT);
  pinMode(zelena1, OUTPUT);
  pinMode(plava1, OUTPUT);

  pinMode(crvena2, OUTPUT);
  pinMode(zelena2, OUTPUT);
  pinMode(plava2, OUTPUT);

  pinMode(crvena3, OUTPUT);
  pinMode(zelena3, OUTPUT);
  pinMode(plava3, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  FirebaseJson jsonObject = firebaseData.jsonObject();
  int semafor1, semafor2, semafor3;

  if (Firebase.get(firebaseData, "semafor")) {
    jsonObject = firebaseData.jsonObject();
    
    FirebaseJsonData semafor1Data, semafor2Data, semafor3Data;
    if (jsonObject.get(semafor1Data, "semafor1")) {
      semafor1 = semafor1Data.intValue;
    }
    if (jsonObject.get(semafor2Data, "semafor2")) {
      semafor2 = semafor2Data.intValue;
    }
    if (jsonObject.get(semafor3Data, "semafor3")) {
      semafor3 = semafor3Data.intValue;
    }

    if (semafor1 == 1 && semafor2 == 1 && semafor3 == 0) {
      digitalWrite(crvena1, LOW);
      digitalWrite(zelena1, HIGH);
      digitalWrite(plava1, LOW);

      digitalWrite(crvena2, LOW);
      digitalWrite(zelena2, HIGH);
      digitalWrite(plava2, LOW);

      digitalWrite(crvena3, HIGH);
      digitalWrite(zelena3, LOW);
      digitalWrite(plava3, LOW);

    } else if (semafor1 == 0 && semafor2 == 0 && semafor3 == 1) {
      digitalWrite(crvena1, HIGH);
      digitalWrite(zelena1, LOW);
      digitalWrite(plava1, LOW);

      digitalWrite(crvena2, HIGH);
      digitalWrite(zelena2, LOW);
      digitalWrite(plava2, LOW);

      digitalWrite(crvena3, LOW);
      digitalWrite(zelena3, HIGH);
      digitalWrite(plava3, LOW);

    } else if (semafor1 == 1 && semafor2 == 1 && semafor3 == 1) {
      digitalWrite(crvena1, HIGH);
      digitalWrite(zelena1, HIGH);
      digitalWrite(plava1, LOW);

      digitalWrite(crvena2, HIGH);
      digitalWrite(zelena2, HIGH);
      digitalWrite(plava2, LOW);

      digitalWrite(crvena3, HIGH);
      digitalWrite(zelena3, HIGH);
      digitalWrite(plava3, LOW);
      delay(3000);

      digitalWrite(crvena1, LOW);
      digitalWrite(zelena1, HIGH);
      digitalWrite(plava1, LOW);

      digitalWrite(crvena2, LOW);
      digitalWrite(zelena2, HIGH);
      digitalWrite(plava2, LOW);

      digitalWrite(crvena3, HIGH);
      digitalWrite(zelena3, LOW);
      digitalWrite(plava3, LOW);
      delay(3000);

      digitalWrite(crvena1, HIGH);
      digitalWrite(zelena1, HIGH);
      digitalWrite(plava1, LOW);

      digitalWrite(crvena2, HIGH);
      digitalWrite(zelena2, HIGH);
      digitalWrite(plava2, LOW);

      digitalWrite(crvena3, HIGH);
      digitalWrite(zelena3, HIGH);
      digitalWrite(plava3, LOW);
      delay(3000);

      digitalWrite(crvena1, HIGH);
      digitalWrite(zelena1, LOW);
      digitalWrite(plava1, LOW);

      digitalWrite(crvena2, HIGH);
      digitalWrite(zelena2, LOW);
      digitalWrite(plava2, LOW);

      digitalWrite(crvena3, LOW);
      digitalWrite(zelena3, HIGH);
      digitalWrite(plava3, LOW);
      delay(3000);
    } else if (semafor1 == 0 && semafor2 == 0 && semafor3 == 0) {
      digitalWrite(crvena1, HIGH);
      digitalWrite(zelena1, HIGH);
      digitalWrite(plava1, LOW);

      digitalWrite(crvena2, HIGH);
      digitalWrite(zelena2, HIGH);
      digitalWrite(plava2, LOW);

      digitalWrite(crvena3, HIGH);
      digitalWrite(zelena3, HIGH);
      digitalWrite(plava3, LOW);
      }
    delay(1000);
  }
}
