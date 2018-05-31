/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:30:05 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/09 13:04:32 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdio.h>

/*
** Printf display
*/
int			ft_printf(char const *format, ...);
int			ft_eprintf(char const *format, ...);
int			ft_dprintf(int fd, char const *format, ...);
int			ft_fprintf(FILE *stream, char const *format, ...);
/*
** Printf string
*/
int			ft_sprintf(char *s, char *format, ...);
int			ft_snprintf(char *s, size_t n, char *format, ...);
int			ft_asprintf(char **as, char *format, ...);
/*
** vprintf display
*/
int			ft_vfprintf(FILE *stream, char const *format, va_list ap);
int			ft_vdprintf(int fd, char const *format, va_list ap);
/*
** vprintf string
*/
int			ft_vsprintf(char *s, char *format, va_list ap);
int			ft_vsnprintf(char *s, size_t n, char *format, va_list ap);
int			ft_vasprintf(char **as, char *format, va_list ap);
/*
** Enum color
*/
enum	e_color
{
	P_RESET,
	P_C_DEFAULT,
	P_BLACK,
	P_RED,
	P_GREEN,
	P_YELLOW,
	P_BLUE,
	P_MAGENTA,
	P_CYAN,
	P_L_GRAY,
	P_D_GRAY,
	P_L_RED,
	P_L_GREEN,
	P_L_YELLOW,
	P_L_BLUE,
	P_L_MAJENTA,
	P_L_CYAN,
	P_WHITE,
	P_BACK_DEFAULT,
	P_BACK_BLACK,
	P_BACK_RED,
	P_BACK_GREEN,
	P_BACK_YELLOW,
	P_BACK_BLUE,
	P_BACK_MAJENTA,
	P_BACK_CYAN,
	P_BACK_L_GRAY,
	P_BACK_D_GRAY,
	P_BACK_L_RED,
	P_BACK_L_GREEN,
	P_BACK_L_YELLOW,
	P_BACK_L_BLUE,
	P_BACK_L_MAJENTA,
	P_BACK_L_CYAN,
	P_BACK_WHITE,
	P_BOLD,
	P_DIM,
	P_UNDERLINE,
	P_BLINK,
	P_INVERTED,
	P_HIDDEN,
};
#endif
