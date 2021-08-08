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
    //Function *p = (Function *)calloc(1, sizeof(Function));
    //printf("p = %p\n", p);
    //printf("&(p->func) = %p\n", &(p->func));
    //printf("&(p->str) = %p\n", &(p->str));
    //printf("&(p->p) = %p\n", &(p->p));
    
    //struct LinkNode *q = &(p->p);
    //强制类型转换，把数 0 强制转换为指向 Function * 结构的地址，而且这个地址在内存位置的 0 处，所以在这种情况下，可以得出结构体成员的偏移量
    //printf("%p\n", &((Function *)(0))->p);   // 先 -> 后 &
    //printf("%lld\n", (long long)(&((Function *)(0))->p));
    
    return RUN_ALL_TESTS();
}
