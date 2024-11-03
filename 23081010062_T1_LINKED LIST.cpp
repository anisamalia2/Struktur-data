#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addAtLast(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void removeAtFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void removeAtMiddle(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        printf("List kosong atau posisi tidak valid!\n");
        return;
    }

    struct Node* temp = *head_ref;
    int count = 0;

    if (position == 1) {
        removeAtFirst(head_ref);
        return;
    }

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Posisi di luar batas!\n");
        return;
    }

    struct Node* to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

void removeAtLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

int search(struct Node* head, int key) {
    struct Node* temp = head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1; 
}

int count(struct Node* head) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int sumOfData(struct Node* head) {
    struct Node* temp = head;
    int sum = 0;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    addAtLast(&head, 15);
    addAtLast(&head, 20);
    addAtLast(&head, 28);
    addAtLast(&head, 43);
    addAtLast(&head, 65);
    printf("Linked List setelah ditambahkan data di akhir:\n");
    display(head);

    removeAtFirst(&head);
    printf("Linked List setelah data pertama dihapus:\n");
    display(head);

    removeAtMiddle(&head, 2); 
    printf("Linked List setelah data yang berada ditengah dihapus:\n");
    display(head);

    removeAtLast(&head);
    printf("Linked List setelah data terakhir dihapus:\n");
    display(head);

    int index = search(head, 28); 
    if (index != -1) {
        printf("Data 28 ditemukan pada indeks %d.\n", index);
    } else {
        printf("Data 28 tidak ditemukan.\n");
    }

    printf("Jumlah data dalam Linked List: %d\n", count(head));
    printf("Jumlah semua data dalam Linked List: %d\n", sumOfData(head));

    return 0;
}
