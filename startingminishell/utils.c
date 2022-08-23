/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:52:21 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/15 01:44:31 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int			i;
	long long	nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		i += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		i += (nb / 10);
		i += (nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (i < ft_strlen(str))
	{
		ft_putchar(str[i]);
		i++;
	}
	return (0);
}
