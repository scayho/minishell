/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:31:59 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/13 18:57:16 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	checking_input(char *str)
{
	if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
		exit(0);
	if (ft_strncmp(str, ">", 1) == 0)
		write_infile
}

int	main(int ac, char **argv, char **envp)
{
	char		*go;
	int			fdhes;

	(void) ac;
	(void) argv;
	(void) envp;
	fdhes = open("minishell_hestory", O_RDWR);
	while (1)
	{
		go = readline("./abelahce/minishell ");
		ft_putstr_fd(go, fdhes);
		ft_putchar_fd('\n', fdhes);
		printf("you have just tapped : %s \n", go);
	}
	return (1);
}
