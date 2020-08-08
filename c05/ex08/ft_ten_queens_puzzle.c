/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:25:52 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/22 03:42:36 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_chess(int chess[9])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = '0' + chess[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		is_pos_avalible(int col, int chess[9])
{
	int i;

	i = 0;
	while (i < col)
	{
		if (chess[i] == chess[col]
			|| col - i == chess[col] - chess[i]
			|| col - i == chess[i] - chess[col])
			return (0);
		i++;
	}
	return (1);
}

int		get_pos(int col, int chess[9])
{
	int line;
	int options;

	options = 0;
	line = 0;
	while (line < 10)
	{
		chess[col] = line;
		if (is_pos_avalible(col, chess))
		{
			if (col == 9)
			{
				options += 1;
				print_chess(chess);
			}
			else
				options += get_pos(col + 1, chess);
		}
		line++;
	}
	return (options);
}

int		ft_ten_queens_puzzle(void)
{
	int chess[9];
	int line;
	int options;

	options = 0;
	line = 0;
	while (line < 10)
	{
		chess[0] = line;
		options += get_pos(1, chess);
		line++;
	}
	return (options);
}
