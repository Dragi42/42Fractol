#include "libft.h"

#include <unistd.h>

int	ft_errret(char *name, char *msg, int ret)
{
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (ret);
}
