#include <WiFi.h>  //library needed for wifi conection

const char *ssid = "abcd";  //name of the network
const char *password = "abcd";  //password of the network

NetworkServer server(80);

const int ledpin1 = 5;
const int ledpin2 = 18;
const int ledpin3 = 19;
const int ledpin4 = 21;

void setup() {
  Serial.begin(115200);
  pinMode(ledpin1, OUTPUT);  // set the LED pin mode
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);

  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  NetworkClient client = server.accept();  // listen for incoming clients

  if (client) {                     // if you get a client,
    Serial.println("New Client.");  // print a message out the serial port
    String currentLine = "";        // make a String to hold incoming data from the client
    while (client.connected()) {    // loop while the client's connected
      if (client.available()) {     // if there's bytes to read from the client,
        char c = client.read();     // read a byte, then
        Serial.write(c);            // print it out the serial monitor
        if (c == '\n') {            // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H1\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L1\">here</a> to turn the LED on pin 5 off.<br>");

            client.print("Click <a href=\"/H2\">here</a> to turn the LED on pin 18 on.<br>");
            client.print("Click <a href=\"/L2\">here</a> to turn the LED on pin 18 off.<br>");

            client.print("Click <a href=\"/H3\">here</a> to turn the LED on pin 19 on.<br>");
            client.print("Click <a href=\"/L3\">here</a> to turn the LED on pin 19 off.<br>");

            client.print("Click <a href=\"/H4\">here</a> to turn the LED on pin 21 on.<br>");
            client.print("Click <a href=\"/L4\">here</a> to turn the LED on pin 21 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H1")) {
          digitalWrite(5, HIGH);  // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L1")) {
          digitalWrite(5, LOW);  // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /H2")) {
          digitalWrite(18, HIGH);  // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L2")) {
          digitalWrite(18, LOW);  // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /H3")) {
          digitalWrite(19, HIGH);  // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L3")) {
          digitalWrite(19, LOW);  // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /H4")) {
          digitalWrite(21, HIGH);  // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L4")) {
          digitalWrite(21, LOW);  // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
