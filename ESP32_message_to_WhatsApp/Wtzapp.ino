// Simple trigger to send a message
// to Whatsapp 

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Dialog 4G 929";
const char* password = "27D456c3";

const int button = D1;
String tobesend;
int c=1;

void setup() 
  {
  pinMode(button, INPUT);
  
  Serial.begin(115200);
  delay(100);
    
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
    
  WiFi.begin(ssid, password);
    
  while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
}

void loop() 
{
  if (digitalRead(button) == LOW && c == 1)
    {
      c=0;
      Serial.print("connecting to ");
      Serial.println("whatsapp");


      WiFiClient client;
      HTTPClient http; //Declare an object of class HTTPClient
      //Specify request destination
      tobesend = "http://api.callmebot.com/whatsapp.php?";
      tobesend = tobesend + "phone=+94763341205";
      tobesend = tobesend + "&text=Valve+ON";
      tobesend = tobesend + "&apikey=857102";
      http.begin(client,tobesend); 
      int httpCode = http.GET(); //Send the request
      if (httpCode > 0) 
          { 
           //Check the returning code
           String payload = http.getString(); //Get the request response payload
           Serial.println(payload); //Print the response payload
          }
      http.end(); //Close connection
    }
  if(digitalRead(button) == HIGH && c==0)
  {
      c=1;
      Serial.print("connecting to ");
      Serial.println("whatsapp");


      WiFiClient client;
      HTTPClient http; //Declare an object of class HTTPClient
      //Specify request destination
      tobesend = "http://api.callmebot.com/whatsapp.php?";
      tobesend = tobesend + "phone=+94763341205";
      tobesend = tobesend + "&text=Valve+OFF";
      tobesend = tobesend + "&apikey=857102";
      http.begin(client,tobesend); 
      int httpCode = http.GET(); //Send the request
      if (httpCode > 0) 
          { 
           //Check the returning code
           String payload = http.getString(); //Get the request response payload
           Serial.println(payload); //Print the response payload
          }
      http.end(); //Close connection
  }
}
