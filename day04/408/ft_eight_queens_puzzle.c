#include <stdio.h>

int ft_eight_queens_puzzle(void);
int checker(int board[][8], int i, int j, int row_occupied, int column_occupied, int k);
int check(int board[][8]);

int main(void)
{
  printf("%d", ft_eight_queens_puzzle());
}

int ft_eight_queens_puzzle(void)
{
  int board[8][8] =
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1}
  };

  return check(board);
}

int checker(int board[][8], int i, int j, int row_occupied, int column_occupied, int k)
{
  if (i > 7)
  {
    return 1;
  }

  // check rows
  while (j < 8)
  {
    k = 0;
    column_occupied = 0;
    row_occupied += board[i][j];
    if (row_occupied > 1)
    {
      return 0;
    }
    // check columns
    while (k < 8)
    {
      column_occupied += board[k][j];
      if (column_occupied > 1)
      {
        return 0;
      }
      k++;
    }
    j++;
  }

  checker(board, i + 1, 0, 0, 0, 0);
}

int check(int board[][8])
{
  return checker(board, 0, 0, 0, 0, 0);
}
