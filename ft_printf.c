/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/06 11:59:22 by marvin           ###   ########.fr       */
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

int len_n16(unsigned long long n)
{
    int len;

    len = 0;
    while (n != 0)
    {
        len++;
        n = n / 16;
    }
    return (len);
}

int len_n10(unsigned int n)
{
    int len;

    len = 0;
    while (n != 0)
    {
        len++;
        n = n / 10;
    }
    return (len);
}

int ft_putchar_rev(int *arr, int len)
{
    int i;

    i = len;
    while (i >= 0)
    {
        ft_putchar(arr[i]);
        i--;
    } 
    return (1);
}

int hex_converter(unsigned long long n)
{
    int temp;
    int i;
    int len;
   
    len = len_n16(n);
    i = 0;

    int arr[len];

    if (n == 0)
    return (write(1, "0", 1)); 
    write(1, "0x", 2);
    while (n != 0)
    {
        temp = 0;
        temp = n % 16;        
        if (temp < 10)        
            arr[i++] = (temp + '0');     
        else       
            arr[i++] = (temp - 10 + 'a');      
        n = n / 16;              
    }    
    ft_putchar_rev(arr, len);    
}

int hex_Upper_lower(unsigned long long n, const char *s, int j)
{
    int temp;
    int i;
    int len;
   
    len = len_n16(n);
    i = 0;

    int arr[len];

    if (n == 0)
    return (write(1, "0", 1)); 
    while (n != 0)
    {
        temp = 0;
        temp = n % 16;        
        if (temp < 10)        
            arr[i++] = (temp + '0');     
        else if (s[j + 1] == 'X')       
            arr[i++] = (temp - 10 + 'A');
        else if (s[j + 1] == 'x')  
            arr[i++] = (temp - 10 + 'a');    
        n = n / 16;              
    }    
    ft_putchar_rev(arr, len);    
}



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
