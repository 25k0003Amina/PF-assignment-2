#include <stdio.h>

int main() {
    int isbn[100], qty[100], count = 0;
    char title[100][50];
    float price[100];
    int choice;
    
    while(1) {
        printf("\n1.Add \n2. Sell \n3.LowStock \n4. Exit\n Your Choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) { 
            printf("ISBN: ");
            scanf("%d", &isbn[count]);
            printf("Title: ");
            scanf(" %[^\n]", title[count]);
            printf("Price: ");
            scanf("%f", &price[count]);
            printf("Quantity: ");
            scanf("%d", &qty[count]);
            count++;
            printf("Book Added!\n");
        }
        else if(choice == 2) {  
            int id, q;
            printf("ISBN: ");
            scanf("%d", &id);
            printf("Copies: ");
            scanf("%d", &q);
            
            for(int i = 0; i < count; i++) {
                if(isbn[i] == id) {
                    if(qty[i] >= q) {
                        qty[i] -= q;
                        printf("Sold! Remaining: %d\n", qty[i]);
                    } else {
                        printf("Not enough!\n");
                    }
                    break;
                }
            }
        }
        else if(choice == 3) {
            printf("\n---Low Stock---\n");
            for(int i = 0; i < count; i++) {
                if(qty[i] < 5) {
                    printf("%d | %s | %f | %d\n", isbn[i], title[i], price[i], qty[i]);
                }
            }
        }
        else if(choice == 4) break;
    }
    return 0;
	} 
