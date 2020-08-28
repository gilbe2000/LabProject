//
// Created by alberto on 24/08/20.
//

#ifndef LABPROJECT_SUBJECT_H
#define LABPROJECT_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}

public:

    virtual void subscribe(Observer *o) = 0;
    virtual void unsubscribe(Observer *o) = 0;
    virtual void notify() const = 0;

};



#endif //LABPROJECT_SUBJECT_H
