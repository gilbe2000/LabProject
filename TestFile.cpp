//
// Created by alberto on 28/08/20.
//

#include "gtest/gtest.h"
#include "../File.h"

TEST(TestFile, testNonExistentResource) {
    ASSERT_THROW(File file("../resources/non_existing_file.jpg"), std::runtime_error);
}

TEST(TestFile, testExistentResource) {
    ASSERT_NO_THROW(File file("../resources/bird.jpg"));
}

TEST(TestFile, testSizeForExistentFile) {
    File file("../resources/bird.jpg");
    ASSERT_FALSE(file.getFileSize() == 0);
}
