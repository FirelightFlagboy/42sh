/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:57:51 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:58:17 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 32

typedef struct		s_rdr
{
	char			*buff;
	char			*eol;
	int				tot_buff;
	int				char_buff;
	int				stop;
	int				fd;
}					t_rdr;

int					get_next_line(const int fd, char **line);

#endif
