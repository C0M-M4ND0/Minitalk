/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:57:01 by oabdelha          #+#    #+#             */
/*   Updated: 2021/12/21 09:54:03 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int nb, int power)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (i <= power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

struct	s_value
{
	int	charofmes;
	int	num;
}s_value = {0, 7};

void	ft_handler(int sig, siginfo_t *info, void *nothing)
{
	(void) nothing;
	if (sig == SIGUSR1)
	{
		s_value.charofmes += ft_power(2, s_value.num);
		s_value.num--;
	}
	if (sig == SIGUSR2)
		s_value.num--;
	if (s_value.num == -1)
	{
		if (s_value.charofmes == 0)
			kill(info->si_pid, SIGUSR1);
		else
			ft_printf("%c", s_value.charofmes);
		s_value.num = 7;
		s_value.charofmes = 0;
	}
}

int	main(void)
{	
	struct sigaction	new;

	ft_printf("The PID of this Process is  : %d\n", getpid());
	new.sa_sigaction = ft_handler;
	new.sa_flags = SA_SIGINFO;
	sigemptyset(&new.sa_mask);
	sigaction(SIGUSR1, &new, NULL);
	sigaction(SIGUSR2, &new, NULL);
	while (1)
		pause();
	return (0);
}
