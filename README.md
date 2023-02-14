# Cellular-Automata-Arduino

I wanted to explore electronics by learning to code them. What better way to do it than with Arduino. 

The hardest part of this project for me was learning how to light up an individual pixel on the Matrix. The other challenge was to get my board to align with a 7 by 12 style matrix. The MKR RGB shell's default state is to read inputs as a 12 by 7, starting at the right. So the easiers thing to do was to simply change the inputs that go into x with y and vice versa

This project will randomly set the state of a board on the first iteration. There, Conway's Game of Life rules are applied. I added some other functionalities, like randomly changing the color of the pixes or making a gradient style change. For example, if an alive cell has 0 living neighbors, that pixel is red, or if that Living cell has four or more living neighbors, the color is closer to orange.


