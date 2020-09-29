#include "classes.h"

static t_arg_type	get_arg_type(t_arg_type types, size_t index)
{
	return ((types >> (sizeof(types) * 8 - index * 2)) & 0b11);
}

t_bool				process_arg_types(t_process *self)
{
	char	types;
	size_t	index;

	ft_memcpy(self->arg_types, self->op->arg_types, sizeof(self->arg_types));
	if (self->op->use_types)
	{
		types = '\0';
		vm_read(self->vm, self->pc, &types, sizeof(types));
		ft_memrev(&types, sizeof(types));
		process_move(self, 1);
		index = 0;
		while (index < MAX_ARG_TYPES)
		{
			self->arg_types[index] = get_arg_type(types, index + 1);
			index++;
		}
	}
	return (TRUE);
}
