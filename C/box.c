#include <stdio.h>

void print_box(int x, int y);

int main()
{
  int x, y;

  printf("Enter x y\n");
  scanf("%d %d", &x, &y);
  print_box(x, y);

  getchar();
  getchar();
  return 0;
}

void print_box(int x, int y)
{
  int i, j;

  for (i=0; i<y; i++){
    if (i == 0 || i == y-1){
      if (i == 0){
        printf("\u250F");
        for (j=0; j<((x-2)*2)+2; j++){
          printf("\u2501");
        }
        printf("\u2513\n");
      }
      else{
        printf("\u2517");
        for (j=0; j<((x-2)*2)+2; j++){
          printf("\u2501");
        }
        printf("\u251B\n");
      }
    }
    else{
      printf("\u2523");
      printf("%*c", ((x-2)*2)+2, ' ');
      printf("\u252B\n");
    }
  }
}
