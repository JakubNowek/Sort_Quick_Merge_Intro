# CMakeList.txt: projekt CMake dla elementu CMakeProject1, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("Main")
include_directories(inc)
file(GLOB SOURCE "src/*.cpp" "inc/*.h")
# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable( ${PROJECT_NAME} ${SOURCE}  "inc/TabFill.h"  "inc/Display.h"  "inc/Rozmiar.h" "inc/MergeSort.h"    "inc/QuickSort.h" "inc/IntroSort.h" "inc/Exchange.h")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.


#