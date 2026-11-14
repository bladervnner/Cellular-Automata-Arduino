# Cellular Automata on Arduino

I wanted to explore electronics and learn how to program an Arduino. For this project, I implemented Conway's Game of Life on an Arduino MKR RGB Shield.

One of the harder challenges was figuring out how to control individual pixels on the LED matrix. I also had to adjust the coordinates because the matrix uses a 12 × 7 layout, while my code represents it as 7 × 12. I handled this by swapping the x and y coordinates when setting pixels.

The program starts with a randomly generated board and applies Conway's Game of Life rules to each generation. Cells wrap around the edges of the board, and the simulation restarts with a new random configuration after 50 generations.

I also added colors based on the number of living neighbors surrounding each cell. For example, cells with no living neighbors are red, while cells with more neighbors appear yellow or orange. The code also includes an optional, commented-out section for random RGB colors.

## Hardware and Software

- Arduino MKR board with MKR RGB Shield
- Arduino IDE
- `ArduinoGraphics` and `Arduino_MKRRGB` libraries

## Running the Project

Open `Automata.ino` in the Arduino IDE, install the required libraries, select your compatible Arduino board, and upload the sketch.

The simulation updates once per second.

## Demonstration
![Automata](https://user-images.githubusercontent.com/112827038/220210555-903dbc6f-bab5-4eca-92b1-eb8958c0e97c.gif)
