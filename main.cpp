#include <iostream>
#include <random>

#include "FileHandler.h"


using namespace std;


int main(int argc, char** argv) {
    cout << "bapz: back-append zeros utility" << endl;

    if (argc == 1) {
        cout << "usage: bapz <filename> [append-length]" << endl << endl
             << " * filename: the file to be processed." << endl
             << " * append-length: count of zero(s) to append." << endl << endl;
        cerr << "warning: incorrect use of this program can cause data loss! handle with care!" << endl;
    } else if (argc <= 3) {
        const char* path = argv[1];
        clog << "processing file " << path << " ..." << endl;

        clog << "opening file..." << endl;
        FileHandler file;
        if (!file.open(path)) {
            cerr << "error occurred when trying to open file in binary append mode." << endl;
            return 1;
        }

        int append_length;
        if (argc == 2) {
            random_device random;
            append_length = random() % 32 + 16;
            clog << "using randomly generated length " << append_length << "." << endl;
        } else {
            const char* user_append_length = argv[2];
            int user_length = atoi(user_append_length);

            if (user_length > 0) {
                append_length = user_length;
                clog << "using user specified length " << append_length << "." << endl;
            } else {
                cerr << "invalid append-length specification '" << user_append_length << "'." << endl;
                return 4;
            }
        }

        clog << "appending " << append_length << " zeros..." << endl;
        if (!file.append_zero(append_length)) {
            cerr << "error occurred when appending zeros." << endl;
            return 2;
        }

        clog << "flushing..." << endl;
        if (!file.flush()) {
            cerr << "error occurred when flushing bytes." << endl;
            return 3;
        }

        clog << "done." << endl;
    } else {
        cerr << "expected 0, 1 or 2 argument(s), found " << argc << " arguments." << endl;
        cout << "hint: use no argument to get usage." << endl;
        return 5;
    }

    return 0;
}