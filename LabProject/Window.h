//
// Created by alberto on 24/08/20.
//

#ifndef LABPROJECT_WINDOW_H
#define LABPROJECT_WINDOW_H

#include "LoadFile.h"
#include <QtWidgets>
#include <iostream>
#include "Observer.h"
#include "string"

class Window :  public QMainWindow , public Observer
{
    Q_OBJECT

public :
    explicit Window(LoadFile *f, QWidget *parent = nullptr); // *parent = nullptr make program understand that this is a window

    virtual ~Window() {
        files->unsubscribe(this);
    }

    virtual void update() override;


private slots:
    void loadResources();

    LoadFile *getFiles() const {
        return files;
    }

private:

    LoadFile *files;

    QPushButton * button;
    QTextEdit * text;
    QProgressBar * progressBar;

    QLabel * name;
    QLabel * matr;
    QLabel * title;


};


#endif //LABPROJECT_WINDOW_H
