#include <stdio.h>
#include <ctype.h>

int extractSum(char array[]);

int main()
{
  char arr[8];
  int i, sum;

  printf("Please enter the characters of the array\n");

  for (i=0; i<8; i++){
    scanf("%c", arr+i);
  }

  sum = extractSum(arr);
  printf("Total is: %d\n", sum);

  getchar();
  getchar();
  return 0;
}

int extractSum(char array[])
{
  int i, hascapital=0, capital, haszero=0, first=0, second=0, total=0, count=0;
  int num[4];

  for (i=0; i<4; i++){
    num[i] = 0;
  }

  for (i=0; i<8; i++){
    if (array[i] >= 'A' && array[i] <= 'Z'){
      hascapital = 1;
      capital = i;
    }
    else if (array[i] == '0') haszero = 1;
  }

  if (hascapital == 1){
    for (i=0; i<8; i++){
      if ((isdigit(array[i]) == 1) && (array[i] != array[capital])){
        if (count == 0) num[count] = array[i]*10;
        else if (count == 1){
          num[count] = array[i];
          break;
        }
        ++count;
      }
    }
  }
  else if (haszero == 1){
    count = 0;
    for (i=0; i<8; i++){
      if (isdigit(array[i]) == 1){
        if ((count == 0) && (array[i] != '0')) first = array[i];
        else if ((count == 1) && (array[i] != '0')){
          second = array[i];
          total += first*10 + second;
        }
        ++count;
      }
    }
  }


  else{
    count = 0;
    for (i=0; i<8; i++){
      if (isdigit(array[i]) == 1){
        if (count == 0 || count == 2) num[count] = array[i]*10;
        else if (count == 1 || count == 3){
          num[count] = array[i];
        }
        ++count;
      }
    }
  }
  for (i=0; i<4; i++){
    total += num[i];
  }
  return total;
}
