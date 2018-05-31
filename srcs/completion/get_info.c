/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:04:18 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:14:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static inline int	ft_has_acl(t_c_tab *list)
{
	char		res;
	struct stat buf;
	acl_t		acl;

	res = 0;
	if ((lstat(list->content, &buf) != 0))
		stat(list->content, &buf);
	acl = acl_get_link_np(list->content, ACL_TYPE_EXTENDED);
	if (acl != NULL)
	{
		if (buf.st_mode & S_ISVTX)
			list->perm[9] = 't';
		else if (buf.st_mode & S_IXOTH)
			list->perm[9] = 'x';
		list->perm[10] = '+';
		res = 1;
	}
	acl_free(acl);
	return (res);
}

static inline void	get_acl(t_c_tab *list)
{
	struct stat buf;

	if (!(stat(list->content, &buf)))
		if (!(lstat(list->content, &buf)))
			return ;
	if (listxattr(list->content, NULL, 0, XATTR_NOFOLLOW) > 0)
	{
		if (buf.st_mode & S_ISVTX)
			list->perm[9] = 't';
		else if (buf.st_mode & S_IXOTH)
			list->perm[9] = 'x';
		list->perm[10] = '@';
		return ;
	}
	if (ft_has_acl(list))
		return ;
	if (buf.st_mode & S_ISVTX)
		list->perm[9] = 't';
	else if (buf.st_mode & S_IXOTH)
		list->perm[9] = 'x';
}

static inline void	get_type(t_stat *buf, char *s)
{
	if (S_ISLNK(buf->st_mode))
		s[0] = 'l';
	else if (S_ISDIR(buf->st_mode))
		s[0] = 'd';
	else if (S_ISCHR(buf->st_mode))
		s[0] = 'c';
	else if (S_ISBLK(buf->st_mode))
		s[0] = 'b';
	else if (S_ISSOCK(buf->st_mode))
		s[0] = 's';
	else if (S_ISFIFO(buf->st_mode))
		s[0] = 'p';
}

static inline void	get_mode(t_stat *buf, char *s)
{
	if (buf->st_mode & S_IRUSR)
		s[1] = 'r';
	if (buf->st_mode & S_IWUSR)
		s[2] = 'w';
	if (buf->st_mode & S_IXUSR)
		s[3] = 'x';
	if (buf->st_mode & S_IRGRP)
		s[4] = 'r';
	if (buf->st_mode & S_IWGRP)
		s[5] = 'w';
	if (buf->st_mode & S_IXGRP)
		s[6] = 'x';
	if (buf->st_mode & S_IROTH)
		s[7] = 'r';
	if (buf->st_mode & S_IWOTH)
		s[8] = 'w';
	if (buf->st_mode & S_IXOTH)
		s[9] = 'x';
}

void				get_info(t_c_tab *list)
{
	struct stat		buf;

	if (list != NULL)
	{
		list->perm = ft_strnew(13);
		if (list->perm != NULL)
		{
			ft_memset(list->perm, '-', 11);
			stat(list->content, &buf);
			((!readlink(list->content, NULL, 0)) && lstat(list->content, &buf));
			get_type(&buf, list->perm);
			get_mode(&buf, list->perm);
			list->perm[12] = '\0';
			get_acl(list);
		}
	}
}
