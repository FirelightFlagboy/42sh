/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:19:48 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 09:36:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stdint.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <limits.h>
# include "my_errno.h"
# include "core.h"
# include "env.h"

# ifndef HASH_SIZE
#  define HASH_SIZE 10000
# endif

t_hash				**get_hash(void);
int					no_need_to_refresh(t_sh *sh);
void				ft_refresh_hash(void);
uintmax_t			ft_hashing(char *s);
void				ft_hash_free(t_hash **head);
void				ft_hash_node_free(t_hash **head);
t_hash				*ft_hash_create(char *key, char *path);
#endif
