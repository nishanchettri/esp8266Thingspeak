
//thingspeak 

#include <SoftwareSerial.h>
String apiKey = "...";    // Edit this CHANNEL API key according to your Account

String Host_Name = "abcd";            // Edit Host_Name

String Password = "password";          // Edit Password

SoftwareSerial ser(2, 3);              // RX, TX

int i=1;




void thingspeak() {

i++;
  String state1=String(i);                 // Converting them to string whatever jo bhejna hai
 

  String cmd = "AT+CIPSTART=\"TCP\",\"";          // Establishing TCP connection

  cmd += "184.106.153.149";                       // api.thingspeak.com

  cmd += "\",80";                                 // port 80

  ser.println(cmd);

  Serial.println(cmd);

 if(ser.find("Error")){

    Serial.println("AT+CIPSTART error");

    return;

  }

String getStr = "GET /update?api_key=";         // prepare GET string

  getStr += apiKey;

  getStr +="&field1=";

  getStr += String(state1);                       

  getStr += "\r\n\r\n";

  cmd = "AT+CIPSEND=";

  cmd += String(getStr.length());                // Total Length of data

  ser.println(cmd);

  Serial.println(cmd);

 

if(ser.find("")){

    ser.print(getStr);

    Serial.print(getStr);

  }

  else{

    ser.println("AT+CIPCLOSE");                  // closing connection

    Serial.println("AT+CIPCLOSE");

  }

 delay(1000);                                  // Update after every 15 seconds

}


void setup() {


  
  Serial.begin(115200);

ser.begin(115200);                     // reset ESP8266

ser.println("AT+RST");               // Resetting ESP8266

char inv ='"';

String cmd = "AT+CWJAP";

       cmd+= "=";

       cmd+= inv;

       cmd+= Host_Name;

       cmd+= inv;

       cmd+= ",";

       cmd+= inv;

       cmd+= Password;

       cmd+= inv;

ser.println(cmd);



}

void loop() {
 
  

  
  thingspeak();

  }

  
