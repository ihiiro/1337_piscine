#include <stdio.h>

struct Queen
{
  char row;
  char col;
};
typedef struct Queen queen;

void update_if_prev_overflow(queen *arr, int index, int cascade);
void init(queen *arr, int index);

int main(void)
{
  queen arr[8];
  init(arr, 7);

  for (int i = 0; i < 8; i++)
  {
    printf("Q%c%c, ", arr[i].col, arr[i].row);
  }

  printf("\n\n");
  update_if_prev_overflow(arr, 7, 0);

  for (int i = 0; i < 8; i++)
  {
    printf("Q%c%c, ", arr[i].col, arr[i].row);
  }
}

void init(queen *arr, int index)
{
  if (!arr || index < 0)
  {
    return;
  }
  arr[index].col = 'a';
  arr[index].row = '1';
  init(arr, index - 1);
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
