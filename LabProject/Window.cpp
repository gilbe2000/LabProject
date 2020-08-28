//
// Created by alberto on 24/08/20.
//

#include <vector>
#include "Window.h"
Window::Window(LoadFile *f, QWidget *parent) : files(f), QMainWindow(parent){
    files->subscribe(this);
    this->setWindowTitle("Progetto Laboratorio di Programmazione");
    this->setFixedSize(QSize(750, 500));
    name = new QLabel("Giovannoni Alberto", this);
    name->setGeometry(QRect(QPoint(15, 15), QSize(200, 30)));
    name->setAlignment(Qt::AlignLeft);

    matr = new QLabel("Matricola: 7025018", this);
    matr->setGeometry(QRect(QPoint(515, 15), QSize(200, 30)));
    matr->setAlignment(Qt::AlignRight);

    title = new QLabel("Classe che carica risorse e aggiorna una progress bar", this);
    title->setGeometry(QRect(QPoint(60, 50), QSize(650, 100)));
    title->setWordWrap(true);
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(20);
    title->setFont(font);

    button = new QPushButton("Carica Files", this);
    button->setGeometry(QRect(QPoint(300, 160), QSize(170, 30)));

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(230, 220), QSize(300, 30)));

    text = new QTextEdit(this);
    text->setGeometry(QRect(QPoint(150, 260), QSize(500, 140)));
    text->setText("Files caricati: \n");
    text->setReadOnly(true);

    QTextCursor c =  text->textCursor();
    c.movePosition(QTextCursor::End);
    text->setTextCursor(c);

    progressBar->setMinimum(0);
    progressBar->setMaximum(1000);
    progressBar->setValue(0);

    connect(button, SIGNAL (released()), this, SLOT (loadResources()));

}

void Window::update() {

        if (files->isLoaded()) {
            while (progressBar->value() < 1000)
                //Update Progress Bar Percentage
                progressBar->setValue(progressBar->value() + (100 / files->getFileNumber()));

            //Update text log
            QString log = "✅ File '" + QString(files->getFilename()) + QString("' caricato (") +
                          QString::number(files->getSize()) + QString(" bytes).") + "\n";
            text->append(log);

            //Update Button Text
            QString percentText = QString(" Risorse caricate");
            button->setText(percentText);

        } else {
            //Update text log
            QString log = "❌ File non caricato! '" + files->getFilename();
            text->append(log);
        }
    }

void Window::loadResources() {

    text->setText("Files caricati :\n");

    std::vector<const char*> filenames;

    filenames.push_back("files/flower.jpg");
    filenames.push_back("files/bird.jpg");
    filenames.push_back("files/cat.jpg");
    filenames.push_back("files/wallpaper.jpeg");
    filenames.push_back("files/sample.jpg");
    filenames.push_back("files/penguin.jpg");
    filenames.push_back("files/large_image.jpg");
    filenames.push_back("files/sample.txt");
    filenames.push_back("files/hi.mp3");
    filenames.push_back("files/car.jpg");


    files->upload(filenames);

}



