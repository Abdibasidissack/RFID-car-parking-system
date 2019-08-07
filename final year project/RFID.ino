//RFID PARKING SYSTEM



#include <Servo.h> // library for servo motor that acts as the gate

#include <Wire.h> // library for Two Wire Interface

#include <SPI.h> // library for serial peripheral interface

#include <MFRC522.h>  // library for rfid reader

#include <LiquidCrystal.h> // library for LCD display



/*

 * define function is directive that allows the definitions

* to replace a repetitive series of keyboard and mouse actions

*/



#define sensor1 w = A0

#define sensor2 x = A1

#define sensor3 y = A2

#define sensor4 z = A3

//#define colx 8

#define SS_PIN 10

#define RST_PIN 9



MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.



int sensor1,sensor2,sensor3,sensor4; //declaration of variable sensor one and two

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //declaring lcd pins to be used

//Servo serrvo; // making the servo an object

Servo myservo; // creating an object







void setup() {

  // place your setup code here, to run once:



  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps

  SPI.begin();      // Initiate  SPI bus

  mfrc522.PCD_Init();   // Initiate MFRC522

  myservo.attach(A5);

//  myservo.write(90);

  myservo.write(0);



  pinMode(sensor1, INPUT); // declaring the pins to accepts input signals

  pinMode(sensor2, INPUT); // declaring the pins to accepts input signals



  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display



  // displaying welcome message on the LCD

  lcd.setCursor(0,0); // start the display in row 1 column 0

  lcd.print("WELCOME TO AUTO. ");

  lcd.setCursor(1,1);// start the display in row 2 column 0

  lcd.print("PARKING SYSTEM");

  delay(3000);

  lcd.clear();



  // giving instructions to the user

  lcd.setCursor(2,0);

  lcd.print("KINDLY PLACE");

  lcd.setCursor(4,1);

  lcd.print("RFID TAG");

  rfid();

  delay(3000);

  lcd.clear();



//  DISPLAYING EMPTY SLOT NUMBERS



//  lcd.setCursor(0,0);

//  lcd.print("PK1 :");

//  lcd.setCursor(0,1);

//  lcd.print("PK2 :");

//  lcd.setCursor(9,0);

//  lcd.print("PK3 :");

//  lcd.setCursor(9,1);

//  lcd.print("PK4 :");





  myservo.attach(A5);  // stating or declaring the pin that will be used by the servo



}









/*

* Creating functions that will be used within the program

*/



// Sensor functions

// OPTIONS



void Option_1()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);  lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);  lcd.print("E");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);  lcd.print("E");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}



  void Option_2()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);  lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("E");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("E");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}



  void Option_3()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("E");



 lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}

void Option_4()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);  lcd.print("E");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}

void Option_5()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("E");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("E");



 lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}

//POSSIBILITY 2



void Option_6()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("E");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}

  void Option_7()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



 lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}



  void Option_8()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("E");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}



  void Option_9()

{lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("E");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



 lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}



  void Option_10()

{lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("E");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("E");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}



  void Option_11()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");

  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("E");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}



//POSSIBILITY 3



void Option_12()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");

  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("E");

}



void Option_13()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("E");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");

  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}



void Option_14()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("E");

  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}

 void Option_15()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");

  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("E");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}

  void Option_default()

{

  lcd.setCursor(0,0);  lcd.print("PK1 :");

  lcd.setCursor(6,0);   lcd.print("F");



  lcd.setCursor(0,1);   lcd.print("PK2 :");

  lcd.setCursor(15,0);   lcd.print("F");



  lcd.setCursor(9,0);   lcd.print("PK3 :");

  lcd.setCursor(6,1);   lcd.print("F");



  lcd.setCursor(9,1);   lcd.print("PK4 :");

  lcd.setCursor(15,1);   lcd.print("F");

}





// RFID SENSORS DATA

// looking for new cards

void rfid()

{

  if(! mfrc522.PICC_IsNewCardPresent())

  {

    return;

  }



  if (! mfrc522.PICC_ReadCardSerial())

  {

    return;

  }

   //Show UID on serial monitor

  lcd.setCursor(0,0);

  Serial.print("UID tag :");

  lcd.print("UID:");

  String content= "";

  byte letter;



  for ( byte i = 0; i < mfrc522.uid.size; i++)

  {

    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");

    Serial.print(mfrc522.uid.uidByte[i], HEX);

    lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");

    lcd.print(mfrc522.uid.uidByte[i], HEX);

    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));

    content.concat(String(mfrc522.uid.uidByte[i], HEX));

  }



  Serial.println();

  Serial.print("Message : ");

  lcd.print("Message : ");

  content.toUpperCase();



   // if (content.substring(1) == "BD 31 15 2B") //change here the UID of the card/cards that you want to give access

   if (content.substring(1) == "49 64 D7 73")

    {

      lcd.setCursor(0,1);

      Serial.println("Authorized access");

      Serial.println();

      lcd.print("Authorized access");

      lcd.println();

      delay(3000);

      lcd.clear();

      myservo.write(90);

      lcd.print("OPPENING .....");

      delay(3000);

      lcd.clear();

      delay(1000);

      myservo.write(0);



    }



   else   {

      lcd.setCursor(0,1);

      Serial.println(" Access denied");

      lcd.print(" Access denied  ");

      delay(5000);

      lcd.clear();

    }

  }



//  servo function

//void myserrvo()

//{

//  myservo.write(90);

//  delay(10);

//  myservo.write(0);

//  delay(10);

//}

void loop()

{

  // put your main code here, to run repeatedly:



  rfid();



   int senread1 = digitalRead(sensor1);

   int senread2 = digitalRead(sensor2);

   int senread3 = digitalRead(sensor3);

   int senread4 = digitalRead(sensor4);



  if(senread1 == HIGH && senread2 == HIGH && senread3 == HIGH && senread4 == HIGH)

  {

    Option_1();

  }

  else if(senread1 == !HIGH && senread2 == HIGH && senread3 == HIGH && senread4 == HIGH )

  {

    Option_2();

  }

  else if(senread1 == HIGH && senread2 == !HIGH && senread3 == HIGH && senread4 == HIGH )

  {

    Option_3();

  }

  else if(senread1 == HIGH && senread2 == HIGH && senread3 == !HIGH && senread4 == HIGH )

  {

    Option_4();

  }

  else if(senread1 == HIGH && senread2 == HIGH && senread3 == HIGH && senread4 == !HIGH )

  {

    Option_5();

  }

  else if(senread1 == !HIGH && senread2 == !HIGH && senread3 == HIGH && senread4 == HIGH )

  {

    Option_6();

  }

   else if(senread1 == HIGH && senread2 == !HIGH && senread3 == !HIGH && senread4 == HIGH )

  {

    Option_7();

  }

   else if(senread1 == HIGH && senread2 == HIGH && senread3 == !HIGH && senread4 == !HIGH )

  {

    Option_8();

  }

  else if(senread1 == !HIGH && senread2 == HIGH && senread3 == !HIGH && senread4 == HIGH )

  {

    Option_9();

  }

  else if(senread1 == !HIGH && senread2 == HIGH && senread3 == HIGH && senread4 == !HIGH )

  {

    Option_10();

  }

  else if(senread1 == HIGH && senread2 == !HIGH && senread3 == HIGH && senread4 == !HIGH )

  {

    Option_11();

  }

  else if(senread1 == !HIGH && senread2 == !HIGH && senread3 == !HIGH && senread4 == HIGH )

  {

    Option_12();

  }

  else if(senread1 == HIGH && senread2 == !HIGH && senread3 == !HIGH && senread4 == !HIGH )

  {

    Option_13();

  }

  else if(senread1 == !HIGH && senread2 == HIGH && senread3 == !HIGH && senread4 == !HIGH )

  {

    Option_14();

  }

  else if(senread1 == !HIGH && senread2 == !HIGH && senread3 == HIGH && senread4 == !HIGH )

  {

    Option_15();

  }

  else

  {

    Option_default();

  }



delay(1);

}
