#include <stdio.h>

struct queen
{
  char col;
  int row;
};
typedef struct queen Queen;

int ft_eight_queens_puzzle(void);
int enumerate(Queen *queens, Queen init_pos, int solution_nbr);
void init(Queen *queens, Queen pos);
void init_init(Queen *queens, int i);

int main(void)
{
  // printf("%d", ft_eight_queens_puzzle());
  ft_eight_queens_puzzle();
}

int ft_eight_queens_puzzle(void)
{
  Queen queens[8];

  init_init(queens, 0);

  int i = 0;
  while (i < 8)
  {
    printf("Q%c%d\n", queens[i].col, queens[i].row);
    i++;
  }

  return 0;
}

int enumerate(Queen *queens, Queen init_pos, int solution_nbr)
{
  if (!queens)
  {
    return -1;
  }
  else if (init_pos.col == 'h' && init_pos.row == 8)
  {
    return solution_nbr;
  }

}

void init(Queen *queens, Queen pos)
{
  if (!queens)
  {
    return;
  }
  queens[0] = pos;
}

void init_init(Queen *queens, int i)
{
  if (!queens || i == 8)
  {
    return;
  }
  queens[i].col = 'a';
  queens[i].row = 1;
  init_init(queens, i + 1);
}
