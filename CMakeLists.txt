# CMakeList.txt : CMake project for DontGetAngryProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("DontGetAngryProject")

# Add source to this project's executable.
add_executable (DontGetAngryProject ".cpp/DontGetAngryProject.cpp" ".hpp/DontGetAngryProject.hpp" ".hpp/Board.hpp" "fields/hpp/Field.hpp" ".hpp/Player.hpp" ".hpp/Pawn.hpp" "fields/hpp/PlayerBaseEntranceField.hpp" "fields/hpp/PlayerStackExitField.hpp" "fields/cpp/Field.cpp"  ".cpp/Board.cpp" "fields/cpp/PlayerOwnedField.cpp" "fields/cpp/PlayerStackField.cpp" "fields/cpp/PlayerStackExitField.cpp" "fields/cpp/PlayerBaseEntranceField.cpp" "fields/cpp/PlayerBaseField.cpp")

# TODO: Add tests and install targets if needed.
