/*
* Copyright (c) 2013-2014 Vladimir Alemasov
* All rights reserved
*
* This program and the accompanying materials are distributed under 
* the terms of GNU General Public License version 2 
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#ifndef __LIST_USER_H__
#define __LIST_USER_H__

#include "list.h"

#ifdef _MSC_VER
#include "stdint_msc.h"	/* uint8_t ... uint64_t */
#else
#include <stdint.h>		/* uint8_t ... uint64_t */
#include <stddef.h>		/* size_t */
#endif

typedef struct list_mqtt_user
{
	list_t next;
	uint16_t user_name_length;
	uint8_t *user_name;
	uint16_t password_length;
	uint8_t *password;
	unsigned char publish_enable;
} list_mqtt_user_t;

list_mqtt_user_t *list_mqtt_user_add_new(list_mqtt_user_t **list, const char *user_name, const char *password, unsigned char publish_enable);
#define list_mqtt_user_add(a, b) (list_mqtt_user_t *)list_add((list_t **)a, (list_t *)b)
#define list_mqtt_user_next(a) (list_mqtt_user_t *)list_next((list_t *)a)
void list_mqtt_user_remove_all(list_mqtt_user_t **list);
list_mqtt_user_t *list_mqtt_user_find_user(list_mqtt_user_t **list, uint8_t *user_name, uint16_t user_name_length, uint8_t *password, uint16_t password_length);

#endif /* __LIST_USER_H__ */
