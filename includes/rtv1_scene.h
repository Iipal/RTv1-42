/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:43:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 16:33:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_SCENE_H
# define RTV1_SCENE_H

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

/*
** Scene Default constants, params and also:
*/
# define TEX_MAX        3
# define TEX_WORLD      "resources/world.jpg"
# define TEX_WOOD       "resources/wood.jpg"
# define TEX_RUBBLE     "resources/rubble.jpg"

# define FP_MAX_OBJS    4
# define FP_SPHERE      "sphere"
# define FP_CONE        "cone"
# define FP_PLANE       "plane"
# define FP_CYLINDER    "cylinder"

# define MAX_LT    2
# define LT_POINT  "point"
# define LT_DIRECT "direct"

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

# define MAX_L_INTENS   1.0f
# define MIN_L_INTENS   .0f

# define DEF_VEC_SIZE   3

# define MAX_HEX_SPECTRUM_LENGHT 6
# define CLR_DEF_MAX_SPECTRUM "Color must contain only 0xRRGGBB"

/*
** Scene parsing errno messages:
*/
# define E_DUP     ERR "In scene cannot be more than "
# define E_DCAMERA E_DUP "1 camera."

# define E_NOCAM   ERR "No camera in scene founded."
# define E_NOLIGHT ERR "No origin lights in scene founded."
# define E_NOOBJS  ERR "No objects in scene founded."

# define W_MISS_PARAM(param, obj) WARNING "Missing " param " param for " obj
# define E_MISS_PARAM(param, obj) ERR "Missing " param " param for " obj

# define E_VEC_SIZE "Wrong vector size: "
# define E_VEC_FRMT "Wrong vector format: "

# define E_UNKNOWN_OBJ_TYPE "Unknown object type"
# define E_UNKNOWN_LGT_TYPE "Unknown light type"

# define E_INVALID_OBJ "Invalid object"
# define E_INVALID_LGT "Invalid light"

# define E_OARR_TYPE ERR E_INVALID_OBJ "s array type."
# define E_LARR_TYPE ERR E_INVALID_LGT "s array type."

# define E_INVALID_OT  E_INVALID_OBJ " type"
# define E_INVALID_LT  E_INVALID_LGT " type"

# define E_LTYPE_MISS   "Missing light type"
# define E_LPOS_MISS    "Missing light position"
# define E_LDIR_MISS    "Missing light direction"
# define E_LINTENS_MISS "Missing light intensity"
# define E_LI_LESS_ZERO "Light intensity less than 0.0"
# define E_LI_GRT_ZERO  "Light intensity greater than 1.0"

# define E_OTYPE_MISS   "Missing object type"
# define E_OPOS_MISS    "Missing object position"
# define E_OCLR_MISS    "Missing object color"
# define E_OCLR_0X_MISS "Missing '0x' at start of the object color HEX value"
# define E_OCLR_SPECTR  "Invalid color for object. " CLR_DEF_MAX_SPECTRUM
# define E_INVALID_CLR  "Invalid color of 0x0. Min 0x1."
# define E_ORADIUS_MISS "Missing object radius"
# define E_OSPEC_MISS   "Missing object radius"

# define E_LPOINT_DIR "'direction' in 'point' light types is useless"
# define E_SPHERE_DIR "'direction' in 'sphere' object types is useless"

# define E_INRANGE " not in available range"

# define E_CAMDIR "Camera rotation" E_INRANGE
# define E_CAMPOS "Camera position" E_INRANGE

# define E_LIGHTPOS "Light position" E_INRANGE
# define E_LINTENSE "Light intensity" E_INRANGE

# define E_OBJPOS  "Object position" E_INRANGE
# define E_OBJRAD  "Object radius" E_INRANGE
# define E_OBJSPEC "Object specular intensity" E_INRANGE

# define E_OCONERAD "Cone radius" E_INRANGE ". min 0.01 - max 3.2."

# define E_OCCURED  " Error occured "
# define E_IN_LINE  E_OCCURED "at line: "
# define E_IN_LIGHT E_OCCURED "in light origin: "
# define E_IN_OBJ   E_OCCURED "in object: "

# define ERRIN_NUM(msg, n) MSG(msg);ft_putnbr(n)
# define ERRIN_N(msg, n, err) {ERRIN_NUM(err,n);MSG(" \"");MSG(msg);MSGN("\"");}
# define ERRIN(err, msg) {MSG(err); MSGN(msg);}

#endif
