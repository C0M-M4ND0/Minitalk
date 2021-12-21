/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:04:33 by oabdelha          #+#    #+#             */
/*   Updated: 2021/12/21 09:49:20 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sending(int pid, char charofmes, int num)
{
	while (num >= 0)
	{
		if ((charofmes >> num) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		num--;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((str[i] - '0') >= 0 && (str[i] - '0') <= 9)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void	handler(int sing)
{
	if (sing == SIGUSR1)
		ft_printf("RECEIVED !\n");
}

void	ft_send(int pid)
{
	int	i;

	i = 0;
	ft_printf("SEAND !\n");
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;
	int	e;

	i = 0;
	e = 0;
	(void) ac;
	pid = ft_atoi(av[1]);
	e = kill(pid, 0);
	if (e == -1)
		ft_printf("Bad pid \n");
	signal(SIGUSR1, handler);
	while (av[2][i])
	{
		ft_sending(pid, av[2][i], 7);
		i++;
		usleep(2);
	}
	if (av[2][i] == '\0' && e != -1)
	{
		ft_send(pid);
	}
	return (0);
}
