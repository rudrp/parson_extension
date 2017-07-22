/*
 * parson_extension.c
 *
 *  Created on: 19-Jul-2017
 *      Author: Rudresh Pandit
 */

#include <string.h>
#include <stdio.h>

#include "parson/parson.h"

#include "parson_extension.h"





JSON_Status json_array_remove_single(JSON_Array *dest_array, const char *str)
{
	int i;
	const char *str1;
	for (i = 0; i < json_array_get_count(dest_array); i++)
	{
		str1 = json_array_get_string(dest_array, i);
		puts(str1);
		if (strncasecmp(str, str1, strlen(str)) == 0
				&& strncasecmp(str, str1, strlen(str1)) == 0)
		{
			return json_array_remove(dest_array, i);

		}
	}

	return JSONFailure;

}

JSON_Status json_array_append_single(JSON_Array *dest_array, const char *str)
{
	int i;
	const char *str1;

	for (i = 0; i < json_array_get_count(dest_array); i++)
	{
		str1 = json_array_get_string(dest_array, i);
		puts(str1);
		if (strncasecmp(str, str1, strlen(str)) == 0
				&& strncasecmp(str, str1, strlen(str1)) == 0)
		{
			puts("Fail");
			return JSONFailure;
		}
	}

	return json_array_append_string(dest_array, str);
}

JSON_Status json_array_append_bulk(JSON_Array *dest_array,
		JSON_Array *array_to_append)
{
	int i, j;
	int toAppend = 0;
	const char *str;
	const char * str1;
	for (i = 0; i < json_array_get_count(array_to_append); i++)
	{
		str = json_array_get_string(array_to_append, i);

		for (j = 0; j < json_array_get_count(dest_array); j++)
		{
			str1 = json_array_get_string(dest_array, j);
			if (strncasecmp(str, str1, strlen(str)) == 0
					&& strncasecmp(str, str1, strlen(str1)) == 0)
			{
				toAppend = 0;
				break;
			}
			else
				toAppend = 1;

		}
		if (toAppend == 1)
		{
			json_array_append_string(dest_array, str);
			toAppend = 0;
		}

	}

	return JSONSuccess;

}

JSON_Status json_array_remove_bulk(JSON_Array *dest_array,
		JSON_Array *array_to_append)
{
	int i, j;

	const char *str;
	const char * str1;
	for (i = 0; i < json_array_get_count(array_to_append); i++)
	{
		str = json_array_get_string(array_to_append, i);

		for (j = 0; j < json_array_get_count(dest_array); j++)
		{
			str1 = json_array_get_string(dest_array, j);
			if (strncasecmp(str, str1, strlen(str)) == 0
					&& strncasecmp(str, str1, strlen(str1)) == 0)
			{
				json_array_remove(dest_array, j);
			}

		}

	}
	return JSONSuccess;
}

JSON_Status json_string_replace(JSON_Object *json_object,uint8_t* key,uint8_t *value){
	return json_object_set_string(json_object, key, value);
}
