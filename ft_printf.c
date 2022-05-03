/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/03 20:38:11 by ivda-cru         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	str = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


int ft_putstr(const char *s)
{
    write (1, s, ft_strlen(s));
    return (ft_strlen(s));
}

  /*   - Store the remainder when the number is divided by 16 in a temporary variable temp. If temp is less than 10, insert (48 + temp) in a character array otherwise if temp is greater than or equals to 10, insert (55 + temp) in the character array.
      Divide the number by 16 now
    - Repeat the above two steps until the number is not equal to 0.
    - Print the array in reverse order now. */

void hex_converter(unsigned long long int n)
{
    // ele recebe um n de 87523
    int i = 0;
    int temp;
    //int n;
    char arr[100];
    //arr = ft_strdup(s);

    while (n != 0)
    {
        temp = 0;
        temp = n % 16;        
        // temp vai ficar com resto 3.
        if (temp < 10)
        {
            arr[i] = temp + 48;
            i++;    
        }
        else
        {
            arr[i] = temp + 87;
            i++;    
        }
        n = n / 16;              
    }
    while (i >= 0)
    {
        ft_putchar(arr[i]);
        i--;
    }    

    
}

int get_specifier(va_list arg, const char *string, int i)
{
    if (string[i + 1] == 'c')
        return (ft_putchar(va_arg(arg, int)));           
    else if (string[i + 1] == 'd')
        return (ft_putchar(va_arg(arg, int)));    
    else if (string[i + 1] == 's')
        return (ft_putstr(va_arg(arg, char *)));
    else if (string[i + 1] == '%')
        return (ft_putchar(string[i + 1]));
     else if (string[i + 1] == 'p')
        hex_converter(va_arg(arg, unsigned long long int));
    
    
        
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
    char c = '%';
    char *str = "16";
    int f = 87523;

    
    hex_converter(f);
   
    
    printf("\nAqui mostro a letra %p\n", f); 

    int i=100;
    printf("%d\n",i);
    int *pointer = &i;
    printf("%p\n",i);
    printf("%p\n",pointer);

    ft_printf("\n%p",pointer);

    
    /* printf("\n Uma string: %s", str);
    printf("\na string str em ponteiro e %p", str);
    printf("\na string str em ponteiro e %d", c);
    printf("\na string str em ponteiro e %i", c);
    //printf("\nNumero de caracters na funcao printf e %d ", ft_printf());  

    int x = 0;

    x = 38 % 16;

    printf("\n----remainder of X ----- %d", x);

    float y;

    y = ((float)2545 / (float)16);
    
    printf("\nfloat is %f", y);

    printf("\nhex da string %p", *str);

    int z = 97114;

    printf("\nhex de 97114 %p", z); */
    
    return (0);
    
}
