
#include "classes.h"

void	process_execute_zjmp(t_process *self)
{
	if (self->carry)
	{
		self->step = self->args[0]->number % IDX_MOD;
	}	
}
