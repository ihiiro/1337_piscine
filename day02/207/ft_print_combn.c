#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_combn(int n);

int main()
{
  ft_print_combn(2);
}

void ft_print_combn(int n)
{
	// main
	if (n < 1 || n > 9)
	{
		return;
	}
	// create array and initialize end to 1
	char combinations[n];
	// fill array with all 0s
	for (int i = 0; i < n; i++)
	{
		combinations[i] = (i == (n - 1)) ? '1' : '0';
	}
	// iterative function
	int done = 0;
	void iter(int n)
	{
		if (done)
		{
			return;
		}
		//
		for (int i = n - 1; i >= 0; i--)
		{
			done = 1;
			if (!(combinations[i] == combinations[i] - 1) && combinations[n - 1] == '9')
			{
				done = 0;
				combinations[i]++;
				for (int j = i + 1; j < n; j++)
				{
					combinations[j] = combinations[j - 1] + 1;
				}
			}
		}
		// digit is a 9? increment the previous one and set the later ones to increments of it
		// for (int i = 0, bool9 = 0, bool89 = 0; i < n; i++)
		// {
		// 	if (combinations[i] == '9' && combinations[i - 1] == '8')
		// 	{
		// 		combinations[i - 2]++;
		// 		bool89 = 1;
		// 	}
		// 	if (combinations[i] == '9')
		// 	{
		// 		combinations[i - 1]++;
		// 		bool9 = 1;
		// 	}
		// 	if (bool9)
		// 	{
		// 		combinations[i] = combinations[i - 1] + 1;
		// 	}
		// 	if (bool89)
		// 	{
		// 		combinations[i - 1] = combinations[i - 2] + 1;
		// 		combinations[i] = combinations[i - 1] + 1;
		// 	}
		// }
		// display digits
		for (int i = 0; i < n; i++)
		{
			ft_putchar(combinations[i]);
		}
		ft_putchar(',');
		ft_putchar(' ');
		combinations[n - 1]++;
		iter(n);
	}
	// call iter
	iter(n);
}
