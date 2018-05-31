/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:37:28 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/02 14:34:53 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

# include "sh_struct.h"

/*
**	Cleaning
*/

void				closesh(t_sh **sh);
char				*treat_quotes(char *cmd);
#endif
