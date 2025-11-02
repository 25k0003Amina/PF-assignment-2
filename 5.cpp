#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len/2; i++) {
        char temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
}
void toggle(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = s[i] ^ 18;  
    }
}
void encode(char msg[]) {
    reverse(msg);
    toggle(msg);
    printf("Encoded: %s\n", msg);
}
void decode(char msg[]) {
    toggle(msg);
    reverse(msg);
    printf("Decoded: %s\n", msg);
}
int main() {
    int choice;
    char msg[200];
    
    printf("TCS Encoder/Decoder\n");
    
    while(1) {
        printf("\n1. Encode\n2. Decode\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        
        if(choice == 3) break;
        
        printf("Enter your message: ");
        fgets(msg, 200, stdin);
        msg[strcspn(msg, "\n")] = 0;
        
        if(choice == 1) encode(msg);
        else if(choice == 2) decode(msg);
        else printf("Wrong choice!\n");
    }
    
    return 0;
}
