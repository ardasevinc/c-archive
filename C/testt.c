#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void draw();
void placeShip(int, int, int);
void initialize_table();
int sonar(int, int, int, int);

char elements[10][11];
int rand_val;

int main()
{
  time_t timer;
  int x, y, shipsize=0, count=1;

  initialize_table();
  draw();
  printf("---------------------------\n\n");

  while(1){
    printf("Round:%d\n\n", count);
    count++;
    sleep(2);
    srand(time(&timer));
    shipsize = rand() % 4;
    if (shipsize == 0){
      continue;
    }
    placeShip(rand() % 9, rand() % 9, shipsize);
    draw();
  }
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
  printf("---------------------------");
}

void placeShip(int x, int y, int shipsize)
{
  int i, sonar_val, ship4=1, ship3=2, ship2=3; ship1=4;
  char shipFont_x = 35, shipFont_y = 64;

  time_t timer;
  srand(time(&timer));

  rand_val = rand() % 2;

  sonar_val = sonar(x, y, shipsize, rand_val);

  printf("\n\n");
  if (shipsize == 1){
    if (elements[x][y] == '.') elements[x][y] = shipFont_x;
  }
  else if (shipsize > 1){
    if (rand_val == 0){
      if (sonar_val == 1){
        for (i=0; i<shipsize; i++){
          if (elements[x][y] == '.'){
            elements[x][y] = shipFont_x;
            x++;
          }
        }
      }
    }
    else{
      if (sonar_val){
        for(i=0; i<shipsize; i++){
          if (elements[x][y] == '.'){
            elements[x][y] = shipFont_y;
            y++;
          }
        }
      }
    }
  }
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

int sonar(int x, int y, int shipsize, int rand_val)
{
  int i, x_org=x, y_org=y;

  if (rand_val == 0)
  {
    for (i=0; i<shipsize+1; i++){
      if (elements[x][y] != '.'){
        return 0;
      }
      else{
        x++;
      }
    }
    x = x_org;

    for (i=0; i<shipsize+1; i++){
      if (elements[x][y-1] != '.'){
        return 0;
      }
      else{
        x++;
      }
    }
    x = x_org;

    for (i=0; i<shipsize+1; i++){
      if (elements[x][y+1] != '.'){
        return 0;
      }
      else{
        x++;
      }
    }
    x = x_org;

    for (i=0; i<3; i++){
      if (elements[x-1][y-1] != '.'){
        return 0;
      }
      else{
        y++;
      }
    }
    y = y_org;
    return 1;
  }

  else
  {
    for (i=0; i<shipsize+1; i++){
      if (elements[x][y] != '.'){
        return 0;
      }
      else{
        y++;
      }
    }
    y = y_org;

    for (i=0; i<shipsize+1; i++){
      if (elements[x-1][y] != '.'){
        return 0;
      }
      else{
        y++;
      }
    }
    y = y_org;

    for (i=0; i<shipsize+1; i++){
      if (elements[x+1][y] != '.'){
        return 0;
      }
      else{
        y++;
      }
    }
    y = y_org;

    for (i=0; i<3; i++){
      if (elements[x-1][y-1] != '.'){
        return 0;
      }
      else{
        x++;
      }
    }
    x = x_org;
  }
  return 1;
}
