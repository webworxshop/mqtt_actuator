BOARD_TAG    = atmega328 
ARDUINO_PORT = /dev/ttyUSB*

ARDUINO_LIBS = pubsubclient/PubSubClient arduino_serial_client 
ARDUINO_SKETCHBOOK = .

include $(ARDMK_DIR)/Arduino.mk
