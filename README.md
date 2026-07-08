# 138
138. Copy List with Random Pointer
Solved
Medium
Topics
premium lock icon
Companies
Hint
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:





solution





/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextNode;
            temp = nextNode;
        }
        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        temp = head;
        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        while (temp != nullptr) {
            Node* copy = temp->next;
            Node* nextNode = copy->next;
            copyTail->next = copy;
            copyTail = copy;
            temp->next = nextNode;
            temp = nextNode;
        }
        return dummy->next;
    }
};

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

<!---LeetCode Topics Start-->
# LeetCode Topics
## Math
|  |
| ------- |
| [3754-concatenate-non-zero-digits-and-multiply-by-sum-i](https://github.com/Yalamurimonish/138/tree/master/3754-concatenate-non-zero-digits-and-multiply-by-sum-i) |
## Array
|  |
| ------- |
| [0496-next-greater-element-i](https://github.com/Yalamurimonish/138/tree/master/0496-next-greater-element-i) |
| [0907-sum-of-subarray-minimums](https://github.com/Yalamurimonish/138/tree/master/0907-sum-of-subarray-minimums) |
## Hash Table
|  |
| ------- |
| [0496-next-greater-element-i](https://github.com/Yalamurimonish/138/tree/master/0496-next-greater-element-i) |
## Stack
|  |
| ------- |
| [0402-remove-k-digits](https://github.com/Yalamurimonish/138/tree/master/0402-remove-k-digits) |
| [0496-next-greater-element-i](https://github.com/Yalamurimonish/138/tree/master/0496-next-greater-element-i) |
| [0907-sum-of-subarray-minimums](https://github.com/Yalamurimonish/138/tree/master/0907-sum-of-subarray-minimums) |
## Monotonic Stack
|  |
| ------- |
| [0402-remove-k-digits](https://github.com/Yalamurimonish/138/tree/master/0402-remove-k-digits) |
| [0496-next-greater-element-i](https://github.com/Yalamurimonish/138/tree/master/0496-next-greater-element-i) |
| [0907-sum-of-subarray-minimums](https://github.com/Yalamurimonish/138/tree/master/0907-sum-of-subarray-minimums) |
## Dynamic Programming
|  |
| ------- |
| [0907-sum-of-subarray-minimums](https://github.com/Yalamurimonish/138/tree/master/0907-sum-of-subarray-minimums) |
## String
|  |
| ------- |
| [0402-remove-k-digits](https://github.com/Yalamurimonish/138/tree/master/0402-remove-k-digits) |
## Greedy
|  |
| ------- |
| [0402-remove-k-digits](https://github.com/Yalamurimonish/138/tree/master/0402-remove-k-digits) |
<!---LeetCode Topics End-->