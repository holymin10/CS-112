################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../App.cpp \
../Vec.cpp \
../VecTester.cpp \
../main.cpp \
../tester.cpp 

CPP_DEPS += \
./App.d \
./Vec.d \
./VecTester.d \
./main.d \
./tester.d 

OBJS += \
./App.o \
./Vec.o \
./VecTester.o \
./main.o \
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
	-$(RM) ./App.d ./App.o ./Vec.d ./Vec.o ./VecTester.d ./VecTester.o ./main.d ./main.o ./tester.d ./tester.o

.PHONY: clean--2e-

