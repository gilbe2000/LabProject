//
// Created by alberto on 24/08/20.
//

#ifndef LABPROJECT_FILE_H
#define LABPROJECT_FILE_H

#include <iostream>
#include <string>

class File {

public:
    explicit File( const char* filename) {
        fileSize = random();
    };

    int getFileSize() const {
        return abs(fileSize);
    }

    virtual ~File() {};

private:
    long int fileSize;
};


#endif //LABPROJECT_FILE_H
