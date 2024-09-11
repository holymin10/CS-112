################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CS112List.cpp \
../testCS112List.cpp \
../tester.cpp 

CPP_DEPS += \
./CS112List.d \
./testCS112List.d \
./tester.d 

OBJS += \
./CS112List.o \
./testCS112List.o \
./tester.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./CS112List.d ./CS112List.o ./testCS112List.d ./testCS112List.o ./tester.d ./tester.o

.PHONY: clean--2e-

