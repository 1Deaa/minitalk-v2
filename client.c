/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:46:41 by drahwanj          #+#    #+#             */
/*   Updated: 2024/11/22 20:15:13 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_status = 0;

static void	eof_handler(int signo)
{
	write(1, "\nMessage Received\n", 18);
	exit(EXIT_SUCCESS);
}

static void	char_handler(int signo)
{
	g_status = 1;
}

static void	char_signal(char c, pid_t server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x80 >> bit))
			_kill(server_pid, SIGUSR1);
		else
			_kill(server_pid, SIGUSR2);
		bit++;
		while (g_status == 0)
			usleep(42);
		g_status = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		write(1, "Invalid Arguments <pid> <message>\n", 34);
		exit(EXIT_FAILURE);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	_signal(SIGUSR1, char_handler, 0);
	_signal(SIGUSR2, eof_handler, 0);
	i = 0;
	while (message[i])
		char_signal(message[i++], server_pid);
	char_signal('\0', server_pid);
	return (EXIT_SUCCESS);
}
