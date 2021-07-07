#include <stdio.h>
#include <stdlib.h>
#include "the3.h"

Apartment* create_street(){
    Apartment *head, *temp;
    Flat *f_temp;
    char x;
    int i, j, apartment_count, flat_count;
    scanf("%d", &apartment_count);
    if(!apartment_count){
        head = NULL;
    }
    for(i = 0; i < apartment_count; i++){
        if(!i){
            temp = (Apartment*) malloc(sizeof(Apartment));
            head = temp;
        
            scanf(" %c", &x);
            temp -> name = (char*) malloc(sizeof(char));
            *(temp -> name) = x;
            scanf("%d", &(temp -> max_bandwidth));
            scanf("%d", &flat_count);
            if(!flat_count){
                temp -> flat_list = NULL;
            }
            for(j = 0; j < flat_count; j++){
                if(!j){
                    temp -> flat_list = (Flat*) malloc(sizeof(Flat));
                    f_temp = temp -> flat_list;
                    scanf("%d", &(f_temp -> id));
                    scanf("%d", &f_temp -> initial_bandwidth);
                    f_temp -> is_empty = 0;
                    f_temp -> prev = NULL;
                    continue;
                }
                if(j == (flat_count - 1)){
                    f_temp -> next = (Flat*) malloc(sizeof(Flat));
                    scanf("%d", &(f_temp -> next) -> id);
                    scanf("%d", &(f_temp -> next) -> initial_bandwidth);
                    (f_temp -> next) -> is_empty = 0;
                    (f_temp -> next) -> prev = f_temp;
                    f_temp = f_temp -> next;
                    f_temp -> next = NULL;
                    break;         
                }
                f_temp -> next = (Flat*) malloc(sizeof(Flat));
                scanf("%d", &(f_temp -> next) -> id);
                scanf("%d", &(f_temp -> next) -> initial_bandwidth);
                (f_temp -> next) -> is_empty = 0;
                (f_temp -> next) -> prev = f_temp;
                f_temp = f_temp -> next;
            }
            if(apartment_count == 1){
                temp -> next = head;
                break;
            }
            else{
                temp -> next = (Apartment*) malloc(sizeof(Apartment));
                temp = temp -> next;
            }
        }
        else{
            scanf(" %c", &x);
            (temp) -> name = (char*) malloc(sizeof(char));
            *(temp -> name) = x;
            scanf("%d", &((temp) -> max_bandwidth));
            scanf("%d", &flat_count);
            if(!flat_count){
                temp -> flat_list = NULL;
            }
            for(j = 0; j < (flat_count); j++){
                if(!j){
                    (temp) -> flat_list = (Flat*) malloc(sizeof(Flat));
                    f_temp = (temp) -> flat_list;
                    scanf("%d", &f_temp -> id);
                    scanf("%d", &f_temp -> initial_bandwidth);
                    f_temp -> is_empty = 0;
                    f_temp -> prev = NULL;
                    continue;
                }
                if(j == (flat_count - 1)){
                    f_temp -> next = (Flat*) malloc(sizeof(Flat));
                    scanf("%d", &(f_temp -> next) -> id);
                    scanf("%d", &(f_temp -> next) -> initial_bandwidth);
                    (f_temp -> next) -> is_empty = 0;
                    (f_temp -> next) -> prev = f_temp;
                    f_temp = f_temp -> next;
                    f_temp -> next = NULL;
                    break;                  
                }
                f_temp -> next = (Flat*) malloc(sizeof(Flat));
                scanf("%d", &(f_temp -> next) -> id);
                scanf("%d", &(f_temp -> next) -> initial_bandwidth);
                (f_temp -> next) -> is_empty = 0;
                (f_temp -> next) -> prev = f_temp;
                f_temp = f_temp -> next;
            }
            if(i == (apartment_count - 1)){
                temp -> next = head;
            }
            else{
                temp -> next = (Apartment*) malloc(sizeof(Apartment));
                temp = temp -> next;
            }
        }
    }

    return head;
}

void print_street(Apartment *head){
    Apartment *temp;
    Flat *f_temp;

    temp = head;
    while(head){
        printf("\nApartment Name: %s, Max Bandwidth: %d\n", temp -> name, temp -> max_bandwidth);
        f_temp = temp -> flat_list;
        while(f_temp){
            printf("(id: %d, initial_bandwith: %d, is_empty: %d) ", f_temp -> id, f_temp -> initial_bandwidth, f_temp -> is_empty);
            if(f_temp -> next ==  NULL){
                printf("\nbackwards\n");
                while(f_temp){
                    printf("(id: %d, initial_bandwith: %d, is_empty: %d)", f_temp -> id, f_temp -> initial_bandwidth, f_temp -> is_empty);
                    f_temp = f_temp -> prev;
                }
                printf("\n");
                break;
            }
            f_temp = f_temp -> next;
        }
        if(temp -> next == head){
            break;
        }
        temp = temp -> next;
    }
}

int main(){
    Apartment* head, *temp;
    char *name = "New Apartment";
    char *ch, *ch2;
    int index, i, id, mm, id_list[60] = {0}, function;

    scanf("%d", &function);
    head = create_street();
    ch = (char*) malloc(12*sizeof(char));
    ch2 = (char*) malloc(12*sizeof(char));
    ch[11] = '\0';
    ch2[11] = '\0';

    switch (function){
        case 1:

            scanf("%d", &index);
            temp = add_apartment(head, index, name, 300);
            print_street(temp);
            break;

        case 2:
            scanf(" %c", ch);
            scanf("%d", &index);
            scanf("%d", &id);
            scanf("%d", &mm);
            add_flat(head, ch, index, id, mm);
            print_street(head);
            break;

        case 3:
            scanf(" %c", ch);
            temp = remove_apartment(head, ch);
            print_street(temp);
            break;

        case 4:
            scanf(" %c", ch);
            scanf("%d", &id);
            make_flat_empty(head, ch, id);
            print_street(head);
            break;

        case 5:
            printf("%d\n",find_sum_of_max_bandwidths(head));
            break;

        case 6:
            scanf(" %c", ch);
            scanf(" %c", ch2);
            temp = merge_two_apartments(head, ch, ch2);
            print_street(temp);
            break;

        case 7:    
            scanf(" %c", ch);
            scanf("%d", &mm);
            scanf("%d", &index);
            for(i = 0; i < index; i++){
                scanf("%d", &(id_list[i]));
            }
            relocate_flats_to_same_apartment(head, ch, mm, id_list);
            print_street(head);
            break;
    }
    return 0;
}
