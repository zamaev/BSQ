/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 12:15:15 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/26 15:17:21 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.c"
#include <stdio.h>

int	main()
{
	char *string = "$$  hello $ world $ mine ";
	char *sep = " $ ";
	char **arr = ft_split(string, sep);
	int i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
