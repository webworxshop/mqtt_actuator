/***************************************************************************
 *  Copyright 2015 Rob Connolly <rob@webworxshop.com>                      *
 *                                                                         *
 *  This file is part of mqtt_actuator.                                    *
 *                                                                         *
 *  mqtt_actuator is free software: you can redistribute it                *
 *  and/or modify it under the terms of the GNU General Public License     *
 *  as published by the Free Software Foundation, either version 3 of      *
 *  the License, or(at your option) any later version.                     *
 *                                                                         *
 *  Smartclock MK2 is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with mqtt_actuator.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef __TOPICMAP_H
#define __TOPICMAP_H

typedef struct
{
    const char *topic;
    int pin;
} TOPIC_MAP;

extern TOPIC_MAP topicmap[];

#endif

