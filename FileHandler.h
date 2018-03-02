// FileHandler.h
// Created by ducksoft on 3/2/18.
//

#ifndef BAPZ_FILEHANDLER_H
#define BAPZ_FILEHANDLER_H

#include <cstdio>

class FileHandler {
public:
    bool open(const char* path);
    bool append_zero(int zeros);
    bool flush();
    ~FileHandler();

private:
    FILE* file = nullptr;
};


#endif //BAPZ_FILEHANDLER_H
