//
// Created by alberto on 24/08/20.
//

#include "LoadFile.h"

void LoadFile::subscribe(Observer *o) {
    observers.push_back(o);
}

void LoadFile::unsubscribe(Observer *o) {
    observers.remove(o);
}

void LoadFile::notify() const {
    for (const auto obs : observers){
        obs->update();
    }

}

void LoadFile::upload(std::vector<const char *> filenames) {
    fileNumber = static_cast<int>(filenames.size());
    for (auto itr : filenames){
        File file(itr);

        filename = QString(itr);
        size = file.getFileSize();
        loaded = true;
        notify();
    }
}
