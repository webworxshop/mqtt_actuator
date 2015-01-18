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

#include <PubSubClient.h>
#include "SerialClient.h"
#include "config.h"

byte server[] = { 0, 0, 0, 0 };

void callback(char* topic, byte* payload, unsigned int length)
{
    digitalWrite(13, HIGH);
    for(int i = 0; i < MAP_LEN; i++)
    {
        if(strstr(topic, topicmap[i].topic) != NULL)
        {
            if(payload[0] == '1')
		digitalWrite(topicmap[i].pin, HIGH);
            else if(payload[0] == '0')
		digitalWrite(topicmap[i].pin, LOW);
        }
    }
}

SerialClient netClient;
PubSubClient client(server, 1883, callback, netClient);

void doConnect(void)
{
    char willTopic[64];
    sprintf(willTopic, "/devices/%s/status", MQTT_CLIENT_ID); 

    while(!client.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASS, 
        willTopic, 0, true, "offline"));
    client.publish(willTopic, "online");
}

void setup()
{
    char topic[128];

    Serial.begin(9600);
    doConnect();

    for(int i = 0; i < MAP_LEN; i++)
    {
        pinMode(topicmap[i].pin, OUTPUT);
        sprintf(topic, "%s/cmd", topicmap[i].topic);
        client.subscribe(topic);
    }
    pinMode(13, OUTPUT);
}

int state = 0;

void loop()
{
    client.loop();

    // reconnect if needed
    if(!client.connected())
        doConnect();
}

