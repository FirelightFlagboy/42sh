/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:08:49 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/10 03:04:03 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		ft_read(int fd, char *buf, size_t bufsiz)
{
	int	ret;

	if ((ret = read(fd, buf, bufsiz)) > 0)
		*(buf + ret) = '\0';
	return (ret);
}
