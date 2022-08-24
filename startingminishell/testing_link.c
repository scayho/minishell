#include <stdio.h>
#include <stdlib.h>

struct t_node {
    char    str;
    int i;
    struct t_node    *next;
}   t_node;


struct t_node *new_node(char str, int i)
{
    struct t_node *node;
    node = (struct t_node *)malloc(sizeof(struct t_node));
    if (!node)
        return (NULL);
    node->str = str;
    node->i = i;
    node->next = NULL;
    return (node);
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

int main(void)
{
    struct t_node *head = NULL;
    int i = 0;
    int ascii = 65;

    while (i <= 26)
    {
        add_back(&head, new_node(ascii, ascii));
        ascii++;
        i++;
    }
    struct t_node *temp = head;
    while (temp->next != NULL)
    {
        printf("node : %c ascii %d\n", temp->str, temp->i);
        temp = temp->next;
    }
}