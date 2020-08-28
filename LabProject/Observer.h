//
// Created by alberto on 24/08/20.
//

#ifndef LABPROJECT_OBSERVER_H
#define LABPROJECT_OBSERVER_H


class Observer {
public:

    virtual  ~Observer() {};
    virtual void update() = 0;

};


#endif //LABPROJECT_OBSERVER_H
