#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void draw();
void initialize_table();
void placeShip(int x, int y, int shipsize, int orientation);
int sonar(int i, int j, int shipsize, int orientation);

char elements[10][11];

int main()
{
  int x, y, ship4=1, ship3=2, ship2=3, ship1=4, count=0, orientation;
  time_t timer;



  initialize_table();
  srand(time(&timer));
  while(1==1){
    printf("Count:%d\n", count);
    ++count;

    x = rand() % 10;
    y = rand() % 10;
    orientation = rand() % 2;

    if (ship4 != 0){

      if (sonar(x, y, 4, orientation)){
        ship4--;
        placeShip(x, y, 4, orientation);
      }
      continue;
    }
    else if (ship3 != 0){

      if (sonar(x, y, 3, orientation)){
        ship3--;
        placeShip(x, y, 3, orientation);
      }
      continue;
    }
    else if (ship2 != 0){

      if (sonar(x, y, 2, orientation)){
        ship2--;
        placeShip(x, y, 2, orientation);
      }
      continue;
    }
    else if (ship1 != 0){

      if (sonar(x, y, 1, 0)){
        ship1--;
        placeShip(x, y, 1, 0);
      }
      continue;
    }
    else
      break;
  }
  printf("---------------------\n");
  draw();
  printf("\nGAME OVER!\n");
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
  printf("---------------------\n");
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
    for (i=0; i<shipsize; i++){
      elements[x][y] = shipfont;
      x++;
    }
  }
  else if (orientation == 0){
    for (i=0; i<shipsize; i++){
      elements[x][y] = shipfont;
      y++;
    }
  }
}





int sonar(int i, int j, int shipsize, int orientation)
{
  int n = shipsize+2, count = 1,maxval = n*3, j_count = 1;

  if (shipsize == 1){
    if (i == 0 && j == 0){
      while (elements[i][j] == '.'){
        if (count == 4) return 1;
        else{
          if (j_count == 2){
            ++i;
            j -= 2;
          }
          ++j;
          ++ j_count;
        }
        ++count;
      }
      return 0;
    }
    else if (i == 9 && j == 0){
      while (elements[i-1][j] == '.'){
        if (count == 4) return 1;
        else{
          if (j_count == 2){
            ++i;
            j -= 2;
          }
          ++j;
          ++j_count;
        }
        ++count;
      }
      return 0;
    }
    else if (i == 9 && j == 9){
      while (elements[i-1][j] == '.'){
        if (count == 4) return 1;
        else{
          if (j_count == 2){
            ++i;
            j += 2;
          }
          --j;
          ++j_count;
        }
        ++count;
      }
      return 0;
    }
    else if (i == 0 && j == 9){
      while (elements[i][j-1] == '.'){
        if (count == 4) return 1;
        else{
          if (j_count == 2){
            ++i;
            j -= 2;
          }
          ++j;
          ++j_count;
        }
        ++count;
      }
      return 0;
    }
    else{
      if ((i != 0 || i != 9) && (j != 0 || j != 9)){
        maxval = 1*9;
        while (elements[i-1][j-1] == '.'){
          if (count == maxval) return 1;
          else{
            if (j_count % 3 == 0){
              ++i;
              j -= 3;
            }
            ++j;
            ++j_count;
          }
          ++count;
        }
        return 0;
      }
    }
    return 0;
  }

  else{
    if (orientation == 1){
      if (i + shipsize == 9) maxval = (n-1) * 3;
      else if (i == 0 && (j != 0 || j != 9)){
        while (elements[i][j-1] == '.')
        {
          if (count == (n-1)*3) return 1;

          else{
            if (j_count % 3 == 0){
              ++i;
              j -= 3;
            }
            ++j;
            ++j_count;
          }
          ++count;
        }
        return 0;
      }
      else if (j == 0 && (i != 0 || i != 9)){
        while (elements[i-1][j] == '.'){
          if (count == n*2) return 1;
          else{
            if (j_count % 2 == 0){
              ++i;
              j -= 2;
            }
            ++j;
            ++j_count;
          }
          ++count;
        }
        return 0;
      }
      else if (j == 9 && (i != 0 || i!= 9)){
        while (elements[i-1][j] == '.'){
          if (count == (n-1)*2) return 1;
          else{
            if (j_count % 2 == 0){
              ++i;
              j += 2;
            }
            --j;
            ++j_count;
          }
          ++count;
        }
        return 0;
      }

      while (elements[i-1][j-1] == '.')
      {
        if (count == maxval) return 1;

        else{
          if (j_count % 3 == 0){
            ++i;
            j -= 3;
          }
          ++j;
          ++j_count;
        }
        ++count;
      }
    }
    else if (orientation == 0){
      if (i == 9 && (j != 9 || j !=0)) maxval = n*2;
      else if (j + shipsize == 9) maxval = (n-1)*3;
      else if (i == 0 && (j != 0 || j != 9)){
        maxval = n*2;
        while (elements[i][j-1] == '.'){
          if (count == maxval) return 1;
          else{
            if (j_count % n == 0){
              ++i;
              j -= n+1;
            }
            ++j;
            ++j_count;
          }
          ++count;
        }
        return 0;
      }
      else if (j == 0 && (i != 0 || i != 9)){
        maxval = (n-1) * 3;
        while (elements[i-1][j] == '.'){
          if (count == maxval) return 1;
          else{
            if ((j_count % n-1) == 0){
              ++i;
              j -= n;
            }
            ++j;
            ++j_count;
          }
          ++count;
        }
        return 0;
      }
      while (elements[i-1][j-1] == '.'){
        if (count == maxval) return 1;
        else{
          if (j_count % n == 0){
            ++i;
            j -= n;
          }
          ++j;
          ++j_count;
        }
        ++count;
      }
      return 0;
    }
  }
  return 0;
}
