/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:22:22 by fursini           #+#    #+#             */
/*   Updated: 2023/03/17 15:16:45 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	ft_client_handler(int signum)
{
	(void)signum;
	ft_printf("Message correctly sent and received by the server.\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;
	pid_t				pid;
	int					c;

	c = -1;
	if (argc != 3)
	{
		ft_printf("ERROR\n./client <server_pid> <text>\n");
		exit (0);
	}
	pid = ft_atoi(argv[1]);
	signal.sa_handler = ft_client_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	while (argv[2][++c])
		ft_send_message(pid, argv[2][c]);
	ft_send_message(pid, 0);
}
