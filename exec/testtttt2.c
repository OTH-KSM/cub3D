// #include <bits/stdc++.h>
// using namespace std;

// // Representation of a Linked List's node
// struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
// };

// // Function to insert an element at the end of a Linked List - O(n)
// void insertAtEnd(ListNode*& head, int element) {
//    ListNode *toAdd = new ListNode(element), *temp = head;
//    if (temp == nullptr) {
//        // If empty list, assign the new node to head
//        head = temp = toAdd;
//    } else {
//        // Otherwise, go to the last node and add the new node after it
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        temp->next = toAdd;
//    }
// }

// ListNode* createLinkedList(int arr[], int size) {
//    ListNode* head = nullptr;
//    for (int i = 0; i < size; ++i) {
//        insertAtEnd(head, arr[i]);
//    }
//    return head;
// }

// void deleteNode(struct ListNode** head_ref, int key) 
// { 
//     // Store head node 
//     struct ListNode *temp = *head_ref, *prev; 
  
//     // If head node itself holds the key to be deleted 
//     if (temp != NULL && temp->data == key) { 
//         *head_ref = temp->next; // Changed head 
//         free(temp); // free old head 
//         return; 
//     } 
  
//     // Search for the key to be deleted, keep track of the 
//     // previous node as we need to change 'prev->next' 
//     while (temp != NULL && temp->data != key) { 
//         prev = temp; 
//         temp = temp->next; 
//     } 
  
//     // If key was not present in linked list 
//     if (temp == NULL) 
//         return; 
  
//     // Unlink the node from linked list 
//     prev->next = temp->next; 
  
//     free(temp); // Free memory 
// } 
// int main() {
//    int arr[] = {3, 1, 4, 5, 2}, size = 5;

//    // Converting the given array to a Linked List
//    ListNode* head = createLinkedList(arr, size);

//    // Printing the Linked List
//    printLinkedList(head);
// }

// int maxCoins(int* nums, int numsSize) {
//     int i = 0;
//     int coin1, coin2, coin3;
//     int coins =0;
//     if(i - 1 >= 0)
//         coin1 = nums[i - 1];
//     else
//         coin1 = 1;
//     if(i + 1 <= numsSize)
//         coin3 = nums[i + 1];
//     else
//         coin3 = 1;
//     coin2 = nums[i];
//     coins = coin1 * coin2 * coin3;
//     ListNode * head = createLinkedList(nums, numsSize);
    
//     return(coins);
// }