//
// Created by alberto on 28/08/20.
//

#include "gtest/gtest.h"
#include "../LoadFile.h"
#include "../Window.h"

TEST(TestObserver, testFileName) {

    LoadFile loader;
    Window observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("file.h");
    loader.upload(vector);

    ASSERT_EQ(observer.files->getFilename(), "file.h");
}

TEST(TestObserver, testFileSize) {
    LoadFile loader;
    Window observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("../resources/bird.jpg");
    loader.upload(vector);

    ASSERT_EQ(observer.files->getSize(), 356059);
}

TEST(TestObserver, testLoaded) {

    LoadFile loader;
    Window observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("../resources/bird.jpg");
    loader.upload(vector);

    ASSERT_EQ(observer.files->isLoaded(), true);
}

