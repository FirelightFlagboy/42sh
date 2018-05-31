/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:40:43 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/02 14:15:08 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"

int			ft_iscritical(int errnum)
{
	if (errnum == ERR_MALLOC || errnum == ERR_FORK)
		return (1);
	return (0);
}

char		*ft_strsignal(int sig)
{
	char *const ts[] = {
		"Unknown signal: 0", "Hangup: 1", "Interrupt: 2", "Quit: 3",\
		"Illegal instruction: 4", "Trace/BPT trap: 5", "Abort trap: 6",\
		"EMT trap: 7", "Floating point exception: 8", "Killed: 9",\
		"Bus error: 10", "Segmentation fault: 11", "Bad system call: 12",\
		"Broken pipe: 13", "Alarm clock: 14", "Terminated: 15",\
		"Urgent I/O condition: 16", "Suspended (signal): 17", "Suspended: 18",\
		"Continued: 19", "Child exited: 20", "Stopped (tty input): 21",\
		"Stopped (tty output): 22", "I/O possible: 23",\
		"Cputime limit exceeded: 24", "Filesize limit exceeded: 25",\
		"Virtual timer expired: 26", "Profiling timer expired: 27",\
		"Window size changes: 28", "Information request: 29",\
		"User defined signal 1: 30", "User defined signal 2: 31", NULL
	};
	static char s[64];

	if (sig >= 0 && sig < 32)
		return (ts[sig]);
	ft_snprintf(s, 64, "Unknown signal: %d\n", sig);
	return (s);
}
