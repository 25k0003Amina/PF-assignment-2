#include <stdio.h>
#include <string.h>

int main() {
    int code[4] = {1,2,3,4}, stock[4] = {50,10,20,8};
    float price[4] = {100,200,300,150};
    int cart[10], cartQ[10], items = 0;
    char name[50], cnic[20];
    int choice;
    
    while(1) {
        printf("\n1.Info \n2.Show \n3.Cart \n4.Bill \n5.Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1) { 
            printf("Name: ");
            scanf(" %[^\n]", name);
            printf("CNIC: ");
            scanf("%s", cnic);
        }
        else if(choice == 2) {  
            for(int i = 0; i < 4; i++)
                printf("%d | %d | %f\n", code[i], stock[i], price[i]);
        }
        else if(choice == 3) {  
            int c, q;
            printf("Code: ");
            scanf("%d", &c);
            printf("Qty: ");
            scanf("%d", &q);
            
            for(int i = 0; i < 4; i++) {
                if(code[i] == c && stock[i] >= q) {
                    cart[items] = c;
                    cartQ[items] = q;
                    items++;
                    stock[i] -= q;
                    printf("Added!\n");
                    break;
                }
            }
        }
        else if(choice == 4) {  
            float total = 0;
            printf("\n---Bill---\n");
            for(int i = 0; i < items; i++) {
                for(int j = 0; j < 4; j++) {
                    if(code[j] == cart[i]) {
                        float t = price[j] * cartQ[i];
                        printf("%d x%d = %.0f\n", cart[i], cartQ[i], t);
                        total += t;
                    }
                }
            }
            printf("Total: %.0f\n", total);
            
            char promo[20];
            printf("Promo: ");
            scanf("%s", promo);
            if(strcmp(promo, "Eid2025") == 0) {
                printf("Final: %.0f (25%% off)\n", total * 0.75);
            }
        }
        else if(choice == 5) break;
    }
    return 0;
}
