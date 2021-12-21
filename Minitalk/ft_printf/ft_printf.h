/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:50:45 by oabdelha          #+#    #+#             */
/*   Updated: 2021/11/28 12:06:43 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_hexdecimal(unsigned int nbr);
int	ft_hedecimal(unsigned int nbr);
int	ft_unsigned(int nbr);
int	ft_pointer(void *ptr);
int	ft_pointerhedexcimal(unsigned long nbr);
#endif