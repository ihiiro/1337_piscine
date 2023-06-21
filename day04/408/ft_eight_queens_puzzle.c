#include <stdio.h>

struct queen
{
  char col;
  char row;
};
typedef struct queen queen;

void init(queen *arr, int index);

int main(void)
{
  queen queens[8];
  init(queens, 7);
}

void init(queen *arr, int index)
{
  if (arr && index >= 0)
  {
    arr[index].col = 'a';
    arr[index].row = '1';
    init(arr, index - 1);
  }
  else
  {
    return;
  }
}
