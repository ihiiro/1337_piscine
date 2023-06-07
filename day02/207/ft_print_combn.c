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
	int i;
	int j;
	// fill array with all '0's then last digit to '1'
	i = 0;
	while (i < n)
	{
		combinations[i] = (i == (n - 1)) ? '1' : '0';
		if (i == (n - 1))
		{
			combinations[i] == '1';
		}
		else
		{
			combinations[i] == '0';
		}
		i++;
	}
	void display()
	{
		int i = 0;
		while (i < n)
		{
			ft_putchar(combinations[i]);
			i++;
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
		i = n - 2;
		while (i >= 0)
		{
			if (combinations[n - 1] == '9')
			{
				display();
				if (combinations[i] != combinations[i + 1] - 1)
				{
					combinations[i]++;
					j = i + 1;
					while (j < n)
					{
						combinations[j] = combinations[j - 1] + 1;
						j++;
					}
				}
			}
			i--;
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
