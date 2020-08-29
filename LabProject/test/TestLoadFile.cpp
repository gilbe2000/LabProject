//
// Created by alberto on 28/08/20.
//

#include "gtest/gtest.h"
#include "../LoadFile.h"

TEST(TestLoadResources, testNoFileNamesProvided) {
    std::vector<const char*> vector;
    LoadFile loader;
    loader.upload(vector);
    ASSERT_EQ(loader.getFileNumber(), 0);
}

TEST(TestLoadResources, fileNamesProvided) {

    std::vector<const char*> vector;
    vector.push_back("anything");
    LoadFile loader;
    loader.upload(vector);
    ASSERT_FALSE(loader.getFileNumber()==0);
}
