/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:38:26 by drahwanj          #+#    #+#             */
/*   Updated: 2024/11/22 19:35:55 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		write(1, "Sending Signal Failed\n", 22);
		exit(EXIT_FAILURE);
	}
}

void	_signal(int signo, void *handler, int use_info)
{
	struct sigaction	sa = {0};

	if (use_info == 1)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else if (use_info == 0)
	{
		sa.sa_handler = handler;
	}
	//sigemptyset(&sa.sa_mask);
	//sigaddset(&sa.sa_mask, SIGUSR1);
	//sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signo, &sa, NULL) < 0)
	{
		write(1, "Sigaction error\n", 16);
		exit(EXIT_FAILURE);
	}
}
