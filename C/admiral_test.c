#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void draw();
void initialize_table();
void placeShip(int x, int y, int shipsize, int orientation);
int sonar(int x, int y, int shipsize, int orientation);

char elements[10][11];

int main()
{
  int shipsize, x, y, ship4=1, ship3=2, ship2=3, ship1=4, count=0, orientation;
  double time_spent;
  time_t timer;
  clock_t begin, end;
  begin = clock();

  printf("This may take as long as 100 counts\n\n");
  sleep(1);

  initialize_table();
  draw();

  while(1){
    printf("Count:%d\n", count);
    ++count;
    srand(time(&timer));
    x = rand() % 9;
    y = rand() % 9;
    orientation = 1;

    if (ship4 != 0){

      if (sonar(x, y, 4, orientation) == 1){
        ship4--;
        placeShip(x, y, 4, orientation);
        draw();
      }

      continue;
    }
    else if (ship3 != 0){

      if (sonar(x, y, 3, orientation) == 1){
        ship3--;
        placeShip(x, y, 3, orientation);
        draw();
      }

      continue;
    }
    else if (ship2 != 0){

      if (sonar(x, y, 2, orientation) == 1){
        ship2--;
        placeShip(x, y, 2, orientation);
        draw();
      }

      continue;
    }
    else if (ship1 != 0){

      if (sonar(x, y, 1, 1) == 1){
        ship1--;
        placeShip(x, y, 1, 1);
        draw();
      }

      continue;
    }
    else
      break;
  }
  end = clock();
  time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
  printf("GAME OVER!\n");
  printf("Time passed:%lf s\n", time_spent*10000.00);
  getchar();
  return 0;
}

void draw()
{
  int i, j;
  printf("  0 1 2 3 4 5 6 7 8 9\n");
  for (i=0; i<10; i++){
    printf("%d", i);
    for (j=0; j<11; j++){
      printf(" %c", elements[i][j]);
    }
  }
  printf("---------------------------\n");
}

void initialize_table()
{
  int i, j;
  for (i=0; i<10; i++){
    for (j=0; j<11; j++){
      elements[i][j] = '.';
      if (j == 10){
        elements[i][j] = '\n';
      }
    }
  }
}

void placeShip(int x, int y, int shipsize, int orientation)
{
  int i;
  char shipfont = 64;

  if (orientation == 1){
    for (i=0; i<shipsize; i++) elements[x][y] = shipfont, x++;
  }
  else if (orientation == 0){
    for (i=0; i<shipsize; i++) elements[x][y] = shipfont, y++;
  }

}


int sonar(int x, int y, int shipsize, int orientation)
{
  int n = (shipsize+2), x_count=0, y_count=0;

  if (shipsize == 1){
    if (x == 0 && y == 0){
      if (elements[x+1][y+1] == '.')
        return 1;
      }
    if (x == 9 && y == 0){
      if (elements[x-1][y+1] == '.')
        return 1;
      }
    if (x == 0 && y == 9){
      if (elements[x+1][y-1] == '.')
        return 1;
      }
    if (x == 9 && y == 9){
      if (elements[x-1][y-1] == '.')
        return 1;
      }
    if (elements[x+1][y] != '.')
      return 0;
    if (elements[x+1][y-1] != '.')
      return 0;
    if (elements[x+1][y+1] != '.')
      return 0;
    if (elements[x][y-1] != '.')
      return 0;
    if (elements[x][y+1] != '.')
      return 0;
    if (elements[x-1][y] != '.')
      return 0;
    if (elements[x-1][y-1] != '.')
      return 0;
    if (elements[x-1][y+1] != '.')
      return 0;
    return 1;
  }

  else if ((shipsize > 1) && (orientation == 1)){
    while (1){
      if (y_count == n*3)
        return 1;
      if (y_count % 3 == 0 && y_count != 0){
        x++;
        if (x == 9)
          return 1;
        y -= 2;
      }
      if (elements[x-1][y-1] != '.'){
        return 0;
        break;
      }
      y_count++;
      y++;
    }
    return 0;
  }


  else if (shipsize > 1 && orientation == 0){
    while (elements[x+1][y-1] == '.'){
      if (x_count == n*3) return 1;
      if (x_count % 3 == 0 && x_count != 0){
       y++;
       x -= 2;
     }
      x--, x_count++;
    }
    return 0;
  }
  return 0;
}
