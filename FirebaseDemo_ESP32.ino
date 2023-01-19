#include <Arduino_JSON.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <IOXhop_FirebaseESP32.h>

WiFiMulti wifiMulti;

String path = "Gate/";
#define FIREBASE_HOST "https://rail-gate-test-db2-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "2MEZAr4A49UrUfnEhD0vfBbzbmo5NJmtgKF4zLYS"

String relay1 = "";
String relay2 = "";
String relay3 = "";
String relay4 = "";
String relay5 = "";
String relay6 = "";

#define relayled1 4
#define relayled2 5
#define relayled3 18
#define relayled4 19
#define relayled5 21
#define relayled6 22

void setup() {
  pinMode(2, OUTPUT);
  pinMode(relayled1, OUTPUT);
  pinMode(relayled2, OUTPUT);
  pinMode(relayled3, OUTPUT);
  pinMode(relayled4, OUTPUT);
  pinMode(relayled5, OUTPUT);
  pinMode(relayled6, OUTPUT);

  Serial.begin(9600);

  wifiMulti.addAP("Galaxy M01 Core7936", "rujb9686");
  wifiMulti.addAP("Dialog", "dinith123");
  wifiMulti.addAP("ICT", "12345678");
  wifiMulti.addAP("School Wi-Fi Zone", "987654321");

  Serial.println("Connecting Wifi...");

  if (wifiMulti.run(5000) == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected!");
    digitalWrite(2, HIGH);
  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  Serial.println("Signuped!");

  while (Firebase.failed()) {
    Serial.println("Signup Issues");
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
  }

  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
  }
  Firebase.setString(path + "Gate1","0");
  Firebase.setString(path + "Gate2","0");
  Firebase.setString(path + "Gate3","0");
  Firebase.setString(path + "Gate4","0");
  Firebase.setString(path + "Gate5","0");
}

// if (Firebase.failed()) {
//   Serial.println(Firebase.error());
// }
void loop() {

  if(Firebase.getString("Gate/Gate1") == "1" || Firebase.getString("Gate/Gate2") == "1"){
  //   relay1 = Firebase.getString("Gate/Gate1");
  // relay2 = Firebase.getString("Gate/Gate2");
  // relay3 = Firebase.getString("Gate/Gate3");
  // relay4 = Firebase.getString("Gate/Gate4");
  // relay5 = Firebase.getString("Gate/Gate5");
  // relay6 = Firebase.getString("Gate/Gate6");

  int relay01 = relay1.toInt();
  int relay02 = relay2.toInt();
  int relay03 = relay3.toInt();
  int relay04 = relay4.toInt();
  int relay05 = relay5.toInt();
  int relay06 = relay6.toInt();

  digitalWrite(relayled1, relay01);
  digitalWrite(relayled2, relay02);
  digitalWrite(relayled3, relay03);
  digitalWrite(relayled4, relay04);
  digitalWrite(relayled5, relay05);
  digitalWrite(relayled6, relay06);

  Serial.print("relay 2 : ");
  Serial.println(relay02);

  Serial.print("relay 3 : ");
  Serial.println(relay03);


  }

  

  // relay1.replace("\\\"", "");
  // relay2.replace("\\\"", "");
  // relay3.replace("\\\"", "");
  // relay4.replace("\\\"", "");
  // relay5.replace("\\\"", "");
  // c

  
}

/*if (relay1 == "1") {
    digitalWrite(relayled1, HIGH);
    getdata;
  } else if (relay1 == "0") {
    digitalWrite(relayled1, LOW);
    getdata;
  } else if (relay2 == "1") {
    digitalWrite(relayled2, HIGH);
    getdata;
  } else if (relay2 == "0") {
    digitalWrite(relayled2, LOW);
    getdata;
  } else if (relay3 == "1") {
    digitalWrite(relayled3, HIGH);
    getdata;
  } else if (relay3 == "0") {
    digitalWrite(relayled3, LOW);
    getdata;
  } else if (relay4 == "1") {
    digitalWrite(relayled4, HIGH);
    getdata;
  } else if (relay4 == "0") {
    digitalWrite(relayled4, LOW);
    getdata;
  } else if (relay5 == "1") {
    digitalWrite(relayled5, HIGH);
    getdata;
  } else if (relay5 == "0") {
    digitalWrite(relayled5, LOW);
    getdata;
  } else if (relay6 == "1") {
    digitalWrite(relayled6, HIGH);
    getdata;
  } else if (relay6 == "0") {
    digitalWrite(relayled6, LOW);
    getdata;
  }*/
//}

/*void getdata() {



  Serial.print("Gate1 : ");
  Serial.print(relay1);
  Serial.print("   ");
  Serial.print("Gate2 : ");
  Serial.println(relay2);

  Serial.print("Gate3 : ");
  Serial.print(relay3);
  Serial.print("   ");
  Serial.print("Gate4 : ");
  Serial.println(relay4);

  Serial.print("Gate5 : ");
  Serial.print(relay5);
  Serial.print("   ");
  Serial.print("Gate6 : ");
  Serial.println(relay6);
  Serial.println("   ");
}*/