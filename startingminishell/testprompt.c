#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pthread.h>
int k = 0;
void    *coint(void *ptr)
{
    int *i = ptr;
    while (i[0] < 1000)
        k++;
    return (NULL);
}

int main(void)
{
    pthread_t th, thh;
    int i = 0;
    // char    *message;

    pthread_create(&th, NULL, &coint, &i);
    pthread_create(&thh, NULL, &coint, &i);
    pthread_join(th, NULL);
    pthread_join(thh, NULL);
    printf("%d\n", k);
    // readline("enter your message please :");    
    // printf("hello newbee . you're welcome to use our services !\n");        
    // while (1)
    // {
    //     // scanf("%s", message);
    //     printf("your which is : %s \n", readline ("enter your message please :"));       
    //     printf("you pleased message will be send to the moon !\n");
    // }
    return (0);
}