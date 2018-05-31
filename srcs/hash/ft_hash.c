/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:14:48 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/04 10:57:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

uintmax_t	ft_hashing(char *s)
{
	uintmax_t	hash;
	int			c;

	hash = 5381;
	while ((c = *s++))
		hash = ((hash << 5) + hash) + c;
	return (hash % HASH_SIZE);
}

void		ft_hash_node_free(t_hash **head)
{
	t_hash	*node;
	t_hash	*tmp;

	node = *head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->key);
		free(tmp->path);
		free(tmp);
	}
	*head = NULL;
}

void		ft_hash_free(t_hash **head)
{
	int	i;

	i = 0;
	if (head == NULL)
	{
		return ;
	}
	while (i < HASH_SIZE)
	{
		ft_hash_node_free(head + i);
		i++;
	}
}

t_hash		*ft_hash_create(char *key, char *path)
{
	t_hash	*node;

	if (!(node = (t_hash*)malloc(sizeof(t_hash)))\
	&& (g_errn = ERR_MALLOC))
		return (NULL);
	node->next = NULL;
	if (!(node->key = ft_strdup(key))\
	&& (g_errn = ERR_MALLOC))
		return (NULL);
	if (!(node->path = ft_strdup(path))\
	&& (g_errn = ERR_MALLOC))
		return (NULL);
	return (node);
}
