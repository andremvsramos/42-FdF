/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:23:31 by marvin            #+#    #+#             */
/*   Updated: 2023/01/08 22:23:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# ifndef VIEW
#  define VIEW 3
# endif

# ifndef WIN_X
#  define WIN_X 1920
# endif

# ifndef WIN_Y
#  define WIN_Y 1080
# endif

typedef struct s_draw
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
}				t_draw;

typedef struct s_i
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}				t_i;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	float	zoom;
	int		color;
	float	shift_x;
	float	shift_y;
	float	trans_x;
	float	trans_y;
	int		view2d;
	t_i		*image;

	char	*file_name;

	void	*mlx_ptr;
	void	*win_ptr;
	int		sizex;
	int		sizey;
}				t_fdf;

/*---INIT---*/
void	fdf_init(t_fdf *data);
void	graphics_init(t_fdf *data);
int		boot(char *file, t_fdf *data);

/*---MEMORY MANAGEMENT---*/
void	mem_alloc(t_fdf *data, char *line, int fd, char *file_name);
int		mem_free(char *line, int fd, int f);

/*----HOOKS-----*/
int		deal_key(int key, t_fdf *data);

/*----FILE TREATMENT------*/
int		read_file(char *file_name, t_fdf *data);
void	fill_matrix(t_fdf *data, int index, char *line);
int		get_width(char *file_name);
int		get_height(char *file_name);
void	draw_init(t_draw *draw);
int		ft_strlensep(char *str, char c);
char	*get_fd_name(char *str);
int		check_if_fdf(char *file_name);

/*--------DRAW-------------------*/
void	bresenham(t_draw draw, t_fdf *data);
void	lines(t_draw *aux, t_fdf *data);
int		max(int a, int b);
void	win_draw(t_fdf *data);
void	apply_zoom_and_color(t_draw *draw, t_fdf *data, int z, int z1);
void	isometric(float *x, float *y, float z, t_fdf *data);
void	my_mlx_pixel_put(t_i *data, int x, int y, int color);
void	print_pixels(t_draw draw, t_fdf *data, float draw_x, float draw_y);

/*----COLOR----*/
int		apply_color(float z, float z1);

/*--------WINDOW CONTROL---------*/
void	get_zoom(int key, t_fdf *data);
void	get_move3d(int key, t_fdf *data);
void	get_move2d(int key, t_fdf *data);
void	get_trans(int key, t_fdf *data);
int		win_close(t_fdf *data);
void	check_2d(int key, t_fdf *data);
void	refresh(t_fdf *data);

#endif
