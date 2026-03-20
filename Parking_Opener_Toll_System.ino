#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Servo.h>

int IR_sensor = 0;
int Diatance = 0;

long ultrasound_distance_1() {
   long duration, distance;
   digitalWrite(8,LOW);
   delayMicroseconds(2);
   digitalWrite(8, HIGH);
   delayMicroseconds(10);
   digitalWrite(8, LOW);
   duration = pulseIn(7, HIGH);
   distance = duration/58;
   return distance;
}

LiquidCrystal_I2C lcd(0x27,16,2);

Servo servo_9;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  lcd.init();

  Serial.begin(9600);

  pinMode(4, INPUT_PULLUP);
  servo_9.attach(9);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
    lcd.backlight();

}

void loop() {
    IR_sensor = digitalRead(4);
    Diatance = ultrasound_distance_1();
    Serial.println(IR_sensor);
    Serial.println(Diatance);
    if (Diatance < 15) {
      servo_9.write(90); delay(4000);
      lcd.display();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome");
      lcd.setCursor(0, 1);
      lcd.print("Have a nice day");
      digitalWrite(5, LOW);
      digitalWrite(2, HIGH);
    } else {
      servo_9.write(180); delay(4000);
      lcd.display();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome To");
      lcd.setCursor(0, 1);
      lcd.print("Toll Gate");
      digitalWrite(5, HIGH);
      digitalWrite(2, LOW);
    }
    if (IR_sensor < 1) {
      servo_9.write(90); delay(4000);
      lcd.display();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Thank You");
      lcd.setCursor(0, 1);
      lcd.print("Have a nice day");
      digitalWrite(5, LOW);
      digitalWrite(2, HIGH);
    } else {
      servo_9.write(180); delay(4000);
      lcd.display();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome To");
      lcd.setCursor(0, 1);
      lcd.print("Toll Gate");
      digitalWrite(5, HIGH);
      digitalWrite(2, LOW);
    }

}