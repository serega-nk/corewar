
#include "classes.h"

void	process_execute_zjmp(t_process *self)
{
	process_move(self, self->args[0]->number % IDX_MOD);
}
