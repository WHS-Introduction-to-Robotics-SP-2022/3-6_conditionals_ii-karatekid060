const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;


const int potPin = A0;


int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;

void setup()
{
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}

void loop()
{

 int potPinValue = map(analogRead(potPin), 0, 1024, 0, 255);


 if (potPinValue <= 42.5) {
 currentColorValueRed = 255;
 currentColorValueGreen = potPinValue * 6;
 currentColorValueBlue = 0;
 }

 if ((potPinValue > 42.5) && (potPinValue <= 85)) {
 currentColorValueRed = 255 - (potPinValue - 43) * 6;
 currentColorValueGreen = 255;
 currentColorValueBlue = 0;
 }

 if ((potPinValue > 85) && (potPinValue <= 127.5)) {
 currentColorValueRed = 0;
 currentColorValueGreen = 255;
 currentColorValueBlue = (potPinValue - 85) * 6;
 }

 if ((potPinValue > 127.5) && (potPinValue <= 170)) {
 currentColorValueRed = 0;
 currentColorValueGreen = 255 - (potPinValue - 127.5) * 6;
 currentColorValueBlue = 255;
 }

 if ((potPinValue > 170) && (potPinValue <= 212.5)) {
 currentColorValueRed = (potPinValue - 170) * 6;
 currentColorValueGreen = 0;
 currentColorValueBlue = 255;
 }

 if ((potPinValue > 212.5) && (potPinValue <= 255)) {
 currentColorValueRed = 255;
 currentColorValueGreen = 0;
 currentColorValueBlue = 255 - (potPinValue - 212.5) * 6;
 }

 analogWrite(redPin, currentColorValueRed);
 analogWrite(bluePin, currentColorValueBlue);
 analogWrite(greenPin, currentColorValueGreen);
}
