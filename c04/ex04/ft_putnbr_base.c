/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:51:29 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/21 04:35:57 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		isbase(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!base[i + 1] || base[i] == '+' || base[i] == '-')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == '-' || base[j] == '+')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	printbasenum(int nbr, int b, char *base)
{
	int		s;
	int		n;
	char	c;

	if (nbr < 0)
		write(1, "-", 1);
	s = nbr > 0 ? nbr % b : nbr % b * -1;
	n = nbr > 0 ? nbr / b : nbr / b * -1;
	if (n != 0)
		printbasenum(n, b, base);
	c = base[s];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int b;

	b = isbase(base);
	if (b)
	{
		printbasenum(nbr, b, base);
	}
}
