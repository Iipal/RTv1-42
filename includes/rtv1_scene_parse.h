/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene_parse.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:38:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 17:48:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_SCENE_PARSE_H
# define RTV1_SCENE_PARSE_H

# include "parson.h"
# include "rtv1_structs.h"

bool		rt_parse_scene(Environment *env,
							const char *const scene_file);

bool		rt_parse_cam(Camera *const camera,
				JSON_Object *const root_obj);
bool		rt_parse_lights(Scene *const scene,
				JSON_Object *root_obj);
bool		rt_parse_objects(Scene *const scene,
				JSON_Object *root_obj);

typedef bool (*t_fn_lght)(const JSON_Object *const, Light *const, const size_t);
bool		rt_parse_point_light(const JSON_Object *const light_obj,
				Light *const l, const size_t curr_light);
bool		rt_parse_dir_light(const JSON_Object *const light_obj,
				Light *const l, const size_t curr_light);
typedef bool (*t_fn_obj)(const JSON_Object *const, Object *const, const size_t);
bool		rt_parse_sphere(const JSON_Object *const object_obj,
				Object *const obj, const size_t curr_obj);
bool		rt_parse_plane(const JSON_Object *const object_obj,
				Object *const obj, const size_t curr_obj);

bool		rt_parse_arr_to_vec(const JSON_Array *const arr,
				__v4df *const dst,
				const char *const obj_name,
				const size_t parsing_obj_counter);
bool		rt_parse_color(string hex_str,
				Color *const dst,
				const size_t parsing_obj_counter);

extern bool	rt_read_vec(string *const s, __v4df *const v);

bool		rt_parsed_validation(Scene *restrict const s);

#endif
