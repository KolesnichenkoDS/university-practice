#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// f(x) = x * cos(x)
double f(double x) {
  return x * cos(x);
}

const int SIZEX = 155;
const int SIZEY = 25;

typedef struct Graph {
  char **buffer;

  double left;
  double right;
  int sizeX;
  int sizeY;
  int centerX;
  int centerY;
  double unitX;
  double unitY;
  double unitSizeX;
  double unitSizeY;
} Graph;

void set(Graph *graph, int i, int j, char v) {
  if (j >= 0 && j < graph->sizeX && i >= 0 && i < graph->sizeY) {
    graph->buffer[i][j] = v;
  }
}

char get(Graph *graph, int i, int j) {
  if (j >= 0 && j < graph->sizeX && i >= 0 && i < graph->sizeY) {
    return graph->buffer[i][j];
  }
  return ' ';
}

void clearBuffer(Graph *graph) {
  for (int i = 0; i < graph->sizeY; i++) {
    for (int j = 0; j < graph->sizeX; j++) {
      set(graph, i, j, ' ');
    }
  }
}

void drawAxes(Graph *graph) {
  for (int i = 0; i < graph->sizeY; i++) {
    for (int j = 0; j < graph->sizeX; j++) {
      if (i == graph->centerY)
        set(graph, i, j, '-');
      if (j == graph->centerX)
        set(graph, i, j, '!');
      if (i == graph->centerY && j == graph->centerX)
        set(graph, i, j, '+');
    }
  }

  for (double x = 0, xx = 0; xx < graph->sizeX; x += graph->unitX, xx += graph->unitSizeX) {
    double x1 = graph->centerX - xx;
    double x2 = graph->centerX + xx;
    if (x1 >= 0) {
      set(graph, graph->centerY, (int) x1, '+');
      char xs[100];
      xs[0] = '\0';
      sprintf(xs, " %.2f", -x);
      if ((int) x1 > strlen(xs) / 2 &&
          (int) x1 + strlen(xs) / 2 < graph->sizeX && (int) x1 != graph->centerX) {
        for (int i = 0; i < strlen(xs); i++) {
          set(graph, graph->centerY - 1, (int) x1 + i - strlen(xs) / 2, xs[i]);
        }
      }
    }
    if (x2 < graph->sizeX) {
      set(graph, graph->centerY, (int) x2, '+');
      char xs[100];
      xs[0] = '\0';
      sprintf(xs, " %.2f", x);
      if ((int) x2 > strlen(xs) / 2 &&
          (int) x2 + strlen(xs) / 2 < graph->sizeX && (int) x2 != graph->centerX) {
        for (int i = 0; i < strlen(xs); i++) {
          set(graph, graph->centerY - 1, (int) x2 + i - strlen(xs) / 2, xs[i]);
        }
      }
    }
  }

  for (double y = 0, yy = 0; yy < graph->sizeY; y += graph->unitY, yy += graph->unitSizeY) {
    double y1 = graph->centerY - yy;
    double y2 = graph->centerY + yy;
    if (y1 >= 0) {
      set(graph, (int)y1, graph->centerX, '+');
      char ys[100];
      ys[0] = '\0';
      sprintf(ys, " %.2f", y);
      if ((int) y1 != graph->centerY) {
        for (int i = 0; i < strlen(ys); i++) {
          set(graph, (int)y1, graph->centerX + 1 + i, ys[i]);
        }
      }
    }
    if (y2 < graph->sizeY) {
      set(graph, (int)y2, graph->centerX, '+');
      char ys[100];
      ys[0] = '\0';
      sprintf(ys, " %.2f", -y);
      if ((int) y2 != graph->centerY) {
        for (int i = 0; i < strlen(ys); i++) {
          set(graph, (int) y2, graph->centerX + i + 1, ys[i]);
        }
      }
    }
  }

  set(graph, 0, graph->centerX, '^');
  set(graph, graph->centerY, graph->sizeX - 1, '>');
}

void drawAnnotations(Graph *graph) {
  char *xs = "X axis";
  char *ys = "Y axis";
  for (int i = 0; i < strlen(xs); i++) {
    set(graph, graph->centerY + 2, graph->sizeX - strlen(xs) + i, xs[i]);
  }
  for (int i = 0; i < strlen(ys); i++) {
    set(graph, 0, graph->centerX - strlen(ys) + i - 1, ys[i]);
  }

  char *fs = "{ y = x * cos(x) }";
  for (int i = 0; i < strlen(fs); i++) {
    set(graph, graph->sizeY - 1, graph->sizeX - strlen(fs) + i, fs[i]);
  }
}

void drawPoint(Graph *graph, double x, int xPos) {
  double y = f(x);
  int yPos = graph->centerY - (int) (y * graph->unitSizeY);
  if (yPos >= 0 && yPos < graph->sizeY) {
    char c = get(graph, yPos, xPos);
    if (c == ' ' || c == '-' || c == '!' || c == '+')
      set(graph, yPos, xPos, '*');
  }
}

void drawChart(Graph *graph) {
  for (int i = 0; i < graph->sizeX; i++) {
    if (graph->centerX + i < graph->sizeX)
      drawPoint(graph, ((double) i) / graph->unitSizeX, graph->centerX + i);
    if (graph->centerX - i >= 0)
      drawPoint(graph, -((double) i) / graph->unitSizeX, graph->centerX - i);
  }
}

int main() {
  double a, b;
  printf("Введите левую и правую границу графика (через пробел): ");
  scanf("%lf %lf", &a, &b);
  if (b < a) {
    double tmpA = a;
    a = b;
    b = tmpA;
  }

  double yA = f(a) - 2;
  double yB = f(b) + 2;

  double diffX = b - a;
  double diffY = yB - yA;
  if (diffY < 0)
    diffY = -diffY;

  double unitX = 1;
  double unitY = 1;

  while (1) {
    if (unitX > diffX / 15) {
      if (unitX / 2 <= diffX / 15) {
        unitX /= 2;
        break;
      }
      if (unitX / 4 <= diffX / 15) {
        unitX /= 4;
        break;
      }
      if (unitX / 5 <= diffX / 15) {
        unitX /= 5;
        break;
      }
      if (unitX / 10 <= diffX / 15) {
        unitX /= 10;
        break;
      }
      unitX /= 10;
    }
    if (unitX < diffX / 10) {
      if (unitX * 2 >= diffX / 10) {
        unitX *= 2;
        break;
      }
      if (unitX * 2.5 >= diffX / 10) {
        unitX *= 4;
        break;
      }
      if (unitX * 5 >= diffX / 10) {
        unitX *= 5;
        break;
      }
      if (unitX * 10 >= diffX / 10) {
        unitX *= 10;
        break;
      }
      unitX *= 10;
    }
  }

  while (1) {
    if (unitY > diffY / 7) {
      if (unitY / 2 <= diffY / 7) {
        unitY /= 2;
        break;
      }
      if (unitY / 4 <= diffY / 7) {
        unitY /= 4;
        break;
      }
      if (unitY / 5 <= diffY / 7) {
        unitY /= 5;
        break;
      }
      if (unitY / 10 <= diffY / 7) {
        unitY /= 10;
        break;
      }
      unitY /= 10;
    }
    if (unitY < diffY / 5) {
      if (unitY * 2 >= diffY / 5) {
        unitY *= 2;
        break;
      }
      if (unitY * 2.5 >= diffY / 5) {
        unitY *= 4;
        break;
      }
      if (unitY * 5 >= diffY / 5) {
        unitY *= 5;
        break;
      }
      if (unitY * 10 >= diffY / 5) {
        unitY *= 10;
        break;
      }
      unitY *= 10;
    }
  }

  double unitSizeX = unitX * SIZEX / diffX;
  double unitSizeY = unitY * SIZEY / diffY;

  char **buffer = malloc(sizeof(void *) * SIZEY);
  for (int i = 0; i < SIZEY; i++) {
    buffer[i] = malloc(sizeof(void *) * SIZEX);
  }

  Graph graph;
  graph.buffer = buffer;
  graph.left = a;
  graph.right = b;
  graph.sizeX = SIZEX;
  graph.sizeY = SIZEY;
  graph.centerX = (int) (-a / unitX * unitSizeX);
  graph.centerY = (int) (yB / unitY * unitSizeY);
  graph.unitX = unitX;
  graph.unitY = unitY;
  graph.unitSizeX = unitSizeX;
  graph.unitSizeY = unitSizeY;

  clearBuffer(&graph);
  drawAxes(&graph);
  drawChart(&graph);
  drawAnnotations(&graph);

  for (int i = 0; i < SIZEY; i++) {
    for (int j = 0; j < SIZEX; j++) {
      printf("%c", graph.buffer[i][j]);
    }
    printf("\n");
  }
}