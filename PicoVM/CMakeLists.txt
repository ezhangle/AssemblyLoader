cmake_minimum_required( VERSION 2.8 )

project(PicoVM)

set( SRC_DIR ${PROJECT_SOURCE_DIR} )

set( CMAKE_BUILD_TYPE DEBUG )

set( CMAKE_CXX_FLAGS_DEBUG "-g -O2 -std=c++11 -Wall -Wextra -Wshadow" )

set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY .. )

set( APP_NAME picovm )

include_directories( CLR/ )

set( HEADERS_ONLY

        CLIHeader
        EnumCasting
        Formatting
        ImageDataDirectory
        ImageFileHeader
        ImageNTHeader32
        ImageNTHeader64
        ImageOptionalHeader32
        ImageOptionalHeader64
        ImageSectionHeader
        NumCasting
        Property
        utf8
   )

list( APPEND SRC ${SRC_DIR}/main.cxx )

set( OUR_SRC

        AppDomain
        AssemblyData
        AssemblyReader
        ExecutionThread
        EvaluationStack
        InstructionTree
        CLIElementTypes
        CLIMetadata
        CLIMetadataTableIndex
        CLIMetadataTableRows
        CLIMethodBody
        CLISignature
        HexStr
   )

foreach( class ${OUR_SRC} )
    list( APPEND SRC ${SRC_DIR}/CLR/${class}.cxx )
endforeach()

list( APPEND SRC ${SRC_DIR}/CLR/crossguid/guid.cxx )

add_executable( ${APP_NAME} ${SRC} )
