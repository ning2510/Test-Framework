/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Mar 2021 07:45:37 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <haizei/linklist.h>

#define TEST(a, b) \
void a##_haizei_##b();\
__attribute__((constructor)) \
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()

/* 
__attribute__((constructor)) void a##_haizei_##_b() {}

__attribute__((constructor))  宏可以使函数(void a##_haizei_##b())比主函数优先执行
*/

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define TYPE(a) _Generic((a), \
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    const char * : "%s",\
    char * : "%s"\
)

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    haizei_test_info.total += 1;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if(_a comp _b) haizei_test_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpext : " #a " " #comp " " #b "\n\t\t" "actual : " ));\
        P(_a, YELLOW_HL);\
        P(" vs ", YELLOW_HL);\
        P(_b, YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN_HL("[-----------] ") #a " " #comp " " #b);\
    printf(" %s\n", _a comp _b ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)

typedef void (*TestFunc)();  //TeshFunc:函数指针类型

typedef struct Function {
    TestFunc func;
    const char *str;
    struct LinkNode p;
}Function;

struct FunctionInfo {
    int total, success;
};
// 声明一个外部的变量
extern struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS();
void add_function(TestFunc, const char*);

/* 
命令: g++ -I./ -E main.cpp
main.cpp 中引用 test.h 中的宏展开后的代码:

typedef void (*TestFunc)();

typedef struct Function {
    TestFunc func;
    const char *str;
}Function;

int RUN_ALL_TESTS();
void add_function(TestFunc, const char*);

int add(int a, int b) {
    return a + b;
}

void testfunc_haizei_add();

__attribute__((constructor)) void add_haizei_testfunc_haizei_add() {
    add_function(testfunc_haizei_add, "testfunc" "_haizei_" "add");
}

void testfunc_haizei_add() {
    printf("%s == %s ? %s\n", "add(3, 4)", "7", (add(3, 4)) == (7) ? "True" : "False");
    printf("%s == %s ? %s\n", "add(1, 2)", "3", (add(1, 2)) == (3) ? "True" : "False");
    ...
}
*/

#endif
