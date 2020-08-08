/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:27:04 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/16 23:47:28 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		start;
	int		fl;
	char	s;

	start = 1000000000;
	fl = 0;
	while (start >= 1)
	{
		s = '0' + nb / start;
		if (s != '0')
		{
			fl = 1;
		}
		if (fl == 1)
		{
			write(1, &s, 1);
		}
		nb = nb - (nb / start) * start;
		start = start / 10;
	}
}

int main(void)
{
    ft_putnbr(0);
}
