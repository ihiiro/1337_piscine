#include <stdio.h>

typedef struct
{
  char col;
  char row;
} queen;

void init_init(queen *arr, int index, char row);
void init(queen *arr);
int survey_cols(queen *arr, int index, int i);
int survey_diagonals(queen *arr, int index, int i, char col, char row, int flp);
int survey(queen *arr, int index);
int survey_and_place(queen *arr, int index);
int backtrack(queen *arr, int index, int count);
void reset_rows(queen *arr, int start_index);
int ft_eight_queens_puzzle(void);

int main(void)
{
  printf("%d", ft_eight_queens_puzzle());
}

int ft_eight_queens_puzzle(void)
{
  queen queens[8];
  init(queens);
  return backtrack(queens, survey_and_place(queens, 1), 0);
}

void init_init(queen *arr, int index, char row)
{
  if (arr && index >= 0 && index <= 7)
  {
    arr[index].col = 'a';
    arr[index].row = row;
    init_init(arr, index - 1, row - 1);
  }
  else
  {
    return;
  }
}

void init(queen *arr)
{
  if (!arr)
  {
    return;
  }
  init_init(arr, 7, '8');
}

int survey_cols(queen *arr, int index, int i)
{
  if (!arr || index <= 0 || i < 0 || i > index || index > 7)
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
  survey_cols(arr, index, i + 1);
}

int survey_diagonals(queen *arr, int index, int i, char col, char row, int flp)
{
  if (!arr || index <= 0 || i < 0 || i > index || index > 7)
  {
    return -1;
  }
  else if (arr[i].col == col && arr[i].row == row)
  {
    return 0;
  }
  else if (flp < 0 && (col < 'a' || row < '1'))
  {
    survey_diagonals(arr, index, 0, arr[index].col + 1, arr[index].row - 1, 1);
  }
  else if (flp && (col > 'h' || row < '1'))
  {
    return 1;
  }
  else if (i == index)
  {
    survey_diagonals(arr, index, 0, col + flp, row - 1, flp);
  }
  else
  {
    survey_diagonals(arr, index, i + 1, col, row, flp);
  }
}

int survey(queen *arr, int index)
{
  if (!arr || index <= 0 || index > 7)
  {
    return -1;
  }
  return (
    survey_cols(arr, index, 0)
    &&
    survey_diagonals(arr, index, 0, arr[index].col - 1, arr[index].row - 1, -1)
  );
}

int survey_and_place(queen *arr, int index)
{
  if (!arr || index <= 0 || index > 7)
  {
    return -1;
  }
  else if (!survey(arr, index) && arr[index].col == 'h')
  {
    arr[index].col = 'a';
    return (index - 1);
  }
  else if (!survey(arr, index))
  {
    arr[index].col++;
    survey_and_place(arr, index);
  }
  else if (survey(arr, index) && index == 7)
  {
    return -2;
  }
  else
  {
    survey_and_place(arr, index + 1);
  }
}

int backtrack(queen *arr, int sap, int count)
{
  if (arr[0].col > 'h')
  {
    return count;
  }
  else if (sap == -2)
  {
    backtrack(arr, 7, count + 1);
  }
  else if (!arr || sap < 0 || sap > 7)
  {
    return -1;
  }
  else if (sap == 0)
  {
    reset_rows(arr, 1);
    arr[sap].col++;
    backtrack(arr, survey_and_place(arr, 1), count);
  }
  else if (arr[sap].col == 'h')
  {
    arr[sap].col = 'a';
    backtrack(arr, sap - 1, count);
  }
  else
  {
    arr[sap].col++;
    backtrack(arr, survey_and_place(arr, sap), count);
  }
}

void reset_rows(queen *arr, int start_index)
{
  if (!arr || start_index <= 0 || start_index >= 7)
  {
    return;
  }
  arr[start_index].col = 'a';
  reset_rows(arr, start_index + 1);
}
