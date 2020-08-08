/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:19:02 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 19:40:33 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# define INPUT_BUF 1024

typedef struct			s_str_list
{
	char				*str;
	int					size;
	struct s_str_list	*next;
}						t_str_list;

typedef	struct	s_list
{
	char			*id;
	char			*str;
	struct s_list	*next;
}				t_list;

void			ft_print_str(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);

t_list			*list_init(char *input_id, char *input_str);
t_list			*list_push_last(t_list **head, char *input_id, char *input_str);
t_list			*list_get_by_id(t_list *head, char *input_id);
void			list_free(t_list *pt);

t_list			*parse_dic(char *dic);
int				hundle_num(char *num, t_list *list);

char			*valid_num(char *num);
int				print_one_char(char a, t_list *list);
int				print_two_char(char a, char b, t_list *list);

t_str_list	*str_list_init(char *input_str, int input_size);
t_str_list	*str_list_push_last(t_str_list **head, char *input_str, int input_size);
void		str_list_free(t_str_list *pt);

int			error(char *str);
int			input_file_ext(int fd, int *read_size, char **str);
t_str_list	*input_file(char *file);
char		get_lc(int i, t_str_list *pt);
int			ft_isspace(char c);

int			get_key(t_str_list *in, char **key, int *i);
int			get_value(t_str_list *in, char **value, int *i);
int			parse_input(t_str_list *in, t_list **pt);

int		test_id(t_list **pt, t_list **tmp);
int		test_str(t_list **pt2, t_list **tmp);
int			test_doubles(t_list *pt);
int			test_def_keys(t_list *pt);

#endif
