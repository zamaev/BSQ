/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 22:05:33 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/17 23:00:51 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int step;
	int s;

	i = 0;
	step = size / 2;
	while (i <= step)
	{
		s = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = s;
		i++;
	}
}
