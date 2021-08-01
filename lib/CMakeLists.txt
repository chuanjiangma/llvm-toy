file(GLOB TemplateSrc Template/*.cpp)
add_library(Template STATIC ${TemplateSrc})
install(TARGETS Template)
#add_library(Template SHARED ${TemplateSrc})

file(GLOB LEX_SRC Lex/*.cpp)
add_library(LEX_OBJ OBJECT ${LEX_SRC})

