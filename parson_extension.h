/*
 * parson_extension.h
 *
 *  Created on: 19-Jul-2017
 *      Author: Arpana Pandit
 */

#ifndef PARSON_EXTENSION_H_
#define PARSON_EXTENSION_H_

#include <stdint.h>

JSON_Status json_array_remove_single(JSON_Array *dest_array, const char *str);
JSON_Status json_array_append_single(JSON_Array *dest_array, const char *str);
JSON_Status json_array_append_bulk(JSON_Array *dest_array,
		JSON_Array *array_to_append);

JSON_Status json_array_remove_bulk(JSON_Array *dest_array,
		JSON_Array *array_to_append);
JSON_Status json_string_replace(JSON_Object *json_object,uint8_t* key,uint8_t *value);

#endif /* PARSON_EXTENSION_H_ */
