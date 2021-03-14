/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Mar 2021 02:50:33 PM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) (long long)(&(((T *)(0))->name))
#define Head(p, T, name) (T *)((char *)(p) - offset(T, name))

struct LinkNode {
    struct LinkNode *next;
};

#endif
