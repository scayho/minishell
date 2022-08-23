/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:11:38 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/18 03:47:14 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*resul;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		resul = malloc(1);
		resul[0] = '\0';
		return (resul);
	}
	if (len > (ft_strlen(s) - start))
		resul = malloc(ft_strlen(s) - start + 1);
	else
		resul = malloc(len * sizeof(char) + 1);
	if (!resul)
		return (NULL);
	while (len > i && s[start] != '\0')
	{
		resul[i++] = s[start++];
	}
	resul[i] = '\0';
	return (resul);
}
