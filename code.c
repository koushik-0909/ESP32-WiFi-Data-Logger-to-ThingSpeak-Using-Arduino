#include <SoftwareSerial.h>

#define RX 3
#define TX 2
SoftwareSerial esp01(RX, TX);
String WIFI_SSID = "ONE Plus Nord"; //Have to Change
String WIFI_PASS = "vamsi123"; //Have to Change 
String API = "XCQXHA8AHGZY8FAG"; // Have to Change
String HOST = "api.thingspeak.com";
String PORT = "80";

int countTrueCommand;
int countTimeCommand;
boolean found = false;
int dummyValue = 0;


void setup() {
  Serial.begin(115200);
  esp01.begin(115200);

  sendCommand("AT", 5, "OK");
  sendCommand("AT+CWMODE=1", 5, "OK");
  sendCommand("AT+CWJAP=\"" + WIFI_SSID + "\",\"" + WIFI_PASS + "\"", 20, "OK");
}

void loop() {
  dummyValue++;
  Serial.print("Sending dummy value: ");
  Serial.println(dummyValue);

  String getData = "GET /update?api_key=" + API + "&field1=" + String(dummyValue);

  sendCommand("AT+CIPMUX=1", 5, "OK");
  sendCommand("AT+CIPSTART=0,\"TCP\",\"" + HOST + "\"," + PORT, 15, "OK");
  sendCommand("AT+CIPSEND=0," + String(getData.length() + 4), 4, ">");

  esp01.println(getData);
  delay(1500);

  countTrueCommand++;
  sendCommand("AT+CIPCLOSE=0", 5, "OK");
  delay(20000);
}

void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". AT command => ");
  Serial.print(command);
  Serial.print(" ");
 
  countTimeCommand = 0;

  while (countTimeCommand < (maxTime * 1)) {
    esp01.println(command);
    if (esp01.find(readReplay)) {
      found = true;
      break;
    }
    countTimeCommand++;
  }

  if (found) {
    Serial.println("OK");
    countTrueCommand++;
  } else {
    Serial.println("Fail");
    countTrueCommand = 0;
  }

  found = false;
}  
