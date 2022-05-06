/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/06 13:31:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



char *unsigned_func(unsigned int n)
{
    char *num;
    int len;

    len = len_n10(n);
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (!num)
        return (NULL);
    num[len] = '\0';
    while (n != 0)
    {
        num[len - 1] = n % 10 + '0';
        n = n / 10;
        len--;
    }
    return (num);    
}

int unsigned_func_2(unsigned int n)
{
    char *num;
    int out_len;

    out_len = 0;
    if (n == 0)
        return (write(1, "0", 1));
    else
    {
        num = unsigned_func(n);
        
        out_len = out_len + ft_putstr(num);
            
        //free(num);
    }
    return (out_len);
}

int get_specifier(va_list arg, const char *string, int i)
{
    if (string[i + 1] == 'c')
        return (ft_putchar(va_arg(arg, int)));           
    else if ((string[i + 1] == 'd') || (string[i + 1] == 'i'))
        return (ft_putchar(va_arg(arg, int)));    
    else if (string[i + 1] == 's')
        return (ft_putstr(va_arg(arg, char *)));    
    else if (string[i + 1] == 'p')
       return (hex_converter(va_arg(arg, unsigned long long)));
    else if (string[i + 1] == 'u')
        return (unsigned_func_2(va_arg(arg, unsigned int)));
    else if (string[i + 1] == 'x')
        return (hex_Upper_lower(va_arg(arg, unsigned long long), string, i));
    else if (string[i + 1] == 'X')
        return (hex_Upper_lower(va_arg(arg, unsigned long long), string, i));
    else if (string[i + 1] == '%')
        return (ft_putchar(string[i + 1]));        
    return(0);
}

int    ft_printf(const char *string, ...)
{
    va_list arg;
    int i;
    int ret;

    i = 0;
    ret = 0;

   va_start(arg, string);
   while (string[i])
   {
       if (string[i] == '%')
       {
           ret = ret + get_specifier(arg, string, i);
            i++;                  
            // nao esquecer de criar a condicao para caso a string acabe em %
       }
       else       
           write(1, &string[i], 1);       
        i++;
   }
   va_end(arg);
   return (ret);
}

int main()
{   
       
    int i = 13432250;
    int *pointer = &i;

    printf("%p\n", (void *)&i);
    printf("O pointer da printf original e %p\n\n", (void *)pointer);

    ft_printf("%p", &i);
    ft_printf("\no Pointer da funcao bla bla e %p\n", (void *)pointer);

    printf("\n%ld\n", sizeof(void *));
    printf("\n%ld\n", sizeof(int));

    int j = -5;
    int p = -1000;
    int l = 2000;
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
    
    return (0);
    
}
