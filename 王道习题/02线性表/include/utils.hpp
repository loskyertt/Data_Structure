#pragma once

#include "node.hpp"
#include <vector>

using std::vector;

/* 打印链表 */
void print_linked_list(Node *head);

/* 数组转链表 */
Node *create_linked_list(vector<int> &nums);

/* 插入节点，在 n0 和 n1 之间 */
void insert(Node *n0, Node *n1);

/* 删除节点 n0 之后的首个节点 */
void remove(Node *n0);

/* 打印数组 */
void print_vector(const vector<int> &nums);