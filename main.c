/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Mar 2021 12:27:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testfunc, add) {
    EXPECT_EQ(add(3, 4), 7)
    EXPECT_NE(add(3, 2), 5)
    EXPECT_EQ(add(1, 2), 3)
}

TEST(testfunc, add2) {
    EXPECT_GE(add(3, 4), 7)
    EXPECT_LT(add(3, 2), 6)
    EXPECT_EQ(add(1, 2), 3)
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
