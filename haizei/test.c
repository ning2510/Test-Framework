#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

Function func_head, *func_tail = &func_head;
struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS() {
    for(struct LinkNode *p = func_head.p.next; p; p = p->next) {
        Function *func = Head(p, Function, p);
        printf(GREEN_HL("[====RUN====]") RED_HL(" %s") "\n", func->str);
        haizei_test_info.total = 0;
        haizei_test_info.success = 0;
        func->func();
        double rate = 100.0 * haizei_test_info.success / haizei_test_info.total;
        printf(GREEN_HL("[  "));
        if(fabs(rate) - 100.0 < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN_HL("  ]") " total : %d    success : %d\n", haizei_test_info.total, haizei_test_info.success);
    }
    return 0;
}

void add_function(TestFunc func, const char *str) {
    Function *temp = (Function *)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(str); // strdp 会将 str 拷贝一份，然后将新拷贝的字符串的地址赋给别的值，，可以防止对原字符串进行操作
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
}

