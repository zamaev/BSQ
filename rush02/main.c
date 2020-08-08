/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:04:14 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 19:35:06 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int	main(int argc, char **argv)
{
	char	*dic;
	char	*num;
	t_list	*list;

	dic = "numbers.dict";
	num = valid_num(argv[1]);
	if (argc == 3)
	{
		dic = argv[1];
		num = valid_num(argv[2]);
	}
	if (!num || argc == 1 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(list = parse_dic(dic)) || !(hundle_num(num, list)))
		write(1, "Dict Error", 10);
	write(1, "\n", 1);
	list_free(list);
	return (0);
}
