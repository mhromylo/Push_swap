/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:16:29 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/23 14:06:20 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isspase(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	atoi_long(const char *str)
{
	long	nb;
	int		minus;

	nb = 0;
	minus = 1;
	while (*str && isspase(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (minus * nb);
}
