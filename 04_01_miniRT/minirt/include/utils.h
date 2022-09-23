#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include <stdbool.h>
# include <stdlib.h>

//------------------- main --------------------
bool	ft_args_check(int argc, char *argv[]);

//------------------- utils --------------------
void	ft_tblclear(char ***tbl);
int		ft_gnl_without_newline(int fd, char **line);

bool	ft_check_strtoi_iter(\
		const char *str, const int *limit, int *dst, size_t cnt);
bool	ft_check_strtod_iter(\
		const char *str, const double *limit, double *dst, size_t cnt);

//------------------- vectors --------------------
t_vt		vec3(double x, double y, double z);
t_pt		point3(double x, double y, double z);
t_pt		color3(double r, double g, double b);
int			ft_trgb(int t, int r, int g, int b);
void		vset(t_vt *vec, double x, double y, double z);
double		vlength2(t_vt vec);
double		vlength(t_vt vec);
t_vt		vplus(t_vt vec, t_vt vec2);
t_vt		vplus_(t_vt vec, double x, double y, double z);
t_vt		vminus(t_vt vec, t_vt vec2);
t_vt		vminus_(t_vt vec, double x, double y, double z);
t_vt		vmult(t_vt vec, double t);
t_vt		vmult_(t_vt vec, t_vt vec2);
t_vt		vdivide(t_vt vec, double t);
double		vdot(t_vt vec, t_vt vec2);
t_vt		vcross(t_vt vec, t_vt vec2);
t_vt		vunit(t_vt vec);
t_vt	vmin(t_vt vec1, t_vt vec2);

#endif