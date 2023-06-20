#include <stdio.h>

struct Queen
{
  char row;
  char col;
};
typedef struct Queen queen;

void update_if_prev_overflow(queen *arr, int index, int cascade);

int main(void)
{
  queen arr[8];
  arr[0].row = '8';
  arr[0].col = 'h';
  arr[1].row = '8';
  arr[1].col = 'h';
  arr[2].row = '8';
  arr[2].col = 'h';
  arr[3].row = '2';
  arr[3].col = 'c';
  arr[4].row = '5';
  arr[4].col = 'f';

  for (int i = 0; i < 5; i++)
  {
    printf("Q%c%c, ", arr[i].col, arr[i].row);
  }

  printf("\n\n");
  update_if_prev_overflow(arr, 3, 0);

  for (int i = 0; i < 5; i++)
  {
    printf("Q%c%c, ", arr[i].col, arr[i].row);
  }
}

void update_if_prev_overflow(queen *arr, int index, int cascade)
{
  if (!arr || index < 0)
  {
    return;
  }
  if (arr[index - 1].col == 'h' && arr[index - 1].row == '8')
  {
    if (arr[index].row < '8')
    {
      arr[index].row++;
    }
    else if (arr[index].row == '8' && arr[index].col < 'h')
    {
      arr[index].row = '1';
      arr[index].col++;
    }
    else if (arr[index].row == '8' && arr[index].col == 'h')
    {
      arr[index].row = '1';
      arr[index].col = 'a';
    }
    update_if_prev_overflow(arr, index - 1, 1);
  }
  else if (cascade)
  {
    arr[index].col = 'a';
    arr[index].row = '1';
    update_if_prev_overflow(arr, index - 1, cascade);
  }
}
