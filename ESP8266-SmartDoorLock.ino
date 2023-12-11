

#include <FirebaseESP8266.h>
#include  <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>

#define ssid "ADASDAW"  //WiFi SSID
#define password "12345678"  //WiFi Password
#define FIREBASE_HOST ""       //Firebase Project URL Remove "https:" , "\" and "/"
#define FIREBASE_AUTH ""      //Firebase Auth Token

FirebaseData firebaseData;

//If using Relay Module
int Device_1 = 2; //relay
#define SS_PIN 15
#define RST_PIN 5

MFRC522 rfid(SS_PIN, RST_PIN);

byte keytagUID[4] = {0x83, 0xB8, 0x66, 0x10};

FirebaseJson json;
String status;
String fireStatus;
void post_to_firebase(String data);
boolean waitResponse(String expected_answer="OK", unsigned int timeout=2000);
void setup() {
  
   Serial.begin(115200);
   SPI.begin();
   rfid.PCD_Init();
   WiFi.begin (ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  pinMode(Device_1,OUTPUT);//initialize the Device OUTPUT  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  Serial.println("Tap an RFID/NFC tag on the RFID-RC522 reader");

}

void loop() {
bacaFirebase();
bacaRFID();
delay(500);
}

void bacaFirebase(){
   if (Firebase.get(firebaseData,"/SmartDoorLock/status")) {
    if (firebaseData.dataType() == "string") {
      String De1 = firebaseData.stringData();
          if (De1=="1"){
              
              digitalWrite(Device_1,HIGH); //Device1 is ON
              Serial.println("relay nyala");
              delay(500);
            
          }
          else if (De1=="0"){
              digitalWrite(Device_1,LOW);//Device1 if OFF
              Serial.println("relay mati");
            }}}
}
void bacaRFID() {
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      Serial.println("Kartu terdeteksi!");

      Serial.print("UID Kartu: ");
      for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print(" ");
      }
      Serial.println();

      if (rfid.uid.uidByte[0] == keytagUID[0] &&
          rfid.uid.uidByte[1] == keytagUID[1] &&
          rfid.uid.uidByte[2] == keytagUID[2] &&
          rfid.uid.uidByte[3] == keytagUID[3]) {
        Serial.println("AKSES BERHASIL");
        bukaPintu();
      } else {
        Serial.println("akses gagal bro");
        status = "SALAH";
        Firebase.setString(firebaseData, "/SmartDoorLock/keterangan", status);
        delay(500);
      }
      rfid.PICC_HaltA();
    }
  }
}
void bukaPintu() {
  digitalWrite(Device_1, HIGH);
  status = "BENAR";
  Firebase.setString(firebaseData, "/SmartDoorLock/keterangan", status);
  delay(500);
}
