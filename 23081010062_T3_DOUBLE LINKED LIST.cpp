#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void addAtLast(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void removeAtFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;

    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }

    free(temp);
}

void removeAtMiddle(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        printf("List kosong atau posisi tidak valid!\n");
        return;
    }

    struct Node* temp = *head_ref;
    int count = 1;

    if (position == 1) {
        removeAtFirst(head_ref);
        return;
    }

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Posisi di luar batas!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
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

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
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
        printf("%d <-> ", temp->data);
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
    printf("Double Linked List setelah ditambahkan data di akhir:\n");
    display(head);

    removeAtFirst(&head);
    printf("Double Linked List setelah data pertama dihapus:\n");
    display(head);

    removeAtMiddle(&head, 3);
    printf("Double Linked List setelah data yang berada di tengah dihapus:\n");
    display(head);

    removeAtLast(&head);
    printf("Double Linked List setelah data terakhir dihapus:\n");
    display(head);

    int index = search(head, 28);
    if (index != -1) {
        printf("Data 28 ditemukan pada indeks %d.\n", index);
    } else {
        printf("Data 28 tidak ditemukan.\n");
    }

    printf("Jumlah data dalam Double Linked List: %d\n", count(head));
    printf("Jumlah semua data dalam Double Linked List: %d\n", sumOfData(head));

    return 0;
}
