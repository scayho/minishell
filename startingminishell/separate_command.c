/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:57:28 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/24 17:39:41 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipes(char *str)
{
	int	i;
	int	pi;

	i = 0;
	pi = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 124)
			pi++;
		i++;
	}
	return (pi);
}

int find_ascii(char *command, int index, int ascii)
{
	int	i;

	i = index;
	while (command[i] != '\0' && command[i] != ascii)
		i++;
	if (command[i] == '\0')
		return (FAILDE);
	return (i);
}

char *separate_command(t_info *knew)
{
	static int	i;
	char		*lock;
	int			j;

	j = i;
	while (knew->command[i] != '\0')
	{
		if (knew->command[i] == DQUOTE)
			i = find_ascii(knew->command, ++i, DQUOTE);
		else if (knew->command[i] == SQUOTE)
			i = find_ascii(knew->command, ++i, SQUOTE);
		if (i < 0)
			exit(1);
		if (knew->command[i] == PIPE)
		{
			lock = ft_substr(knew->command, j, i - j);
			i++;
			return (lock);
		}
		i++;
	}
	lock = ft_substr(knew->command, j, i - j);
	i = 0; // kanradoh l ziro 7it ila maredinach l 0 l command 1 radi takhdem mais li moraha maradich ikhadmo
	knew->len = 0; // 7it 7atino condition f splite_pipes fach  nwaslo lakher dyal l command aykhess loop ta7bes , hadchi lach redinah l 0
	return (lock);
}

int	split_pipes(t_info *knew)
{
	// struct t_node *head;
	int	i;

	i = 0;
	// head = NULL;
	knew->len = 1;
	while (knew->len)
		knew->splited_command[i++] = separate_command(knew);
	knew->splited_command[i] = NULL;
	i = -1;
	while (knew->splited_command[++i])
		printf("%s\n", knew->splited_command[i]);
	indentify_var(knew);
	return (SUCCES);
}