#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	rt;

	if (ft_args_check(argc, argv))
	{
		ft_minirt_create_window(&rt, argv[1]);
		ft_minirt_message_loop(&rt);
	}
	else
		return (EXIT_FAILURE);
}