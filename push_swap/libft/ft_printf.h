/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:01 by mhromylo          #+#    #+#             */
/*   Updated: 2023/12/01 15:45:48 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_count(char c);
int	ft_putstr_counter(char const *str);
int	ft_putp(uintptr_t nb);
int	ft_putnb(int nb);
int	ft_putnbu(unsigned int nb);
int	ft_puthex(unsigned int nb, char str);

#endif
