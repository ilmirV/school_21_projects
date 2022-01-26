#include "cub3d.h"

void	clear_file(t_list *file)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = file;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free((char *)(tmp2->content));
		free(tmp2);
	}
}
