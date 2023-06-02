#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
// notes in the melody:
int melody[] = {
  NOTE_CA, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
4, 8, 8, 4, 4, 4, 4, 4
};
int thisNote = -1, noteDuration = 0;
long previousTime = 0,
presentTime = 0,
pauseBetweenNotes = 0;
void checkToPlay() {
  presentTime = millis ();
  if (presentTime - previousTime >= pauseBetweenNotes) {
      thisNote += 1;
      if(thisNote >= 8 ) {
        thisNote = -1;
        pauseBetweenNotes = 100;
        previousTime = millis ();
      }
      else {
        noteDuration = 500 / noteDurations [thisNote];
        tone (9, melody [thisNote], noteDuration);
        pauseBetweenNotes = noteDuration * 1.2;
        previousTime = millis();
      }
void loop() {
for (int i = 0; i < 8 ; i++){
    digitalWrite(latchPin,LOW);
    shiftOut (dataPin, clockPin, MSBFIRST, colDataMatrix[i]); 
    shiftOut (dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
    digitalWrite(latchPin,HIGH);
    checkToPlay();
    delay(1);
}
