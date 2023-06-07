#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_combn(int n);

int main()
{
  ft_print_combn(10);
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
	int done = 0;
	// fill array with all '0's then last digit to '1'
	for (int i = 0; i < n; i++)
	{
		combinations[i] = (i == (n - 1)) ? '1' : '0';
	}
	void display()
	{
		for (int i = 0; i < n; i++)
		{
			ft_putchar(combinations[i]);
		}
		if (!done)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
	// iterative function
	void iter(int n)
	{
		// base case and handling of commas
		if (combinations[n - 1] == ':')
		{
			return;
		}
		for (int i = n - 2; i >= 0; i--)
		{
			if (combinations[n - 1] == '9')
			{
				display();
				if (combinations[i] != combinations[i + 1] - 1)
				{
					combinations[i]++;
					for (int j = i + 1; j < n; j++)
					{
						combinations[j] = combinations[j - 1] + 1;
					}
				}
			}
		}
		// increment the last digit on the right
		if (combinations[n - 1] + 1 == ':')
		{
			done = 1;
		}
		// display digits
		display();
		combinations[n - 1]++;
		iter(n);
	}
	// call iter
	iter(n);
}
