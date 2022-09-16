#include "../include/miniRT.h"

typedef struct s_cyvar
{
	double	a;
	double	b;
	double	c;
	double	t;
	double 	t1;
	double	t2;
	t_vt	v;
	t_vt	w;
	t_vt	h;
	t_pt	p;
	t_vt	top;
	t_vt	bot;
	t_vt	hc;
	double	r2;
} t_cyvar;

void	t_select(double *t1, double *t2, int i);
double	intersect_check(t_cyvar var, double *t1, double *t2, int i);
double	cy_calc(t_cyvar var, t_hit *hit, int i);
void	cy_normal(t_ray ray, t_cyl *cy, t_hit *hit);
int		cy_boundary(t_ray ray, t_cyl cy, t_cyvar var);
int		intersect_cyl(t_ray ray, t_cyl cy, t_hit *hit, int i);
t_vt	get_cy_normal(t_vt pos, t_cyl cy);
int		cy_boundary(t_ray ray, t_cyl cy, t_cyvar var);

int		intersect_cyl(t_ray ray, t_cyl cy, t_hit *hit, int i)
{
	t_cyvar var;

	var.r2 = cy.diam * cy.diam;
	var.top = vt_minus(cy.center, vt_multi(cy.dir,
			cy.height));
	var.bot = vt_plus(cy.center, vt_multi(cy.dir,
			cy.height));
	var.hc = vt_minus(var.top, var.bot);
	var.h = vt_unit(var.hc);
	var.w = vt_minus(ray.orig, var.bot);
	var.v = ray.dir;
	if (!(var.t = cy_calc(var, hit, i)))
		return (0);
	if (!cy_boundary(ray, cy, var))
		return (0);
	hit->t = var.t;
	cy_normal(ray, &cy, hit);
	hit->norm = vt_unit(vt_minus(hit->p, cy.center));
	hit->p = vt_plus(hit->p, vt_multi(hit->norm,
		EPSILON));
	return (1);
}

void	t_select(double *t1, double *t2, int i)
{
	double	tmp;
	
	if (i == 1)
	{
		if (*t1 > *t2) // 원기둥 앞
		{
			tmp = *t1;
			*t1 = *t2;
			*t2 = tmp;
		}
	}
	else
	{	
		if (*t1 < *t2) // 원기둥 뒤
		{
			tmp = *t1;
			*t1 = *t2;
			*t2 = tmp;
		}
	}
}

double	intersect_check(t_cyvar var, double *t1, double *t2, int i)
{
	double	root;
	double	t;

	root = (var.b * var.b) - (4 * var.a * var.c);
	if (root < 0)
		return (0);
	if (root > 0)
	{
		t = (var.b > 0) ? -0.5 * (var.b + sqrt(root)) :
			-0.5 * (var.b - sqrt(root));
		*t1 = t / var.a;
		*t2 = var.c / t;
		t_select(t1, t2, i);
	}
	else if (root == 0)
	{
		if (fabs(vt_dot(var.v, var.h)) != 1)
		{
			*t1 = -var.b / (2 * var.a);
			*t2 = -var.b / (2 * var.a);
		}
	}
	return (1);
}

double	cy_calc(t_cyvar var, t_hit *hit, int i)
{
	double t;

	var.a = ft_dot_mine(var.v) - pow(vt_dot(var.v, var.h), 2);
	var.b = (vt_dot(var.v, var.w) - (vt_dot(var.v, var.h) *
	vt_dot(var.w, var.h))) * 2;
	var.c = ft_dot_mine(var.w) - pow(vt_dot(var.w, var.h), 2) - var.r2;
	if (!(intersect_check(var, &var.t1,&var.t2, i)))
		return (0);
	if ((var.t1 < 0 && var.t2 < 0) ||
	(var.t1 > hit->t && var.t2 > hit->t))
		return (0);
	if (var.t2 < 0)
		return (0);
	if (var.t1 > 0)
		t = var.t1;
	else
		t = var.t2;
	return (t);
}

void	cy_normal(t_ray ray, t_cyl *cy, t_hit *hit)
{
	double dir;

	hit->p = ray_at(&ray, hit->t);
	if (cy->dir.x == 1 || cy->dir.x == -1)
	{
		dir = hit->p.x - cy->center.x;
		cy->center.x = cy->center.x + dir;
	}
	if (cy->dir.y == 1 || cy->dir.y == -1)
	{
		dir = hit->p.y - cy->center.y;
		cy->center.y = cy->center.y + dir;
	}
	if (cy->dir.z == 1 || cy->dir.z == -1)
	{
		dir = hit->p.z - cy->center.z;
		cy->center.z = cy->center.z + dir;
	}
}

int		cy_boundary(t_ray ray, t_cyl cy, t_cyvar var)
{
	var.p = ray_at(&ray, var.t);
	if ((cy.dir.x != 0) &&
		(cy.dir.y == 0 || cy.dir.z == 0))
	{
		if (var.p.x < cy.center.x - cy.height || var.p.x > cy.center.x + cy.height)
			return (0);
	}
	else if ((cy.dir.y != 0) &&
		(cy.dir.y == 0 || cy.dir.z == 0))
	{
		if (var.p.y < cy.center.y - cy.height || var.p.y > cy.center.y + cy.height)
			return (0);
	}
	else if ((cy.dir.z != 0) &&
		(cy.dir.y == 0 || cy.dir.z == 0))
	{
		if (var.p.z < cy.center.z - cy.height || var.p.z > cy.center.z + cy.height)
			return (0);
	}
	return (1);
}

t_vt	get_cy_normal(t_vt pos, t_cyl cy)
{
	t_vt	norm;
	t_vt	tmp;

	tmp = vt_minus(pos, cy.center);
	norm = vt_minus(tmp, vt_multi(cy.dir, vt_dot(cy.dir, tmp)));
	return (vt_unit(norm));
}

int		cy_boundary(t_ray ray, t_cyl cy, t_cyvar var)
{
	double	len;

	var.p = ray_at(&ray, var.t);
	len = sqrt(pow(cy.diam, 2.0) + pow(cy.height, 2.0));
	if (ft_vec_dist(cy.center, var.p) > len)
		return (0);
	return (1);
}
