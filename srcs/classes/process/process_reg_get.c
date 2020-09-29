#include "classes.h"

long	process_reg_get(t_process *self, int num)
{
	long	value;

	value = 0;
	ft_memcpy(&value, self->reg + (num - 1) * REG_SIZE, REG_SIZE);
	ft_memrev(&value, REG_SIZE);
	ft_signed(&value, REG_SIZE, sizeof(value));
	return (value);
}
