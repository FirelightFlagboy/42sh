/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_arr_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:54:20 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_arr_len(char **arr)
{
	int i;

	i = 0;
	while (*arr)
	{
		i++;
		arr++;
	}
	return (i);
}
