#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addAtLast(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref; 
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head_ref; 
    }
}

void removeAtFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (temp->next == *head_ref) {
         free(temp);
        *head_ref = NULL;
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        *head_ref = temp->next;
        last->next = *head_ref; 
        free(temp);
    }
}

void removeAtMiddle(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        printf("List kosong atau posisi tidak valid!\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (position == 1) {
        removeAtFirst(head_ref);
        return;
    }

    int count = 1;
    struct Node* prev = NULL;

    while (count < position && temp->next != *head_ref) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count == position) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Posisi di luar batas!\n");
    }
}

void removeAtLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (temp->next == *head_ref) {
        free(temp);
        *head_ref = NULL;
    } else {
        struct Node* last = *head_ref;
        struct Node* prev = NULL;

        while (last->next != *head_ref) {
            prev = last;
            last = last->next;
        }
        prev->next = *head_ref; 
        free(last);
    }
}

int search(struct Node* head, int key) {
    if (head == NULL) {
        return -1;
    }

    struct Node* temp = head;
    int index = 0;

    do {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    } while (temp != head);

    return -1; 
}

int count(struct Node* head) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    struct Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int sumOfData(struct Node* head) {
    if (head == NULL) {
        return 0;
    }

    int sum = 0;
    struct Node* temp = head;
    do {
        sum += temp->data;
        temp = temp->next;
    } while (temp != head);

    return sum;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n"); 
}

int main() {
    struct Node* head = NULL;

    addAtLast(&head, 15);
    addAtLast(&head, 20);
    addAtLast(&head, 28);
    addAtLast(&head, 43);
    addAtLast(&head, 65);
    printf("Circular Linked List setelah menambahkan data di akhir:\n");
    display(head);

    removeAtFirst(&head);
    printf("Circular Linked List setelah menghapus data pertama:\n");
    display(head);

    removeAtMiddle(&head, 2);
    printf("Circular Linked List setelah menghapus data di posisi tengah:\n");
    display(head);

    removeAtLast(&head);
    printf("Circular Linked List setelah menghapus data terakhir:\n");
    display(head);

    int index = search(head, 28);
    if (index != -1) {
        printf("Data 28 ditemukan pada indeks %d.\n", index);
    } else {
        printf("Data 28 tidak ditemukan.\n");
    }

    printf("Jumlah data dalam Circular Linked List: %d\n", count(head));
    printf("Jumlah semua data dalam Circular Linked List: %d\n", sumOfData(head));

    return 0;
}
