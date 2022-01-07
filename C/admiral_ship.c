#include <stdio.h>
#include <windows.h>

void draw_battleships_board(int, int);
void place_ship(int);


int main()
{
  int x, y;
  SetConsoleOutputCP(65001);
  printf("Enter x y\n");
  scanf("%d %d", &x, &y);

  draw_battleships_board(x, y);

  return 0;
}
void draw_battleships_board(int x, int y)
{
  int i, j, n;

  for (i=0; i<y; i++){
    if (i == 0 || i == y-1){
      if (i == 0){
        printf("\u250F");
        for (j=0; j<x; j++){
          printf("\u252F");
        }
        printf("\u2513\n");
      }
      else{
        printf("\u2517");
        for (j=0; j<x; j++){
          printf("\u2537");
        }
        printf("\u251B\n");
      }
    }
    else{
      printf("\u2520");
      for (n=0; n<x; n++){
        printf("\u253C");
        printf("\u2573");
      }
      printf("\u2528\n");
    }
  }
}

void place_ship(int size)
{

}
