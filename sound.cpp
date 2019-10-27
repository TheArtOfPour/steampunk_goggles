#include "sound.h"
#include "application.h"

int piezo;
int light;
int tempo = 130;

const int doom[] PROGMEM = {
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //1
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,
};

const int vampire[] = {
  NOTE_E5,16, NOTE_E5,8, NOTE_D5,16, REST,16, NOTE_CS5,-4, NOTE_E4,8, NOTE_FS4,16, NOTE_G4,16, NOTE_A4,16,
  NOTE_B4,-8, NOTE_E4,-8, NOTE_B4,8, NOTE_A4,16, NOTE_D5,-4, //7
  NOTE_E5,16, NOTE_E5,8, NOTE_D5,16, REST,16, NOTE_CS5,-4, NOTE_E4,8, NOTE_FS4,16, NOTE_G4,16, NOTE_A4,16,
};

const int rick[] = {
  NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4
};

const int potter[] = {
  REST, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,
};

Sound::Sound(){}

void Sound::initSound(int p, int l)
{
  pinMode(p, OUTPUT);
  piezo = p;
  light = l;
}

void Sound::beep(int note, int duration)
{
  tone(piezo, note, duration);
  digitalWrite(light, HIGH);
  delay(duration);
  noTone(piezo);
  digitalWrite(light, LOW);
  delay(50);
}

void Sound::playSW()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
}

void Sound::playDOOM()
{
  tempo = 180;
  int notes = sizeof(doom) / sizeof(doom[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = pgm_read_word_near(doom+thisNote + 1);
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    digitalWrite(light, HIGH);
    tone(piezo, pgm_read_word_near(doom+thisNote), noteDuration * 0.9);
    delay(noteDuration);
    noTone(piezo);
    digitalWrite(light, LOW);
  }
}

void Sound::playVampire()
{
  int notes = sizeof(vampire) / sizeof(vampire[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = vampire[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    digitalWrite(light, HIGH);
    tone(piezo, vampire[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(piezo);
    digitalWrite(light, LOW);
  }
}

void Sound::playRick()
{
  tempo = 114;
  int notes = sizeof(rick) / sizeof(rick[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = rick[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    digitalWrite(light, HIGH);
    tone(piezo, rick[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(piezo);
    digitalWrite(light, LOW);
  }
}

void Sound::playPotter()
{
  tempo = 144;
  int notes = sizeof(potter) / sizeof(potter[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = potter[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    digitalWrite(light, HIGH);
    tone(piezo, potter[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(piezo);
    digitalWrite(light, LOW);
  }
}
