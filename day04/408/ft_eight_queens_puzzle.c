#include <stdio.h>

struct queen
{
  char col;
  char row;
};
typedef struct queen queen;

void init(queen *arr, int index);
int survey_cols(queen *arr, int index, int i);
int survey_diagonals(queen *arr, int index, int i, char col, char row, int flp);

int main(void)
{
  queen queens[8];
  queens[0].col = 'a';
  queens[0].row = '1';
  queens[1].col = 'h';
  queens[1].row = '3';
  queens[2].col = 'b';
  queens[2].row = '1';
  // queens[3].col = 'a';
  // queens[3].col = 'a';
  // init(queens, 7);
  printf("%d", survey_diagonals(queens, 2, 0, queens[2].col - 1, queens[2].row - 1, 0));
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

int survey_cols(queen *arr, int index, int i)
{
  if (!arr || index <= 0 || i < 0 || i > index)
  {
    return -1;
  }
  else if (i == index)
  {
    return 1;
  }
  else if (arr[index].col == arr[i].col)
  {
    return 0;
  }
  // else if (arr[index].row == arr[i].row)
  // {
  //   return 0;
  // }
  survey_cols(arr, index, i + 1);
}

int survey_diagonals(queen *arr, int index, int i, char col, char row, int flp)
{
  if (!arr || index <= 0 || i < 0 || i > index)
  {
    return -1;
  }
  else if (arr[i].col == col && arr[i].row == row)
  {
    return 0;
  }
  else if (!flp && (col < 'a' || row < '1'))
  {
    survey_diagonals(arr, index, 0, arr[index].col + 1, arr[index].row - 1, 1);
  }
  else if (flp && (col > 'h' || row < '1'))
  {
    return 1;
  }
  else if (!flp && i == index)
  {
    survey_diagonals(arr, index, 0, col - 1, row - 1, flp);
  }
  else if (flp && i == index)
  {
    survey_diagonals(arr, index, 0, col + 1, row - 1, flp);
  }
  else
  {
    survey_diagonals(arr, index, i + 1, col, row, flp);
  }
}
