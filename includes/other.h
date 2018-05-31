/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:43:49 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/09 13:30:04 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

# include "sh_struct.h"

void	ft_free_tchar(char **ts);
int		ft_access(char *path, int mode);
void	ft_gen_promt(t_sh *sh);
void	ft_check_placement(void);
#endif
