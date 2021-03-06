/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene_parse.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:38:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/26 12:41:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_SCENE_PARSE_H
# define RTV1_SCENE_PARSE_H

# include "parson.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"

/*
** Function prototypes:
*/
bool	rt_parse_scene(Environment *const env,
			char const *const scene_file) NON_NULL((1,2));

bool	rt_parse_cam(Camera *const camera,
			JSON_Object const *const root_obj) NON_NULL((1,2));
bool	rt_parse_lights(Scene *const scene,
			JSON_Object const *const root_obj) NON_NULL((1,2));
bool	rt_parse_objects(Scene *const scene,
			JSON_Object const *const root_obj) NON_NULL((1,2));

typedef bool	(*t_fn_lght)(JSON_Object const *const,
					Light *const, size_t const);
bool	rt_parse_point_light(JSON_Object const *const light_obj,
			Light *const l, size_t const light_i) NON_NULL((1,2));
bool	rt_parse_dir_light(JSON_Object const *const light_obj,
			Light *const l, size_t const light_i) NON_NULL((1,2));

typedef bool	(*t_fn_obj)(JSON_Object const *const,
					Object *const, size_t const);
bool	rt_parse_sphere(JSON_Object const *const object_obj,
			Object *const obj, size_t const obj_i) NON_NULL((1,2));
bool	rt_parse_cone(JSON_Object const *const object_obj,
			Object *const obj, size_t const obj_i) NON_NULL((1,2));
bool	rt_parse_plane(JSON_Object const *const object_obj,
			Object *const obj, size_t const obj_i) NON_NULL((1,2));
bool	rt_parse_cylinder(JSON_Object const *const object_obj,
			Object *const obj, size_t const obj_i) NON_NULL((1,2));

bool	rt_parse_other(Environment *const env,
			JSON_Object const *const root_obj) NON_NULL((1,2));

bool	rt_parse_arr_to_vec(JSON_Array const *const arr,
			t_v4df *const dst,
			char const *const obj_name,
			size_t const parsing_obj_counter) NON_NULL((2,3));
bool	rt_parse_color(char *hex_str,
			Color *const dst,
			size_t const parsing_obj_counter) NON_NULL((1,2));

bool	rt_parsed_scene_validation(Scene *restrict const s) NON_NULL((1));

/*
** Scene Default constants, params and also:
*/
# define TEX_MAX        3
# define TEX_WORLD      "resources/world.jpg"
# define TEX_WOOD       "resources/wood.jpg"
# define TEX_RUBBLE     "resources/rubble.jpg"

# define FP_SPHERE      "Sphere"
# define FP_CONE        "Cone"
# define FP_PLANE       "Plane"
# define FP_CYLINDER    "Cylinder"

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

# define E_VEC_SIZE "Wrong vector size: "
# define E_VEC_FRMT "Wrong vector format: "

# define E_UNKNOWN_OBJ_TYPE "Unknown object type"
# define E_UNKNOWN_LGT_TYPE "Unknown light type"

# define E_INVALID_OBJ "Invalid object"
# define E_INVALID_LGT "Invalid light"

# define E_OARR_TYPE ERR E_INVALID_OBJ "s array type."
# define E_LARR_TYPE ERR E_INVALID_LGT "s array type."

# define E_INVALID_ARR "Invalid array"

# define E_INVALID_OT  E_INVALID_OBJ " type"
# define E_INVALID_LT  E_INVALID_LGT " type"

# define E_MISS         "Missing or invalid "

# define E_CPOS_MISS    E_MISS "camera position"
# define E_CROT_MISS    E_MISS "camera rotation"

# define E_LTYPE_MISS   E_MISS "light type"
# define E_LPOS_MISS    E_MISS "light position"
# define E_LDIR_MISS    E_MISS "light direction"
# define E_LINTENS_MISS E_MISS "light intensity"
# define E_LI_LESS_ZERO "Light intensity less than 0.0"
# define E_LI_GRT_ZERO  "Light intensity greater than 1.0"

# define E_OTYPE_MISS   E_MISS "object type"
# define E_OPOS_MISS    E_MISS "object position"
# define E_OCLR_MISS    E_MISS "object color"
# define E_OCLR_0X_MISS E_MISS "'0x' at start of the object color HEX value"
# define E_OCLR_SPECTR  "Invalid color for object. " CLR_DEF_MAX_SPECTRUM
# define E_INVALID_CLR  "Invalid color or 0x0. Min 0x1."
# define E_INVALID_HCLR "Invalid color hex value."
# define E_ORADIUS_MISS E_MISS "object radius"
# define E_OSPEC_MISS   E_MISS "object specular"
# define E_ODIR_MISS    E_MISS "object direction"

# define E_SPARAM_MISS  E_MISS "shadows control boolean param."

# define E_LPOINT_DIR "'direction' in 'point' light types is useless"
# define E_SPHERE_DIR "'direction' in 'sphere' object types is useless"
# define E_PLANE_RAD  "'radius' in 'plane' object types in useless"

# define E_SHADOWS_BOOL ERR "'Shadows' param must to be 'boolean' type."
# define E_AA_NUMBER    ERR "'Anti-Aliasing' param must to be 'number' type."
# define E_AA_USELESS   ERR "'Anti-Aliasing' param less than 0 or 1. Useless."
# define E_AA_MAX       ERR "'Anti-Aliasing' param greate than 8. Max is 8."

# define E_AL_NUMBER    ERR "'Ambient light' param must to be 'number' type."

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
# define E_IN_CAM   E_OCCURED "in camera: "

# define ERRIN_NUM(msg, n) MSG(msg);ft_putnbr(n)
# define ERRIN_N(msg, n, err) {ERRIN_NUM(err,n);MSG(" \"");MSG(msg);MSGN("\"");}
# define ERRIN(err, msg) {MSG(err); MSGN(msg);}

#endif
