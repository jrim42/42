#include "minirt.h"

static void	ft_canvas(t_canvas *canvas, int width, int height)
{
	canvas->width = width;
	canvas->height = height;
	canvas->aspect_ratio = ((double)width / (double)height);
}

t_vt	dir_setup(t_vt dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (vec3(0, dir.y, 1e-6));
	else
		return (vec3(0, 1, 0));
}

double	ft_fov2rad(int fov)
{
	return (fov * (M_PI / FOV_LIMIT));
}

static bool	ft_check_camera_information(t_camera *cam, char *const *tbl)
{
	static const double	nor_limit[2] = {-1.0, 1.0};
	static const int	fov_limit[2] = {0, FOV_LIMIT};
	double				orig[3];
	double				normal[3];
	int					fov;

	if (cam->initialized)
		return (ft_camera_error("camera duplicate creation error."));
	if (!ft_check_strtod_iter(*++tbl, NULL, orig, 3))
		return (ft_camera_error("camera format error (point)."));
	if (!ft_check_strtod_iter(*++tbl, nor_limit, normal, 3))
		return (ft_camera_error("camera format error (normal)."));
	if (!ft_check_strtoi_iter(*++tbl, fov_limit, &fov, 1))
		return (ft_camera_error("camera format error (fov)."));
	if (NULL != *++tbl)
		return (ft_camera_error("camera format error (more info)"));
	cam->orig = point3(orig[0], orig[1], orig[2]);
	cam->dir = vec3(normal[0], normal[1], normal[2]);
	cam->fov = fov;
	cam->initialized = true;
	return (true);
}

bool	ft_camera_setup(t_camera *cam, t_canvas *cav, char *const *tbl)
{
	// t_vt		p;
	// t_vt		q;
	// t_vt		r;

	if (!ft_check_camera_information(cam, tbl))
		return (ft_camera_error(NULL));
	// printf("%lf %lf %lf\n", cam->orig.y, cam->orig.y, cam->orig.z);
	// printf("%lf %lf %lf\n", cam->dir.y, cam->dir.y, cam->dir.z);
	// printf("%d\n", cam->fov);
	ft_canvas(cav, 1024, 768);
	cam->focal_length = tan((cam->fov * PI * 180.0) / 2.0);
	// cam->focal_length = 1.0;
	cam->viewport_height = cam->focal_length * 2;
	cam->viewport_width = cam->viewport_height * cav->aspect_ratio;
	cam->dir = vunit(cam->dir);
	// p = vunit(vmult(cam->dir, -1));
	// q = vunit(vcross(dir_setup(cam->dir), p));
	// r = vcross(p, q);
	// cam->horizontal = vmult(q, cam->viewport_width);
	// cam->vertical = vmult(r, cam->viewport_height);
	// cam->l_bottom = vminus(vminus(vminus(cam->orig, \
	// 		vdivide(cam->horizontal, 2)), vdivide(cam->vertical, 2)), p);
	cam->horizontal = vec3(cam->viewport_width, 0, 0);
	cam->vertical = vec3(0, cam->viewport_height, 0);
    cam->l_bottom = vminus(vminus(vminus(cam->orig, vdivide(cam->horizontal, 2)),
                    vdivide(cam->vertical, 2)), vec3(0, 0, cam->focal_length));
	return (true);
}
