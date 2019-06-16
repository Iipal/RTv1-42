/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:43:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/16 13:48:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_SCENE_STRUCTS_H
# define RTV1_SCENE_STRUCTS_H

# include "libvectors.h"
# include "libftsdl.h"

/*
** Scene structs, pointers to functions & enum:
*/
enum	e_object_types
{
	sphere,
	plane,
	cone,
	cylinder,
	max_objs
} __attribute__((packed));

enum	e_light_types
{
	point,
	direct,
} __attribute__((packed));

# define E_OBJ_TYPES  typedef enum e_object_types objType
# define E_LGHT_TYPES typedef enum e_light_types  lightType

E_OBJ_TYPES;
E_LGHT_TYPES;

struct	s_camera
{
	__v4df		pos;
	__v4df		dir;
	double_t	t;
	bool		is;
};

struct	s_light
{
	__v4df		pos;
	__v4df		dir;
	lightType	type;
	double_t	intens;
};

typedef __v4df	(*t_fn_inter)(const __v4df,
							const __v4df,
							const void *restrict const);
typedef __v4df	(*t_fn_normal)(const __v4df,
							const __v4df,
							const struct s_camera *restrict const,
							const void *restrict const);
typedef Uint32	(*t_fn_uv)(SDL_Surface *restrict const, const __v4df);

struct	s_object
{
	__v4df		pos;
	__v4df		dir;
	Color		clr;
	double_t	radius;
	double_t	spec;
	objType		type;
	SDL_Surface	*texture;
	t_fn_inter	fn_inter_calc;
	t_fn_normal	fn_normal_calc;
	t_fn_uv		fn_uv;
};

# define CAMERA typedef struct s_camera    Camera
# define LIGHT typedef struct s_light      Light
# define OBJECT typedef struct s_object    Object
# define ISRNDR typedef struct s_isrender  Isr
# define TIME typedef struct s_time        Time

CAMERA;
LIGHT;
OBJECT;
ISRNDR;
TIME;

struct	s_scene
{
	Camera		cam;
	Light		*lights;
	Object		*objs;
	size_t		ins_lights;
	size_t		ins_objs;
	bool		is_render_shadow;
};

# define SCENE typedef struct s_scene   Scene

SCENE;

#endif
