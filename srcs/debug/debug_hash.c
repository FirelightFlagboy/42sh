/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:11:52 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 08:33:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static inline int		debug_hash_have_next_node(t_hash **hash, int index)
{
	while (++index < HASH_SIZE)
	{
		if (hash[index])
			return (1);
	}
	return (0);
}

static inline void		debug_hash_set_str(\
	char **ts, char **tt, t_hash **hash, int index)
{
	if (debug_hash_have_next_node(hash, index))
	{
		*ts = "├";
		*tt = "│";
	}
	else
	{
		*ts = "└";
		*tt = " ";
	}
}

static inline void		debug_hash_print_node(char *t, t_hash *node)
{
	char *s;

	while (node)
	{
		if (node->next)
			s = "├";
		else
			s = "└";
		ft_eprintf("%s   %s── bin > %-20s : path > %s\n",\
		t, s, node->key, node->path);
		node = node->next;
	}
}

void					ft_print_hash(void)
{
	t_hash	**hash;
	t_hash	*node;
	char	*s;
	char	*t;
	int		i;

	hash = get_hash();
	i = -1;
	ft_eprintf("============= hash ===========\n\n");
	ft_eprintf("hash\n");
	while (++i < HASH_SIZE)
	{
		if ((node = hash[i]))
		{
			debug_hash_set_str(&s, &t, hash, i);
			ft_eprintf("%s── at %d\n", s, i);
			debug_hash_print_node(t, hash[i]);
		}
	}
	ft_eprintf("\n============= hash ===========\n\n");
}
