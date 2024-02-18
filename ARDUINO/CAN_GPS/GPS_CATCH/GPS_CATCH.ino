#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  ss.begin(GPSBaud);

  Serial.println(F("GPS Data:"));
  Serial.println(F("---------"));
}

void loop() {
Serial.print(F("Satellites:      "));
  printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
  Serial.println(F(" (Number of satellites in view)"));

  Serial.print(F("HDOP:            "));
  printFloat(gps.hdop.hdop(), gps.hdop.isValid(), 6, 1);
  Serial.println(F(" (Horizontal Dilution of Precision)"));

  Serial.print(F("Latitude:        "));
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  Serial.println(F(" (Latitude in degrees)"));

  Serial.print(F("Longitude:       "));
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  Serial.println(F(" (Longitude in degrees)"));

  Serial.print(F("Location Age:    "));
  printInt(gps.location.age(), gps.location.isValid(), 5);
  Serial.println(F(" (Time since last GPS fix in milliseconds)"));

  Serial.print(F("Date & Time:     "));
  printDateTime(gps.date, gps.time);
  Serial.println(F(" (Date and time of last GPS fix)"));

  Serial.print(F("Altitude:        "));
  printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
  Serial.println(F(" (Altitude in meters)"));

  Serial.print(F("Course:          "));
  printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
  Serial.println(F(" (Course in degrees)"));

  Serial.print(F("Speed:           "));
  printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
  Serial.println(F(" (Speed in km/h)"));

  Serial.print(F("Course Cardinal: "));
  printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.deg()) : "*** ", 6);
  Serial.println(F(" (Cardinal direction of course)"));

  // Serial.println();

  // 東京都庁との距離と方角を計算して表示
  static const double TOKYO_LAT = 35.6895, TOKYO_LON = 139.6917;
unsigned long distanceKmToTokyo =
  (unsigned long)TinyGPSPlus::distanceBetween(
    gps.location.lat(),
    gps.location.lng(),
    TOKYO_LAT, 
    TOKYO_LON) / 1000;
Serial.print(F("Distance to Tokyo: "));
printInt(distanceKmToTokyo, gps.location.isValid(), 9);
Serial.println(F(" km"));

double courseToTokyo =
  TinyGPSPlus::courseTo(
    gps.location.lat(),
    gps.location.lng(),
    TOKYO_LAT, 
    TOKYO_LON);
Serial.print(F("Course to Tokyo: "));
printFloat(courseToTokyo, gps.location.isValid(), 7, 2);
Serial.println(F(" degrees"));

const char *cardinalToTokyo = TinyGPSPlus::cardinal(courseToTokyo);
Serial.print(F("Cardinal to Tokyo: "));
printStr(gps.location.isValid() ? cardinalToTokyo : "*** ", 6);
Serial.println();

  Serial.println();

  smartDelay(4000);

  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));
}

static void smartDelay(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void printFloat(float val, bool valid, int len, int prec) {
  if (!valid) {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  } else {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1);
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i = flen; i < len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

static void printInt(unsigned long val, bool valid, int len) {
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i = strlen(sz); i < len; ++i)
    sz[i] = ' ';
  if (len > 0)
    sz[len - 1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t) {
  if (!d.isValid()) {
    Serial.print(F("********** "));
  } else {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }

  if (!t.isValid()) {
    Serial.print(F("******** "));
  } else {
    char sz[32];
    int hour = t.hour() + 9;
    if (hour >= 24) hour -= 24;
    sprintf(sz, "%02d:%02d:%02d ", hour, t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}

static void printStr(const char *str, int len) {
  int slen = strlen(str);
  for (int i = 0; i < len; ++i)
    Serial.print(i < slen ? str[i] : ' ');
  smartDelay(0);
}


