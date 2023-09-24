CC=gcc
BUILD_DIR=build
SOURCE_DIR=src
TARGET=$(BUILD_DIR)/output
OBJECTS=$(BUILD_DIR)/main.o
 
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^


$(BUILD_DIR)/main.o : $(SOURCE_DIR)/main.c
	$(CC) -c -o $@ $^

clean:
	rm $(OBJECTS) $(TARGET)