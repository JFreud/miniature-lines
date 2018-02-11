#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int get_octant(int x0, int y0, int x1, int y1) {
  int delta_x = x1 - x0;
  int delta_y = y1 - y0;

  if (delta_x >= delta_y && delta_y >= 0) {
    return 1;
  }
  if (delta_x <= delta_y && delta_y >= 0) {
    return 2;
  }
  if (delta_x >= -1 * delta_y && delta_y < 0) {
    return 8;
  }
  if (delta_x <= -1 * delta_y && delta_y < 0) {
    return 7;
  }


  printf("not right\n");
  return -1;
}
//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  // f (x, y) = Ax + By + C
  if (x1 - x0 < 0) {
    draw_line(x1, y1, x0, y0, s, c);
  }
  else {
    int A,B,C,d,x,y;
    int octant = get_octant(x0, y0, x1, y1);
    if (octant < 0) {
      printf("something went wrong\n");
      exit(0);
    }
    x = x0;
    y = y0;
    A = y1 - y0;
    B = x0 - x1;
    C = 0;
    //octant 1
    if (octant == 1) {
      // printf("octant 1/5\n");
      d = 2 * A + B;
      while (x < x1) {
        plot (s, c, x, y);
        if (d > 0) {
          y++;
          d += 2 * B;
        }
        x++;
        d += 2 * A;
      }
    }

    else if (octant == 2) {
      // printf("octant 2/6\n");
      d = A + 2 * B;
      while (y < y1) {
        plot (s, c, x, y);
        if (d < 0) {
          x++;
          d += 2 * A;
        }
        y++;
        d += 2 * B;
      }
    }

    else if (octant == 7) {
      // printf("octant 3/7\n");
      d = A - 2 * B;
      while (y > y1) {
        plot (s, c, x, y);
        if (d > 0) {
          x++;
          d += 2 * A;
        }
        y--;
        d -= 2 * B;
      }
    }

    else {
      // printf("octant 4/8\n");
      d = 2 * A - B;
      while (x < x1) {
        plot (s, c, x, y);
        if (d < 0) {
          y--;
          d -= 2 * B;
        }
        x++;
        d += 2 * A;
      }
    }
  }
  // printf("finish\n");
}
