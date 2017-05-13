################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameBoard.cpp \
../Pong.cpp \
../game_object_mgr.cpp \
../tetris.cpp 

OBJS += \
./GameBoard.o \
./Pong.o \
./game_object_mgr.o \
./tetris.o 

CPP_DEPS += \
./GameBoard.d \
./Pong.d \
./game_object_mgr.d \
./tetris.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	@echo 'Finished building: $<'
	@echo ' '


