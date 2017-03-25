SOURCES += main.cpp

# Compile with high warning levels, a warning is an error
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror

# C++14
CONFIF += c++14
QMAKE_CXXFLAGS += -std=c++14

# Debug and release mode
CONFIG += console debug_and_release
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# gprof
QMAKE_CXXFLAGS += -pg
QMAKE_LFLAGS += -pg

