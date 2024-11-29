/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:56:07 by drahwanj          #+#    #+#             */
/*   Updated: 2024/11/29 13:21:58 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
void	_kill(pid_t pid, int signo);
void	_signal(int signo, void *handler, int use_info);

#endif
