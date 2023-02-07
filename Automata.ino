#include <ArduinoGraphics.h>
#include <Arduino_MKRRGB.h>

// Function that sets pixel based on the x,y coordinate of the board given
const int width = 7;
const int height = 12;

int currGen[width][height];
int nextGen[width][height];


void setPixel(int y, int x, unsigned char r, unsigned char g, unsigned char b){
  MATRIX.beginDraw();
  // For our program, y will take the place of x, horizontally going only to 6, while our x will take the place of y, vertically going up to 11
  MATRIX.set(y, x, r, g, b);
  MATRIX.endDraw();
}

int countAlive(int i, int j){
  int count = 0;
  for (int x = -1; x <=1; x++){ // members left and right
    for (int y = -1; y <=1; y++){ // will count alive members above and below
      int row = (i + x + width) % width; //left and right of i
      // Add print statements to debug
      int col = (j + y + height) % height; // up and down of j
      count += currGen[row][col];
    }
  }
  count -= currGen[i][j];
  return count;
}

void newGeneration(){
  for (int i = 0; i < width; i ++){
    for (int j = 0; j < height; j++){
      int alive = countAlive(i, j);
      if (currGen[i][j] == 1){
        if (alive < 2 || alive > 3){
          nextGen[i][j] = 0;
        }
        else{
          nextGen[i][j] = 1;
        }
      }
      else{
        if (alive == 3){
          nextGen[i][j] = 1;
        }
        else{
          nextGen[i][j] = 0;
        }
      }
    }
  }
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++ ){
      currGen[i][j] = nextGen[i][j];
    }
  }
}

void displayGen(){
  MATRIX.clear();
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      if(currGen[i][j] == 1){
        /*
        int r = random(0,255);
        int g = random(0, 255);
        int b = random(0,255);
        setPixel(j, i, r, g, b);
        */
        int neighbors = countAlive(i, j);
        if(neighbors == 0){
          setPixel(j, i, 255, 0, 0); 
        }
        else if(neighbors == 1){
          setPixel(j, i, 255, 128, 0); 
        }
        else if(neighbors == 2){
          setPixel(j, i, 255, 200, 0); 
        }
        else{
          setPixel(j, i, 255, 255, 50); 
        }
      }
    }
  }
  
}
void restart(){
  for(int i = 0; i < width; i++){
    for (int j = 0; j < height; j++) {
      currGen[i][j] = random(0,2);
    }
  }
}

int reset = 0;
void setup() {
 
  Serial.begin(9600);
  MATRIX.begin();
  MATRIX.brightness(10);
  randomSeed(analogRead(0));
  //Initialize board with random values;
  restart();
}

void loop() {
  
  if (reset == 50){
    restart();
    reset = 0;
  }
  reset = reset + 1;
  newGeneration();
  displayGen();
  delay(1000);
  //MATRIX.set(11,6,255,0,0); 
  //MATRIX.endDraw();

  // put your main code here, to run repeatedly:

}
