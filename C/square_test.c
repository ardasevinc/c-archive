#include <stdlib.h>
#include <stdio.h>

void print_square_cell(int, char);

int main()
{
  int side, cell_1, cell_2, i, j;
  char symbol;

  printf("Enter one side of the square: ");
  scanf("%d", &side);
  printf("Enter cell type (5 5 means 5x5 cell): ");
  scanf("%d %d", &cell_1, &cell_2);
  getchar();
  printf("Enter a char: ");
  scanf("%c", &symbol);

  if ((cell_1 == cell_2) == 1){
      print_square_cell(side, symbol);
  }
  else{
    for (i=1; i<=cell_2; i++){
      for (j=1; j<=cell_1; j++){
        print_square_cell(side, symbol);
      }
    }
  }


  getchar();
  printf("Press enter to exit...");
  getchar();
}


void print_square_cell(int n, char x)
{
  int i;

  for(i=1; i <= (n*5); i++){
    printf("%c", x);
    if (((i % n) == 0) && ((i != n*5))){
      printf("\n");
    }
  }
}
