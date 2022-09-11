/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:31:59 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/24 17:25:04 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_ignore_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	return (str + i);
}

void	check_fals_name(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 33 || str[i] == 34 || str[i] == 38 || str[i] == 39 \
		|| str[i] == 40 || str[i] == 41 || str[i] == 47 || str[i] == 60 \
		|| str[i] == 124 || str[i] == 59 || str[i] == 92)
		{
			ft_putstr("syntax error\n");
		}
		i++;
	}
}

void	ft_reoutput(char	*str)
{
	str = ft_ignore_space(str);
	check_fals_name(str);
}

int	check_qotes(char *str)
{
	int	i;
	int	one;
	int	two;

	i = -1;
	one = 0;
	two = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 39)
			one++;
		if (str[i] == 34)
			two++;
	}
	if (one % 2 != 0)
	{
		ft_putstr("your command misses one qoute \'\n");
		return (1);
	}
	if (two % 2 != 0)
	{
		ft_putstr("your command misses one double qoute \"\n");
		return (1);
	}
	return (0);
}

int	parsing(char *str)
{
	if (check_qotes(str))
		return (1);
	return (0);
}

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\r' || str[i] == '\f' || str[i] == '\v' \
		|| str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **argv, char **envp)
{
	t_info			*knew;

	(void) ac;
	(void) argv;
	knew = malloc(sizeof(t_info));
	if (!knew)
		return (FAILDE);
	knew->anv = envp;
	while (1)
	{
		knew->command = readline("./abelahce/minishell: ");
		knew->command = ft_ignore_space(knew->command);
		knew->lengh = ft_strlen(knew->command);
		if (check_spaces(knew->command))
			continue ;
		if (knew->lengh >= 1)
			add_history(knew->command);
		if (parsing(knew->command))
			continue ;
		knew->splited_command = malloc (sizeof(char **) * pipes(knew->command));
		if (!knew->splited_command)
			continue ;
		checking_input(knew);
		split_pipes(knew);
	}
	return (SUCCES);
}

// ls -la dir | < in grep -B 10 pop | wc -l "psodsd | dsf ds"
// ls -la dir "| < in grep -B 10 pop "| wc -l "psodsd | dsf ds"