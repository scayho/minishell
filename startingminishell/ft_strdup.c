/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:35:30 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/22 01:09:50 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = ft_strlen((char *)s1);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, (void *)s1, i);
	return (str);
}
