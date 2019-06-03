/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:43:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/03 09:30:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_SCENE_H
# define RTV1_SCENE_H

# include "libft_vectors.h"

# ifdef __APPLE__
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
# endif

# ifdef __linux__
#  include <SDL2/SDL.h>
# endif

/*
** Scene structs, pointers to functions & enum:
*/
enum	e_type
{
	sphere,
	plane,
	cone,
	cylinder,
	max_objs
};

# define ETYPE typedef enum e_type  Type

ETYPE;

struct	s_camera
{
	Vector		pos;
	Vector		dir;
	double_t	t;
	bool		is;
};

struct	s_light
{
	Vector		pos;
	Vector		dir;
	double_t	intens;
};

typedef Vector	(*t_fn_inter)(const Vector,
							const Vector,
							const void *restrict const);
typedef Vector	(*t_fn_normal)(const Vector,
							const Vector,
							const struct s_camera *restrict const,
							const void *restrict const);
typedef Color	(*t_fn_uv)(SDL_Surface *restrict const, const Vector);

struct	s_object
{
	Vector		pos;
	Vector		dir;
	Color		clr;
	double_t	radius;
	double_t	spec;
	Type		type;
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

/*
** Scene Default constants, params and also:
*/
# define TEX_MAX        3
# define TEX_WORLD      "resources/world.jpg"
# define TEX_WOOD       "resources/wood.jpg"
# define TEX_RUBBLE     "resources/rubble.jpg"

# define FP_CAM         "Camera:"
# define FP_LIGHT       "Light:"
# define FP_SHADOWS     "eShadow"

# define FP_MAX_OBJS    4
# define FP_SPHERE      "Sphere:"
# define FP_CONE        "Cone:"
# define FP_PLANE       "Plane:"
# define FP_CYLINDER    "Cylinder:"

# define MAX_X  1500
# define MAX_Z  1500
# define MAX_Y  1500

# define MIN_X  -MAX_X
# define MIN_Z  -MAX_Z
# define MIN_Y  -MAX_Y

# define MAX_RADIUS     50
# define MIN_RADIUS     0

# define MAX_SPEC       10000
# define MIN_SPEC       0

# define MAX_ROT_ANGLE  360.0f
# define MIN_ROT_ANGLE  -MAX_ROT_ANGLE

# define MAX_LIGHTS     5
# define MAX_L_INTENS   1.0f
# define MIN_L_INTENS   .0f

/*
** Scene parsing errno messages:
*/
# define PERR       " ERROR"
# define ERR        " ERROR: "
# define WARNING    " WARNING: "

# define E_DIR      ERR "Invalid executable path."
# define E_ALLOC    ERR "Where is memory, pal ?"

# define E_FNMAE    ERR "Missing file name."
# define E_EFILE    ERR "Empty scene file."
# define E_FILEXT   ERR "Invalid scene file extension. (.rtv1)"
# define E_ISYNTAX  ERR "Invalid scene file syntax."

# define E_DUP      ERR "In scene cannot be more than "
# define E_DCAMERA  E_DUP "1 camera."
# define E_MLIGHTS  ERR "Maximum lights in scene: 5."

# define E_OBJ      ERR "Unknown object type."

# define E_NOCAM    ERR "No camera in scene founded."
# define E_NOLIGHT  ERR "No origin lights in scene founded."
# define E_NOOBJS   ERR "No objects in scene founded."

# define E_INRANGE  " not in available range"
# define E_CAMDIR   "Camera destination point(rotation)" E_INRANGE
# define E_CAMPOS   "Camera position" E_INRANGE
# define E_LIGHTPOS "Light position" E_INRANGE
# define E_LINTENSE "Light intensity" E_INRANGE
# define E_OBJPOS   "Object position" E_INRANGE
# define E_OBJRAD   "Object radius" E_INRANGE
# define E_OBJSPEC  "Object specular intensity" E_INRANGE
# define E_OCONERAD "Cone radius" E_INRANGE ". min 1 - max 3."

# define ERRIN_NUM(msg, n) MSG(msg);ft_putnbr(n)
# define ERRIN_N(msg, n, err) {ERRIN_NUM(err,n);MSG(" \"");MSG(msg);MSGN("\"");}
# define ERRIN(err, msg) {MSG(err); MSGN(msg);}
# define E_OCCURED  " Error occured "
# define E_IN_LINE  E_OCCURED "at line: "
# define E_IN_LIGHT E_OCCURED "in light origin: "
# define E_IN_OBJ   E_OCCURED "in object: "

#endif
