/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:43:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 14:41:39 by tmaluh           ###   ########.fr       */
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
	max_lights
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
};

struct	s_light
{
	__v4df		pos;
	__v4df		dir;
	double_t	intens;
	lightType	type;
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
	SDL_Surface	*texture;
	t_fn_inter	fn_inter_calc;
	t_fn_normal	fn_normal_calc;
	t_fn_uv		fn_uv;
	__v4df		pos;
	__v4df		dir;
	double_t	radius;
	double_t	spec;
	Color		clr;
	objType		type;
};

# define CAMERA typedef struct s_camera    Camera
# define LIGHT typedef struct s_light      Light
# define OBJECT typedef struct s_object    Object
# define TIME typedef struct s_time        Time

CAMERA;
LIGHT;
OBJECT;
TIME;

struct	s_scene
{
	Light		*lights;
	Object		*objs;
	size_t		ins_lights;
	size_t		ins_objs;
	double_t	tmax;
	double_t	tmin;
	Camera		cam;
	bool		is_camera_exist;
};

# define SCENE typedef struct s_scene   Scene

SCENE;

#endif
