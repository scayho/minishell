/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:25:26 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/24 19:37:03 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "minishell.h"

# define PIPE 124
# define DQUOTE 34
# define SQUOTE 39
# define DOLLAR 36
# define SPACE 32
# define SUCCES 0
# define FAILDE -1
# define NEWLINE -2

typedef struct t_data {
	char	*command;
	char	**splited_command;
	char	**anv;
	int		lengh;
	int		quto;
	int		dquto;
	int		len;
	struct t_node *head;
	
}	t_info;

struct t_node
{
	char	*variable;
	int		start;
	int		end;
	int		cmd;
	struct t_node *next;
};

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char	*str);
int		ft_putchar(char c);
void	ft_bzero(void *s, size_t n);
int		main(int ac, char **argv, char **envp);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int		check_qotes(char *str);
int		parsing(char *str);
int		pipes(char *str);
int 	find_ascii(char *command, int index, int ascii);
char 	*separate_command(t_info *knew);
void	ft_echo(char *str, int n);
void	ft_env(t_info	*knew);
void    ft_exit(void);
int		checking_input(t_info	*knew);
char	*ft_ignore_space(char *str);
void	check_fals_name(char	*str);
void	ft_reoutput(char	*str);
int		split_pipes(t_info *knew);
int		check_spaces(char *str);
void    indentify_var(t_info *knew);



#endif

// ls -la dir | < in grep -B 10 pop | wc -l "psodsd | dsf ds"
// spliti l command b '|' 
// moraha kola request atwali bo7dha
// spliti kola request bl espace 
// moraha aywaliw 3andk descompenent li radi tclassihom mabin les variable les orders o les donner
// o tb9a lspliti o tfare9 kola haja bohdha