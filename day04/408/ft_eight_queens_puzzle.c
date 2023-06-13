#include <stdio.h>

int ft_eight_queens_puzzle(void);
int checker(int board[][8]);

int main(void)
{
  printf("%d", ft_eight_queens_puzzle());
}

int checker(int board[][8])
{
  // check rows
  int i = 0;
  int j = 0;
  int row_occupied = 0;
  int column_occupied = 0;
  while (i < 8)
  {
    j = 0;
    row_occupied = 0;
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
    i++;
  }

  return 1;
}



int ft_eight_queens_puzzle(void)
{
  int board[8][8] =
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  return checker(board);
}
