#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "minitalk.h"

static struct t_data	g_info;

static void print_message(int bit)
{
	g_info.bit += ((bit & 1) << g_info.len);
	g_info.len++;
	if (g_info.len == 7)
	{
			ft_putchar_fd(g_info.bit, 1);
			if (!g_info.bit)
				ft_putstr_fd("\n", 1);
			g_info.bit = 0;
			g_info.len = 0;
	}
}	

int main()
{
	pid_t pid;

	pid = getpid();
	ft_putstr_fd("THIS IS THE PID---> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	g_info.len = 0;
	g_info.bit = 0;
	while(1)
	{
		signal(SIGUSR1, print_message);
		signal(SIGUSR2, print_message);
		pause();
	}
	return(0);
}
