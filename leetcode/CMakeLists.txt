include_directories(include)

file(GLOB SOURCE
    "include/*.h"
    "src/*.cpp"
)

add_library(leetcode SHARED STATIC ${SOURCE})
target_include_directories(leetcode PUBLIC include)