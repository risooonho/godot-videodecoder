/*************************************************************************/
/*  godot_videodecoder.h                                                         */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2018 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2018 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef GODOT_NATIVEVIDEODECODER_H
#define GODOT_NATIVEVIDEODECODER_H

#include <gdnative/gdnative.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	void *(*constructor)(godot_object *);
	void (*destructor)(void *);
	char *(*get_plugin_name)(void);
	godot_bool (*open_file)(void *, void *);
	godot_real (*get_length)(const void *);
	godot_real (*get_playback_position)(const void *);
	void (*seek)(void *, godot_real);
	void (*set_audio_track)(void *, godot_int);
	godot_object *(*update)(void *, godot_real); // TODO: Return Texture
	void (*set_mix_callback)(void *, void *, void *); // TODO: 2nd arg Needs to be AudioMixCallback
	godot_int (*get_channels)(const void *);
	godot_int (*get_mix_rate)(const void *);
	godot_vector2 (*get_size)(const void *);
} godot_videodecoder_interface_gdnative;

// FileAccess wrappers for custom FFmpeg IO
godot_int GDAPI godot_videodecoder_file_read(void *file_ptr, uint8_t *buf, int buf_size);
int64_t GDAPI godot_videodecoder_file_seek(void *file_ptr, int64_t pos, int whence);
void GDAPI godot_videodecoder_register_decoder(const godot_videodecoder_interface_gdnative *p_interface);
godot_object GDAPI *godot_videodecoder_create_image(godot_pool_byte_array *byte_array, int x, int y);

#ifdef __cplusplus
}
#endif

#endif /* !GODOT_NATIVEVIDEODECODER_H */