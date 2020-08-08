/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:02:43 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 21:19:18 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

t_list	*parse_dic(char *dic)
{
	t_list		*pt;
	t_str_list	*pt2;

	pt = NULL;
	pt2 = NULL;
	if (ft_strlen(dic) < 1)
		return (NULL);
	if ((pt2 = input_file(dic)) == NULL)
		return (0);
	if ((parse_input(pt2, &pt)) == 1)
		return (0);
	str_list_free(pt2);
	if (test_def_keys(pt))
		return (NULL);
	if (test_doubles(pt))
		return (NULL);
	return (pt);
}
