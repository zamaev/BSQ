/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 14:37:07 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/19 14:48:17 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	getchar(int i, int j, int x, int y)
{
	if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
	{
		if (i == 0 && (j == 0 || j == y - 1))
		{
			ft_putchar('A');
		}
		else if (i == x - 1 && (j == 0 || j == y - 1))
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			getchar(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
}
