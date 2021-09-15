/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:57:44 by jofernan          #+#    #+#             */
/*   Updated: 2021/09/15 14:57:48 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "minitalk.h"

void	text_sig(int pid, char *message, size_t len)
{
	size_t	i;
	int		bit;

	i = 0;
	while (i < len)
	{
		bit = 0;
		while (bit < 7)
		{
			if ((message[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit++;
			usleep(1000);
		}
		i++;
	}
}

void	error_message(void)
{
	ft_putstr_fd("\033[0;31m       ---ERROR--- \033[0m\n", 1);
	ft_putstr_fd("\033[0;33m Try sending the message this way:\n", 1);
	ft_putstr_fd("./client [pid] LOREM IPSUM\033[0m\n", 1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3 || argc > 3)
	{
		error_message();
		return (1);
	}
	pid = ft_atoi(argv[1]);
	text_sig(pid, argv[2], ft_strlen(argv[2]));
	text_sig(pid, "\n", 1);
	return (0);
}
