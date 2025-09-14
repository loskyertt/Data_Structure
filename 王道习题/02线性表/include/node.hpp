#pragma once

struct Node {
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

struct DNode {
  int val;
  DNode *prev;
  DNode *next;
  DNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};