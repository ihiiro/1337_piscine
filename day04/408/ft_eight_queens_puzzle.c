#include <stdio.h>

int ft_eight_queens_puzzle(void);
int checker(int board[][8], int i, int j, int row_occupied, int column_occupied);
int check(int board[][8]);

int main(void)
{
  printf("%d", ft_eight_queens_puzzle());
}

int checker(int board[][8], int i, int j, int row_occupied, int column_occupied)
{
  if (i > 7)
  {
    return 1;
  }

  // check rows
  while (j < 8)
  {
    if (board[i][j])
    {
      row_occupied++;
    }
    if (row_occupied > 1)
    {
      return 0;
    }
    j++;
  }

  checker(board, i + 1, 0, 0, 0);
}

int check(int board[][8])
{
  return checker(board, 0, 0, 0, 0);
}

int ft_eight_queens_puzzle(void)
{
  int board[8][8] =
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  return check(board);
}
