BOARD_TAG    = atmega328 
ARDUINO_PORT = /dev/ttyUSB*

ARDUINO_LIBS = pubsubclient/PubSubClient 
ARDUINO_SKETCHBOOK = .

include $(ARDMK_DIR)/Arduino.mk
