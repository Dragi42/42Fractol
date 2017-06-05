#include <stdlib.h>

char	*ito(long double nb)
{
	int		len;
	long long	n;
	char		*s;

	len = 1;
	n = nb;
	while (n >= 10 && (n /= 10))
		len++;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len--] = 0;
	n = nb;
	while (n >= 10)
	{
		s[len--] = n % 10 + '0';
		n /= 10;
	}
	s[len] = n % 10 + '0';
	return (s);
}
