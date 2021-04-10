cmake_minimum_required (VERSION 3.10)

project (SAPER)
#####################################################################
# Tu wymień wszystkie pliki .cpp, z których składa się projekt (rozdzielone spacją)
set ( SOURCES main.cpp MinesweeperBoard.cpp  MSBoardTextView.cpp MSTextController.cpp)
#####################################################################
# Dalej na razie nic nie trzeba zmieniać
# przy każdej kompilacji używaj:
add_compile_options(-Wall -Wextra -g)

add_executable(main ${SOURCES} )

set_target_properties(main PROPERTIES
 CXX_STANDARD 11
 CXX_EXTENSIONS OFF
)