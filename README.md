# Temperature\_sensor\_project

# 

# This project name is “Temperature Monitored Alert System”. In this project, I have implemented it using the DS18B20 temperature sensor and ESP32.

# 

# Coming to the project, it has different files called sensor.h, sensor.cpp, messenger.h, messenger.cpp, and sketch.ino.

# 

# In sensor.h, I have written function declarations for initializing the sensor configurations, and in sensor.cpp, I wrote the definitions for the functions declared in the .h file.

# 

# The same thing is also repeated in messenger.h and messenger.cpp. If we want to send any message to the terminal, at that time we are using this messenger module, in which I am sending messages. By using these function definitions in the main file, we can simply reuse this for any other protocol rather than UART.

# 

# I have abstracted sensor.h and messenger.h for a purpose. Suppose if we want to use the same system, like temperature reading and message sending, but with different devices (for example, instead of UART, using other protocols or different sensors), we don’t need to build everything from scratch. We are just using the functions, and they are also useful for different things (like I2C sensors). That is how the abstraction layer will be helpful.

# 

# The main advantage of this project is that the user can get information; they can monitor the limits, change the threshold temperature, and also adjust time delay by sending commands. The user can use the sensors based on requirements and can monitor the system very easily.

# 

# This is the full overview of my project.

