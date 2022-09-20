#include "minirt.h"

static bool	ft_error(const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	return (false);
}

static bool	ft_check_filename(const char *filename)
{
	size_t	len;

	len = 0U;
	if (filename)
		len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 3, ".rt", 3))
		return (false);
	return (true);
}

bool	ft_args_check(int argc, char *argv[])
{
	const char	*err_count = "The number of arguments is invalid.";
	const char	*err_file = "The file extension is invalid.";

	if (argc != 2)
		return (ft_error(err_count));
	if (!ft_check_filename(argv[1]))
		return (ft_error(err_file));
	return (true);
}
