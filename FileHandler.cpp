// FileHandler.cpp
// Created by ducksoft on 3/2/18.
//

#include "FileHandler.h"

#include <cassert>


bool FileHandler::open(const char *path) {
    return (bool)(this->file = fopen(path, "ab"));
}

bool FileHandler::append_zero(int zeros) {
    assert(zeros > 0);

    int result;

    result = fseek(this->file, 0, SEEK_END);
    if (result) return false;

    while (zeros--) {
        result = fputc(0, this->file);
        if (result) return false;
    }

    return true;
}

FileHandler::~FileHandler() {
    fclose(this->file);
}

bool FileHandler::flush() {
    return !fflush(this->file);
}
