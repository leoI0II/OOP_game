#pragma once

#include<exception>

class FileOpenExcept : public std::exception {
public:
    const char* what();
};

class TileCountError : std::exception {
public:
    const char* what();
};
