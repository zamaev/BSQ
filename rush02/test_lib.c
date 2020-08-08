/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:15:13 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 21:27:46 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int	test_id(t_list **pt, t_list **tmp)
{
	while (*pt != NULL)
	{
		*tmp = (*pt)->next;
		while (*tmp != NULL)
		{
			if (ft_strcmp((*pt)->id, (*tmp)->id) == 0)
				return (1);
			*tmp = (*tmp)->next;
		}
		*pt = (*pt)->next;
	}
	return (0);
}

int	test_str(t_list **pt2, t_list **tmp)
{
	while (*pt2 != NULL)
	{
		*tmp = (*pt2)->next;
		while (*tmp != NULL)
		{
			if (ft_strcmp((*pt2)->str, (*tmp)->str) == 0)
				return (1);
			*tmp = (*tmp)->next;
		}
		*pt2 = (*pt2)->next;
	}
	return (0);
}

int	test_doubles(t_list *pt)
{
	t_list *tmp;
	t_list *pt2;

	pt2 = pt;
	if (test_id(&pt, &tmp))
		return (1);
	if (test_str(&pt2, &tmp))
		return (1);
	return (0);
}

int	test_def_keys(t_list *pt)
{
	t_list		*list_pt;
	t_str_list	*str_pt;

	list_pt = NULL;
	str_pt = input_file("numbers.dict");
	parse_input(str_pt, &list_pt);
	str_list_free(str_pt);
	while (list_pt != NULL)
	{
		if (list_get_by_id(pt, list_pt->id) == NULL)
			return (1);
		list_pt = list_pt->next;
	}
	list_free(list_pt);
	return (0);
}
