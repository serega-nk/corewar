#include "libft.h"

void	ft_signed(void *data, size_t size, size_t max_size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)data;
	if (max_size > size && size > 0 && ptr[size - 1] & 0x80)
	{
		ft_memset(ptr + size, -1, max_size - size);
	}
}
