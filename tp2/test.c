#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} List;

// Prototypes
List* create_list();
void free_list(List* list);
int add_front(List* list, int value);
int add_back(List* list, int value);
int remove_value(List* list, int value);
int modify_value(List* list, int old_value, int new_value);
void sort_list(List* list);
int insert_sorted(List* list, int value);
int list_size(List* list);
void print_list(List* list);

// Helper
int is_full();
int is_empty(List* list);

// Implementation
List* create_list() {
    List* list = malloc(sizeof(List));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

void free_list(List* list) {
    if (!list) return;
    Node* curr = list->head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(list);
}

int is_full() {
    // Try to allocate a node to check memory
    Node* test = malloc(sizeof(Node));
    if (!test) return 1;
    free(test);
    return 0;
}

int is_empty(List* list) {
    return !list || list->size == 0;
}

int add_front(List* list, int value) {
    if (!list || is_full()) return 0;
    Node* node = malloc(sizeof(Node));
    if (!node) return 0;
    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;
    return 1;
}

int add_back(List* list, int value) {
    if (!list || is_full()) return 0;
    Node* node = malloc(sizeof(Node));
    if (!node) return 0;
    node->value = value;
    node->next = NULL;
    if (!list->head) {
        list->head = node;
    } else {
        Node* curr = list->head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
    list->size++;
    return 1;
}

int remove_value(List* list, int value) {
    if (is_empty(list)) return 0;
    Node* curr = list->head;
    Node* prev = NULL;
    while (curr) {
        if (curr->value == value) {
            if (prev) prev->next = curr->next;
            else list->head = curr->next;
            free(curr);
            list->size--;
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

int modify_value(List* list, int old_value, int new_value) {
    if (is_empty(list)) return 0;
    Node* curr = list->head;
    while (curr) {
        if (curr->value == old_value) {
            curr->value = new_value;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void sort_list(List* list) {
    if (is_empty(list) || list->size == 1) return;
    for (Node* i = list->head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->value < min->value) min = j;
        }
        if (min != i) {
            int tmp = i->value;
            i->value = min->value;
            min->value = tmp;
        }
    }
}

int insert_sorted(List* list, int value) {
    if (!list || is_full()) return 0;
    Node* node = malloc(sizeof(Node));
    if (!node) return 0;
    node->value = value;
    node->next = NULL;
    if (!list->head || value < list->head->value) {
        node->next = list->head;
        list->head = node;
    } else {
        Node* curr = list->head;
        while (curr->next && curr->next->value < value) curr = curr->next;
        node->next = curr->next;
        curr->next = node;
    }
    list->size++;
    return 1;
}

int list_size(List* list) {
    return list ? list->size : 0;
}

void print_list(List* list) {
    if (is_empty(list)) {
        printf("Liste vide.\n");
        return;
    }
    Node* curr = list->head;
    printf("Liste (%d elements): ", list->size);
    while (curr) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

// Mini interface
void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter au debut\n");
    printf("2. Ajouter a la fin\n");
    printf("3. Supprimer une valeur\n");
    printf("4. Modifier une valeur\n");
    printf("5. Trier la liste\n");
    printf("6. Inserer dans l'ordre\n");
    printf("7. Afficher la liste\n");
    printf("8. Taille de la liste\n");
    printf("0. Quitter\n");
    printf("Choix: ");
}

int main() {
    List* list = create_list();
    int choix, val, val2;
    while (1) {
        menu();
        if (scanf("%d", &choix) != 1) break;
        switch (choix) {
            case 1:
                printf("Valeur a ajouter au debut: ");
                if (scanf("%d", &val) == 1)
                    add_front(list, val);
                break;
            case 2:
                printf("Valeur a ajouter a la fin: ");
                if (scanf("%d", &val) == 1)
                    add_back(list, val);
                break;
            case 3:
                printf("Valeur a supprimer: ");
                if (scanf("%d", &val) == 1)
                    if (!remove_value(list, val))
                        printf("Valeur non trouvee.\n");
                break;
            case 4:
                printf("Ancienne valeur: ");
                if (scanf("%d", &val) == 1) {
                    printf("Nouvelle valeur: ");
                    if (scanf("%d", &val2) == 1)
                        if (!modify_value(list, val, val2))
                            printf("Valeur non trouvee.\n");
                }
                break;
            case 5:
                sort_list(list);
                printf("Liste triee.\n");
                break;
            case 6:
                printf("Valeur a inserer dans l'ordre: ");
                if (scanf("%d", &val) == 1)
                    insert_sorted(list, val);
                break;
            case 7:
                print_list(list);
                break;
            case 8:
                printf("Taille de la liste: %d\n", list_size(list));
                break;
            case 0:
                free_list(list);
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    }
    free_list(list);
    return 0;
}