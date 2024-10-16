#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	char c = 'h';
	char *s = "Hello";
	int i = 0;
	int ft;
	int og;

	printf("--TESTING FT_PRINTF--\n\n");
	ft = ft_printf("blank test\n");
	og = printf("blank test\n");
	printf("return diff: %i\n\n", ft - og);

	printf("TESTING %%d and %%i\n\n");
	ft = ft_printf("%d\n", i);
	og = printf("%d\n", i);
	printf("return diff: %i\n\n", ft - og);

	ft = ft_printf("%i\n", INT_MIN);
	og = printf("%i\n", INT_MIN);
	printf("return diff: %i\n\n", ft - og);

	printf("TESTING %%c and %%s\n\n");
	ft = ft_printf("%s\n", s);
	og = printf("%s\n", s);
	printf("return diff: %i\n\n", ft - og);

	ft = ft_printf("%c\n", c);
	og = printf("%c\n", c);
	printf("return diff: %i\n\n", ft - og);

	printf("TESTING %%x , %%X and %%u\n\n");
	ft = ft_printf("%x\n", 56789);
	og = printf("%x\n", 56789);
	printf("return diff: %i\n\n", ft - og);

	ft = ft_printf("%X\n", 98765);
	og = printf("%X\n", 98765);
	printf("return diff: %i\n\n", ft - og);

	ft = ft_printf("%u\n", -123);
	og = ft_printf("%u\n", -123);
	printf("return diff: %i\n\n", ft - og);

	printf("TESTING %%p\n\n");
	ft = ft_printf("%p\n", &i);
	og = printf("%p\n", &i);
	printf("return diff: %i\n\n", ft - og);

	printf("TESTING MULTIPLES ARGS\n\n");
	ft = ft_printf("%s%d%c%x\n", s, INT_MAX, c, 64206);
	og = printf("%s%d%c%x\n", s, INT_MAX, c, 64206);
	printf("return diff: %i\n\n", ft - og);

	ft = ft_printf("%s %d %c %x\n", s, INT_MAX, c, 64206);
	og = printf("%s %d %c %x\n", s, INT_MAX, c, 64206);
	printf("return diff: %i", ft - og);

}