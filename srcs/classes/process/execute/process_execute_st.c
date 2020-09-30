
#include "classes.h"

void	*process_reg_addr(t_process *self, long number)
{
	return ((void *)(self->reg + (number - 1) * REG_SIZE));
}

void	*process_ind_addr(t_process *self, long number)
{
	return ((void *)(self->pc + (number % IDX_MOD)));
}

void	process_execute_st(t_process *self)
{
	void	*src;
	void	*dst;

	src = process_reg_addr(self, self->args[0]->number);
	if (self->args[1]->arg_type & T_REG)
	{
		dst = process_reg_addr(self, self->args[1]->number);
		ft_memcpy(dst, src, REG_SIZE);
	}
	else if (self->args[1]->arg_type & T_IND)
	{
		dst = process_ind_addr(self, self->args[1]->number);
		vm_write(self->vm, dst, src, IND_SIZE);
	}
}
