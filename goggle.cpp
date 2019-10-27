#include "goggle.h"
#include "application.h"

Servo servoR;
Servo servoL;

Goggle::Goggle(){}

void Goggle::initGoggles(int r, int l) {
  servoR.attach(r);
  servoL.attach(l);
}

void Goggle::close() {
  closeLeft();
  closeRight();
}

void Goggle::closeLeft() {
  servoL.write(175);
}

void Goggle::closeRight() {
  servoR.write(5);
}

void Goggle::open() {
  openLeft();
  openRight();
}

void Goggle::openLeft() {
  servoL.write(5);
}

void Goggle::openRight() {
  servoR.write(175);
}

void Goggle::blink() {
    close();
    delay(400);
    open();
    delay(400);
}

void Goggle::adjustLeft(int amount) {
  int lastAmount = servoL.read();
  int newAmount = lastAmount + amount;
  if (newAmount < 5) {
      newAmount = 5;
  }
  else if (newAmount > 175) {
      newAmount = 175;
  }
  servoL.write(newAmount);
}

void Goggle::adjustRight(int amount) {
  int lastAmount = servoR.read();
  int newAmount = lastAmount + amount;
  if (newAmount < 5) {
      newAmount = 5;
  }
  else if (newAmount > 175) {
      newAmount = 175;
  }
  servoR.write(newAmount);
}

void Goggle::adjustBoth(int amount) {
  adjustLeft(-1*amount);
  adjustRight(amount);
}

void Goggle::adjustOpposite(int amount) {
  adjustLeft(amount);
  adjustRight(amount);
}