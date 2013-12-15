#!/bin/bash
GENERATOR_ROOT=${COCOS2DX_ROOT}/tools/bindings-generator
INI_FILE=bind_sample.ini
SECTION_NAME=bind_sample
OUTPUT_PATH=../Classes/LuaGlue
OUTPUT_NAME=lua_bind_sample_auto
LD_LIBRARY_PATH=${CLANG_ROOT}/lib $PYTHON_BIN ${GENERATOR_ROOT}/generator.py $INI_FILE -s $SECTION_NAME -t lua -o ${OUTPUT_PATH} -n $OUTPUT_NAME

