#include <stdio.h>

int main() {
    int grid[3][3] = {0};
    int choice, r, c;
    
    while(1) {
        printf("\n1.Update \n2.Check \n3.Diag \n4.Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {  
            int bit, val;
            printf("Row Col: ");
            scanf("%d %d", &r, &c);
            printf("Bit(0,1,2): ");
            scanf("%d", &bit);
            printf("Set(1) Clear(0): ");
            scanf("%d", &val);
            
            if(val == 1)
                grid[r][c] = grid[r][c] | (1 << bit);
            else
                grid[r][c] = grid[r][c] & ~(1 << bit);
            printf("Done!\n");
        }
        else if(choice == 2) {  
            printf("Row Col: ");
            scanf("%d %d", &r, &c);
            int s = grid[r][c];
            printf("Power: %s\n", (s & 1) ? "ON" : "OFF");
            printf("Overload: %s\n", (s & 2) ? "YES" : "NO");
            printf("Maintenance: %s\n", (s & 4) ? "YES" : "NO");
        }
        else if(choice == 3) {  
            int over = 0, maint = 0;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(grid[i][j] & 2) over++;
                    if(grid[i][j] & 4) maint++;
                }
            }
            printf("Overload: %d \n Maintenance: %d\n", over, maint);
        }
        else if(choice == 4) break;
    }
    return 0;
}
