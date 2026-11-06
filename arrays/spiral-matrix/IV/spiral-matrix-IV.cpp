
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  void insert(int x) {
    ListNode *node = new ListNode(x, nullptr);

    ListNode *curr = this;
    while (curr->next != nullptr)
      curr = curr->next;

    curr->next = node;
  }
};

class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    vector<vector<int>> matrix(m, vector<int>(n));

    int top = 0;
    int buttom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= buttom and left <= right) {

      // Going right
      for (int j = left; j <= right; j++) {
        if (head != nullptr) {
          matrix[top][j] = head->val;
          head = head->next;
        }

        else
          matrix[top][j] = -1;
      }
      top++;

      // Going down
      for (int i = top; i <= buttom; i++) {
        if (head != nullptr) {
          matrix[i][right] = head->val;
          head = head->next;
        }

        else
          matrix[i][right] = -1;
      }
      right--;

      // Going left
      if (top <= buttom) {
        for (int j = right; j >= left; j--) {
          if (head != nullptr) {
            matrix[buttom][j] = head->val;
            head = head->next;
          }

          else
            matrix[buttom][j] = -1;
        }
      }
      buttom--;

      // Going up
      if (left <= right) {
        for (int i = buttom; i >= top; i--) {
          if (head != nullptr) {
            matrix[i][left] = head->val;
            head = head->next;
          }

          else
            matrix[i][left] = -1;
        }
        left++;
      }
    }

    return matrix;
  }
};

int main() {
  int m = 3;
  int n = 5;
  ListNode head;

  int size;
  cout << "Enter linked list size: ";
  cin >> size;

  int input;
  cout << "Enter first element: ";
  cin >> input;
  head.val = input;
  for (int i = 1; i < size; i++) {
    cout << "Enter element n " << (i + 1) << " :";
    cin >> input;
    head.insert(input);
  }

  Solution sol;
  for (vector<int> row : sol.spiralMatrix(m, n, &head)) {
    for (int x : row)
      cout << x << " ";
    cout << '\n';
  }
}