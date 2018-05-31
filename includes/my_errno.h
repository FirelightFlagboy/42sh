/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:30:52 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/28 15:58:51 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ERRNO_H
# define MY_ERRNO_H

# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf.h"

typedef enum	e_verr
{
	ERR_OK,
	ERR_NOPATH,
	ERR_MALLOC,
	ERR_CHDIR,
	ERR_STAT,
	ERR_NOENT,
	ERR_NOOLDPWD,
	ERR_ACCESS,
	ERR_OPEN,
	ERR_READ,
	ERR_SIZE,
	ERR_RANGE,
	ERR_FORK,
	ERR_PARSING,
	ERR_NAMETOOLONG,
	ERR_ISNOTDIR,
	ERR_ISNOTFILE,
	ERR_ISDIR,
	ERR_ISBLK,
	ERR_ISFIFO,
	ERR_ISLNK,
	ERR_ISSOCK,
	ERR_ISCHR,
	ERR_ISREG,
	ERR_BADARG,
	ERR_FAULT,
	ERR_ARGTOOMUCH,
	ERR_AGRMISSING,
	ERR_NOCMD,
	LAST
}				t_verr;

# ifndef EXIT_STOP
#  define EXIT_STOP 2
# endif

# ifndef EXIT_WARNING
#  define EXIT_WARNING 3
# endif

/*
** Global var for my simple errno
*/
uint32_t	g_errn;

char	*ft_strsignal(int sig);
char	*ft_strerror(int errnum);
size_t	ft_strlen_err(char const *s);
int		ft_atoi_to_buff(uint32_t nb, char *buf);
/*
** Fc str copy and cat warnx
*/
char	*ft_strcpy_warnx(char *d, char const *s, size_t lim);
char	*ft_strcat_warnx(char *d, char const *s, size_t lim);
/*
** Error is critic
*/
int		ft_iscritical(int errnum);
/*
** Error quit
*/
int		ft_error(char *cmd, char *error_type);
int		ft_error_errn(char *type, int errnum);
int		ft_error2_errn(char *type, char *s, int errnum);
/*
** Warning
*/
int		ft_warnx(char *cmd, char *error_type);
int		ft_warnx_errn(char *type, int errnum);
int		ft_warn2_errn(char *type, char *s, int errnum);
int		ft_warnx_sig(char *type, int st);
/*
** Arg
*/
int		ft_bad_option(char *s, char c);
int		ft_usage(char *name, char *usage);
#endif
