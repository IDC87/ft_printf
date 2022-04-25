/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/04/25 20:27:24 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

/* c = va_arg(args, int)
s = va_arg(args, char *)
d = va_arg(args, int)
i = va_arg(args, int)
u = va_arg(args, unsigned int)
p = va_arg(args, unsigned long)# or 
                               #(unsigned long)va_arg(args, void *);
x = va_arg(args, unsigned int)
X = va_arg(args, unsigned int)


    %d (print as a decimal integer)
    %6d (print as a decimal integer with a width of at least 6 wide)
    %f (print as a floating point)
    %4f (print as a floating point with a width of at least 4 wide)
    %.4f (print as a floating point with a precision of four characters after the decimal point)
    %3.2f (print as a floating point at least 3 wide and a precision of 2)



%[flags][width][.precision]type 
*/

//int serie_if(const char *string, int i, arg_list(arg))


/* ft_x
if (string[i - 1] == 'c')
            {
                char c = va_arg(arg, int);
                write (1, &c, 1);
            }
ft_count
funcao()
    int x;
    ft_x();
    ft_count()
    return (x);
100/10;
100/16
string[i]
    i++;
writes;
countar;
x += numero
return (x); */

int ft_putchar(char c)
{
    write(1, &c, 1);
    return(1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void get_specifier(va_list arg, char *string, int i, int ret)
{
    if (string[i] == 'c')
            {
                char c = va_arg(arg, int);
                i++;
                ft_putchar(c);                
            }
            if (string[i] == 'd')
            {
                int d = va_arg(arg, int);
                i++;
                ft_putchar(d);
            }        
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
            i++;
            get_specifier(arg, string, i, ret);            
       }
       else
       {
           write(1, string, ft_strlen(string));
           return(ft_strlen(string));
       }
       
       
        //write(1, &string[i], 1);
        i++;
   }
   va_end(arg);
   return (ret);
}

int main()
{   
    char c = 'i';
    ft_printf("Aqui mostro a letra ", c); 
    //printf("\nOla eu sou o %c %d", c, 1);  
    return (0);
}
