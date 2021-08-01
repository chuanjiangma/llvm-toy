set(template_src TemplateTest.cpp)

add_executable(TemplateTest ${template_src})
target_link_libraries(TemplateTest
    Template
    gtest_main
    gtest
    pthread
)

add_test(TemplateTest TemplateTest WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
