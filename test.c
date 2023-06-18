#include <stdio.h>
int  sumar(int i)
{
        static int a = 0;
        a++;
        return (a);
}                         
int	main(void)
{
	int i;

	printf ("%i \n", sumar(i));
	printf ("%i \n", sumar(i));
	printf ("%i \n", sumar(i));
	printf ("%i \n", sumar(i));
	printf ("%i \n", sumar(i));
	return (0);
}
