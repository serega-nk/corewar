
#include "classes.h"

void	process_execute_aff(t_process *self)
{
	ft_printf("Aff: %c\n", process_reg_get(self, self->args[0]->number));
}
