/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:29:25 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/23 12:24:04 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	print_args(char **str)
{
	str++;
	while (*str)
	{
		print_str(*str);
		str++;
	}
}

int		diff_str(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;
	char	*s;

	(void)argc;
	str = argv;
	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (diff_str(str[i], str[j]) > 0)
			{
				s = str[i];
				str[i] = str[j];
				str[j] = s;
			}
			j++;
		}
		i++;
	}
	print_args(str);
	return (0);
}
