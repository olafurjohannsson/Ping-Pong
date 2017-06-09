################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Game.cpp \
../helpers.cpp \
../main.cpp 

OBJS += \
./Game.o \
./helpers.o \
./main.o 

CPP_DEPS += \
./Game.d \
./helpers.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	@echo 'Finished building: $<'
	@echo ' '


