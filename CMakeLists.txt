cmake_minimum_required(VERSION 3.11)
project("RobotCar")
set(PRODUCT_NAME "RobotCar")

set(F_CPU 16000000UL) # set clock speed to 16 MHZ
set(MCU atmega328p) # set chip identity full list at (https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html)
set(PROG_TYPE xplainedmini) # set programming device

set(E_FUSE 0xfd)
set(H_FUSE 0xda)
set(L_FUSE 0xfd)
set(LOCK_BIT 0xff)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_ASM_COMPILER avr-gcc)

add_definitions(
    -DF_CPU=${F_CPU}
    -DBAUD=${BAUD}
)

set(CMAKE_EXE_LINKER_FLAGS -mmcu=${MCU})

add_compile_options(
    -mmcu=${MCU} # MCU
    -std=c11 # C11 standard
    -Os # optimize
    -Wall # enable warnings
    -Wextra
    -Wundef
    -Wunused-macros
    -Wnonnull
    -Wimplicit-fallthrough
    -Wmisleading-indentation
    -Wswitch-default
    -Wunused-parameter
    -Wshadow
    -Wparentheses
    -Wpacked
    -Wpadded
    -Winline
    -pedantic
    -Wstrict-prototypes
    -Wl,--relax,--gc-sections
    -funsigned-char # a few optimizations
    -funsigned-bitfields
    -fpack-struct
    -fshort-enums
)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "*c")
file(GLOB_RECURSE REMOVE_CMAKE "build/*" "extern/*" )
list(REMOVE_ITEM SRC_FILES ${REMOVE_CMAKE})
include_directories("/home/sjoerd/opt/avr/avr/include")

add_executable(${PRODUCT_NAME} ${SRC_FILES})
# Rename the output to .elf as we will create multiple files
set_target_properties(${PRODUCT_NAME} PROPERTIES OUTPUT_NAME ${PRODUCT_NAME}.elf)

# Strip binary for upload
add_custom_target(strip ALL avr-strip ${PRODUCT_NAME}.elf DEPENDS ${PRODUCT_NAME})

# Transform binary into hex file, we ignore the eeprom segments in the step
add_custom_target(hex ALL avr-objcopy -R .eeprom -O ihex ${PRODUCT_NAME}.elf ${PRODUCT_NAME}.hex DEPENDS strip)
# Transform binary into hex file, this is the eeprom part (empty if you don't
# use eeprom static variables)
add_custom_target(eeprom avr-objcopy -j .eeprom  --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 -O ihex ${PRODUCT_NAME}.elf ${PRODUCT_NAME}.eep DEPENDS strip)

# Upload the firmware with avrdude
add_custom_target(upload avrdude  -c ${PROG_TYPE} -p ${MCU} -U flash:w:${PRODUCT_NAME}.hex DEPENDS hex)

# Upload the eeprom with avrdude
# add_custom_target(upload_eeprom avrdude -c ${PROG_TYPE} -p ${MCU}  -U eeprom:w:${PRODUCT_NAME}.eep DEPENDS eeprom)

# Burn fuses
add_custom_target(fuses avrdude -c ${PROG_TYPE} -p ${MCU}  -U lfuse:w:${L_FUSE}:m -U hfuse:w:${H_FUSE}:m -U efuse:w:${E_FUSE}:m -U lock:w:${LOCK_BIT}:m )

# Clean extra files
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${PRODUCT_NAME}.hex;${PRODUCT_NAME}.eeprom;${PRODUCT_NAME}.lst")
