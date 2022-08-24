/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indentify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:32:37 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/24 17:45:27 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ignore_sqoute(char  *str, int i)
{
    int index;
    
    index = 0;
    while (str[index] != SQUOTE)
        index++;
    return (i + index);
}

void add_back(struct t_node **head, struct t_node *node)
{
    struct t_node *temp = *head;

    if (temp == NULL)
    {
        *head = node;
        return ;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;

    }
    temp->next = node;
}

int take_variable(char  *str, int   start)
{
    int i;

    i = 0;
    while (str[i] != SPACE && str[i] != '\0' && str[i] != DOLLAR)
        i++;
    return (i + start);
}

void    indentify_var(t_info *knew)
{
    int i;
    int j;

    j = 0;
    while (knew->splited_command[j] != NULL)
    {
        i = 0;
        while (knew->splited_command[j][i] != '\0')
        {
            if (knew->splited_command[j][i] == SQUOTE)
                i = ignore_sqoute(knew->splited_command[j], i);
            if (knew->splited_command[j][i] == DOLLAR)
            {
                i = take_varibale(knew->splited_command[j][i], i);
                
            }
        }
        j++;
    }
}