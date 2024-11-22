/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:46:31 by drahwanj          #+#    #+#             */
/*   Updated: 2024/11/22 19:32:46 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signo, siginfo_t *info, void *unused_info)
{
	static char		c = 0;
	static int		bit = 0;
	static pid_t	client_pid = 0;
	
	if (info->si_pid)
		client_pid = info->si_pid;
	if (SIGUSR1 == signo)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signo)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if ('\0' == c)
		{
			//I will send a message to client.
			_kill(client_pid, SIGUSR2);
			c = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	_kill(client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	
	pid = getpid();
	if (argc != 1)
	{
		write(1, "Use: ./server\n", 14);
		return (EXIT_FAILURE);
	}
	//my function from utilites.c
	printf("Server PID: %d\n", pid);
	
	_signal(SIGUSR1, handler, 1);
	_signal(SIGUSR2, handler, 1);
	while (42)
		pause();
	return (EXIT_SUCCESS);
}
