# include "ft_printf.h"
# include	<stdlib.h>
# include <stdio.h>

int main()
 {   
       
    int i = 13432250;
    int *pointer = &i;
    int j = -5;
    int p = -1000;
    int l = 2000;

    printf("%p\n", -1);
    printf("(endereco origem)%d\n", &i);
    printf("O pointer da printf original e %p\n\n", pointer);

    ft_printf("%p", -1);
    ft_printf("\no Pointer da funcao bla bla e %p\n", pointer);

    printf("\n%ld\n", sizeof(void *));
    printf("\n%ld\n", sizeof(int));

    
    printf("\no %%u de -5 e %u\n", j);
    printf("\no %%u de -1000 e %u\n", p);
    printf("\no %%u de 2000 e %u\n", l);

    ft_printf("\n\n Esta e para ver como esta a minha funcao com o u usando o -1000 ----> %u <----\n", p);
    ft_printf("\no %%u de -5 e %u\n", j);
    ft_printf("\no %%u de -1000 e %u\n", p);
    ft_printf("\no %%u de 2000 e %u\n", l);

    ft_printf("\ntestar o X e x\n");
    printf("\nprintf x de -1000 e 2000 %x %x\n", p, l);
    ft_printf("ft_printf x de -1000 e 2000 %x %x\n", p, l);

    printf("\nprintf X de -1000 e 2000 %X %X\n", p, l);
    ft_printf("ft_printf X de -1000 e 2000 %X %X\n", p, l);

    printf("\n o que acontece quando o printf acaba em %%");
    ft_printf("\n ver o que acontece quando a condicao acaba em %u\n", p);

    printf("\nretorno do printf e %d\n", ft_printf("deve ter este numero de caracteres"));

    
    ft_printf("ft_printf X de -1000 e 2000 %X %X\n", p, l);
    return (0);
    
} 