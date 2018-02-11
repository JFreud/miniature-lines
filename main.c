#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = MAX_COLOR;
  c.green = 30;
  c.blue = 50;

  clear_screen(s);


  // // draw_line(0, 0, 500, 200, s, c);
  // draw_line(200, 0, 300, 500, s, c);
  // draw_line(0, 200, 500, 300, s, c);
  //
  // draw_line(0, 300, 500, 200, s, c);
  // draw_line(200, 500, 300, 0, s, c);
  //
  draw_line(250, 0, 250, 500, s, c); //vertical
  draw_line(0, 250, 500, 250, s, c); //horizontal
  draw_line(0, 0, 500, 500, s, c); //slope 1
  draw_line(0, 500, 500, 0, s, c); //slope -1

  c.red = 50;
  c.green = 30;
  c.blue = MAX_COLOR;

  int count = 0;
  srand(time(NULL));
  while (count < 500) {

    int start_x = rand() % 500;
    int start_y = rand() % 500;

    // printf("start x: %d\n", start_x);
    // printf("start y: %d\n", start_y);

    int length_x = rand() % 100 - 50;

    int length_y = rand() % 100 - 50;

    draw_line(start_x, start_y, start_x + length_x, start_y + length_y, s, c);
    count++;
    // printf("%d\n", count);
  }

  // draw_line(400, 300, 30, 30, s, c);
  display(s);
  save_extension(s, "lines.png");
}
