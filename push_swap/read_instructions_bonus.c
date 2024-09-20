#include "push_swap.h"

void read_push(t_list **stack_a, t_list **stack_b,  char *inst)
{
	if(ft_strncmp(inst, "pa\n",3))
		push_a(stack_b, stack_a);
	else
		push_a(stack_a, stack_b);
}

void read_swap(t_list **stack_a, t_list **stack_b, char *inst)
{
	ft_printf("DEBUG 1.1 DENTRO DE READ_SWAP\n");
	if(ft_strncmp(inst,"sa",3))
		swap(stack_a);
	else if (ft_strncmp(inst,"sb",3))
		swap(stack_b);
	else
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void read_instructions(t_list **stack_a, t_list **stack_b, char *inst)
{
	if(!ft_strncmp(inst,"pa\n",3) || !ft_strncmp(inst,"pb\n",3))
		read_push(stack_a, stack_b, inst);
	else if(!ft_strncmp(inst,"sa\n",3) || !ft_strncmp(inst,"sb\n",3))
		read_swap(stack_a, stack_b, inst);
	else if(!ft_strncmp(inst,"ss\n",3))
		read_swap(stack_a,stack_b,inst);
}
