/* when an integer ranging from -1 to 8 is sent over i2c from the mega,
 * it is interpreted here and the correct sound is played
 */
#include <Wire.h>
#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>

SdFat sd;

SFEMP3Shield MP3player;

const uint8_t volume = 0; // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max

bool started = false;
bool repeat = false;
int lastSong = -2;

int signal = 5;
volatile int currentCommand = -999;

void setup(){
  Wire.begin(8);
  Wire.onReceive(dataEvent);
  Serial.begin(9600);
  initSD();  // Initialize the SD card
  initMP3Player(); // Initialize the MP3 Shield
}

void loop(){
  // 1 through 7 are sounds, -1 is pause, and 0 is nothing
  if (currentCommand != -999){
  //  Serial.println(currentCommand);
  }

  if (currentCommand == -1){
    if (MP3player.isPlaying()) {
      MP3player.stopTrack();
    }
  }
  else if (currentCommand == 0){
    started = false;
  }
  else if (!started || currentCommand != lastSong ){
    started = true;
    if (MP3player.isPlaying()) {
      MP3player.stopTrack();
    }
    //play curent song
    int result = MP3player.playTrack(currentCommand);
  }
  else if (repeat && started && !MP3player.isPlaying()){
    //loooop!!!
    started = false;
  }

  lastSong = currentCommand;
}

void initSD() {
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED))
    sd.initErrorHalt();
  if(!sd.chdir("/"))
    sd.errorHalt("sd.chdir");
}

// initMP3Player() sets up all of the initialization for the
// MP3 Player Shield. It runs the begin() function, checks
// for errors, applies a patch if found, and sets the volume/
// stero mode.
void initMP3Player() {
  uint8_t result = MP3player.begin();
  if(result != 0) {
    Serial.print("INIT ERROR!!! ");
    Serial.println(result);
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}

void dataEvent(int howMany)
{
  // incoming data is 1 bit for repeating, 15 bits for song number
  int data = Wire.read();
  repeat = (data & (1 << 7)) >> 7;
  Serial.println(repeat, HEX);
  currentCommand = data & 0x7f;
}
