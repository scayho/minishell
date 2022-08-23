/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:31:59 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/23 17:33:00 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *str)
{
	if (ft_strncmp(str, " -n ", ft_strlen(" -n ")) == 0)
	{
		ft_putstr(str + ft_strlen(" -n "));
	}
	else
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
}

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
	int	i;

	i = -1;
	str = ft_ignore_space(str);
	check_fals_name(str);
}

void	ft_env(t_info	*knew)
{
	int	i;

	i = 0;
	while (knew->anv[i] != NULL)
		printf("%s\n", knew->anv[i++]);
}

int	checking_input(t_info	*knew)
{
	knew->command = ft_ignore_space(knew->command);
	if (!ft_strlen(knew->command))
		rl_on_new_line();
	else if (ft_strncmp(knew->command, "exit", ft_strlen("env")) == 0)
		exit(0);
	else if (ft_strncmp(knew->command, "echo", ft_strlen("echo")) == 0)
		ft_echo(knew->command + ft_strlen("echo"));
	else if (ft_strncmp(knew->command, "env", ft_strlen("env")) == 0)
		ft_env(knew);
	return (0);
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

int fct(char *command, int index, int ascii)
{
	int	i;

	i = index;
	while (command[i] != 0 && command[i] != ascii)
		i++;
	if (command[i] == 0)
		return (FAILDE);
	return (i);
}

char *separate_command(t_info *knew)
{
	static int	i;
	char		*lock;
	int			j;

	j = i;
	knew->quto = 0;
	knew->dquto = 0;
	while (knew->command[i] != 0)
	{
		if (knew->command[i] == 34)
			i = fct(knew->command, ++i, 34);
		else if (knew->command[i] == 39)
			i = fct(knew->command, ++i, 39);
		if (i < 0)
			exit(1);
		if (knew->command[i] == 124)
		{
			lock = ft_substr(knew->command, j, i - j);
			i++;
			return (lock);
		}
		i++;
	}
	lock = ft_substr(knew->command, j, i - j);
	i = 0;
	knew->len = 0;
	return (lock);
}

int	hamzaton(t_info *knew)
{
	int	i;

	i = 0;
	knew->len = ft_strlen(knew->command);
	while (knew->len != 0)
	{
		knew->splited_command[i++] = separate_command(knew);
	}
	knew->splited_command[i] = NULL;
	return (SUCCES);
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
	int				check_loop;

	(void) ac;
	(void) argv;
	check_loop = 0;
	knew = malloc(sizeof(t_info));
	if (!knew)
		return (0);
	knew->anv = envp;
	while (1)
	{
		knew->command = readline("./abelahce/minishell ");
		knew->command = ft_ignore_space(knew->command);
		knew->lengh = ft_strlen(knew->command);
		if (check_spaces(knew->command))
			continue ;
		if (knew->lengh >= 1)
			add_history(knew->command);
		if (parsing(knew->command))
			continue ;
		knew->splited_command = malloc (sizeof(char **) * pipes(knew->command));
		checking_input(knew);
		hamzaton(knew);
	}
	return (1);
}

// ls -la dir | < in grep -B 10 pop | wc -l "psodsd | dsf ds"
// ls -la dir "| < in grep -B 10 pop "| wc -l "psodsd | dsf ds"