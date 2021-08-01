file(GLOB TOYC_SRC toyc/*.cpp)
add_executable(toyc ${TOYC_SRC} $<TARGET_OBJECTS:LEX_OBJ>)

target_link_libraries(toyc)

install(TARGETS toyc)
