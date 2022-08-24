/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:59:47 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/24 19:37:20 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *str, int n)
{
	int i = 0;
	if (ft_strncmp(str, " -n ", ft_strlen(" -n ")) == 0)
		i = 1;
	ft_putstr_fd(str, n);
	if(i == 1)
		ft_putchar_fd('\n', n);
}

void	ft_env(t_info	*knew)
{
	int	i;

	i = 0;
	while (knew->anv[i] != NULL)
		printf("%s\n", knew->anv[i++]);
}

void    ft_exit(void)
{
    exit(0);
}

int	checking_input(t_info	*knew)
{
	knew->command = ft_ignore_space(knew->command);
	if (!ft_strlen(knew->command))
		rl_on_new_line();
	else if (ft_strncmp(knew->command, "exit", ft_strlen("env")) == 0)
        ft_exit();
	else if (ft_strncmp(knew->command, "echo", ft_strlen("echo")) == 0)
		ft_echo(knew->command + ft_strlen("echo"), 1);
	// else if (ft_strncmp(knew->command, "env", ft_strlen("env")) == 0)
		// ft_env(knew);
	return (0);
}
