#include "minirt.h"

static bool	ft_graphic_element_setup(t_graphic *g, char *const *tbl)
{
	if (NULL == *tbl || '#' == **tbl)
		return (true);
	else if (ft_is_scene_type(tbl[0]))
		return (ft_scene_setup(&(g->scene), tbl));
	else if (ft_is_object_type(tbl[0]))
		return (ft_objects_setup(&(g->objs), tbl));
	else
		return (ft_graphic_error(g, "Undefined element type."));
	return (true);
}

static bool	ft_graphic_data_validate(t_graphic *g)
{
	if (!ft_check_scene_initialized(&(g->scene)) || \
			!ft_check_objects_initialized(&(g->objs)))
		return (false);
	return (true);
}

static bool	ft_graphic_data_save(t_graphic *g, int fd)
{
	int		ret;
	char	*line;
	char	**tbl;

	while (1)
	{
		ret = ft_gnl_without_newline(fd, &line);
		if (ret <= 0)
			break ;
		tbl = ft_split(line, '\t');
		free(line);
		if (!tbl)
			return (ft_graphic_error(g, "Can't allocate memory."));
		ret = ft_graphic_element_setup(g, tbl);
		ft_tblclear(&tbl);
		if (!ret)
			return (ft_graphic_error(g, NULL));
	}
	if (ret < 0)
		return (ft_graphic_error(g, "Can't read scene file."));
	if (!ft_graphic_data_validate(g))
		return (ft_graphic_error(g, \
					"There are not enough elements in the scene file."));
	return (true);
}

bool	ft_graphic_setup(t_graphic *g, const char *scenefile)
{
	int		fd;
	bool	ret;

	fd = open(scenefile, O_RDONLY);
	if (fd < 0)
		return (ft_graphic_error(g, "Can't open scene file."));
	ret = ft_graphic_data_save(g, fd);
	if (close(fd) < 0)
		return (ft_graphic_error(g, "Can't close scene file."));
	return (ret);
}
