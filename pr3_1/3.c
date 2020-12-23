#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct path {
  int from;
  int to;
} path;

typedef struct vec {
  path *array;
  int length;
  int size;
} vec;

vec *vec_new(int size) {
  vec *v = (vec *) malloc(sizeof(vec));
  v->array = malloc(sizeof(path) * size);
  v->length = 0;
  v->size = size;
  return v;
}

void vec_add(vec *v, path p) {
  if (v->length >= v->size) {
    v->size += 10;
    v->array = realloc(v->array, sizeof(path) * v->size);
  }
  v->array[v->length] = p;
  v->length++;
}

void vec_destroy(vec *v) {
  free(v->array);
  free(v);
}

bool has_path(vec *v, int from, int to) {
  if (from > to)
    return false;
  bool result = false;
  for (int i = 0; i < v->length; i++) {
    path p = v->array[i];
    if (p.from == from && p.to == to) return true;
    if (p.from == from)
      result = result || has_path(v, p.to, to);
  }
  return result;
}

int main() {
  int n;
  printf("Enter target: ");
  scanf("%d", &n);

  vec* v = vec_new(1);

  printf("Enter connected points (two per line, delimited by space, \"0 0\" to end sequence:\n");
  while (true) {
    int f, t;
    path p;
    scanf("%d %d", &f, &t);
    if (f == 0 && t == 0) {
      break;
    }
    p.from = f;
    p.to = t;
    vec_add(v, p);
  }

  for (int i = 0; i < v->length; i++) {
    printf("%d %d\n", v->array[i].from, v->array[i].to);
  }

  if (has_path(v, 1, n)) {
    printf("Path from point 1 to pint %d exists\n", n);
  } else {
    printf("Path from point 1 to pint %d doesn't exist\n", n);
  }

  vec_destroy(v);
}