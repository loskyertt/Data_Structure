#pragma once

#include "node.hpp"
#include <vector>

/* 打印单链表 */
void print_linked_list(Node *head);

/* 打印循环单链表 */
void print_linked_list_looped(Node *head);

/* 打印循环双链表 */
void print_linked_listD_looped(DNode *head);

/* 数组转单链表 */
Node *create_linked_list(std::vector<int> &nums);

/* 数组转循环单链表 */
Node *create_linked_list_looped(std::vector<int> &nums);

/* 数组转循环双链表 */
DNode *create_linked_listD_looped(std::vector<int> &nums);

/* 插入节点，在 n0 和 n1 之间 */
void insert(Node *n0, Node *n1);

/* 删除节点 n0 之后的首个节点 */
void remove(Node *n0);

/* 打印数组 */
void print_vector(const std::vector<int> &nums);