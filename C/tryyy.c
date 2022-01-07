#include <stdio.h>
#include <string.h>

void inWord(char letter, char word[], int guessed[]);
int n=0;

int main()
{
  char word[] = "ARDA", letter = 'D', m[] = "____";
  int guessed[2], i;
  inWord(letter, word, guessed);

  


  getchar();
  return 0;
}

void inWord(char letter, char word[], int guessed[])
{
  int size, i, j;
  char m[] = "____";

  size = strlen(word);

  for(i=0; i<2; i++)
  {
    guessed[i] = 15;
  }

  for(i=0; i<size; i++)
  {
    if (word[i] == letter)
    {
      m[i] = letter;
    }

  }

  for(i=0; i<4; i++)
  {
    printf("%c", m[i]);
  }


}
