/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:05:24 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/17 23:32:22 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int k;
	int n;
	int c;

	i = 0;
	while (i < size)
	{
		k = i + 1;
		n = i;
		while (k < size)
		{
			if (tab[k] < tab[n])
			{
				n = k;
			}
			k++;
		}
		c = tab[i];
		tab[i] = tab[n];
		tab[n] = c;
		i++;
	}
}
