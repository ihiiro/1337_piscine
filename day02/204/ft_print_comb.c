#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb(void);

int main()
{
  ft_print_comb();
}

void ft_print_comb(void)
{
	void iter(char one, char two, char three, char root_one, char root_two, char root_three)
	{
		// helper
		void display(int comma)
		{
			if (comma)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar(one);
			ft_putchar(two);
			ft_putchar(three);
		}
		// main
		if (one == '7' && two == '8' && three == '9')
		{
			display(1);
			return;
		}
		// for the beginning no-comma case
		if (one == '0' && two == '1' && three == '2')
		{
			display(0);
			iter(one, two, three + 1, root_one, root_two, root_three);
			return;
		}
		// increment root: root is the beginning of a series xyz where x is a new increment
		if (two == '8' && three == '9')
		{
			display(1);
			iter(root_one + 1, root_two + 1, root_three + 1, root_one + 1, root_two + 1, root_three + 1);
			return;
		}
		// change the last two digits
		if (three == '9')
		{
			display(1);
			iter(one, two + 1, two + 2, root_one, root_two, root_three);
			return;
		}

		display(1);
		iter(one, two, three + 1, root_one, root_two, root_three);
	}

	iter('0', '1', '2', '0', '1', '2');
}
