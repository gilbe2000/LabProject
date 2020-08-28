//
// Created by alberto on 24/08/20.
//

#ifndef LABPROJECT_LOADFILE_H
#define LABPROJECT_LOADFILE_H

#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include "File.h"
#include <list>
#include <QtCore/QString>
#include <vector>


class LoadFile : public Subject {
public:
    LoadFile() {}

    virtual void subscribe(Observer *o) override;
    virtual void unsubscribe(Observer *o) override;
    virtual void notify () const override;

    void upload(std::vector<const char *> filenames);

    int getSize() const {
        return size;
    }

    int getFileNumber() const {
        return fileNumber;
    }

    bool isLoaded() const {
        return loaded;
    }

    const QString &getFilename() const {
        return filename;
    }

private:
    std::list<Observer*> observers;
    int size;
    int fileNumber;
    bool loaded;
    QString filename;

};


#endif //LABPROJECT_LOADFILE_H
