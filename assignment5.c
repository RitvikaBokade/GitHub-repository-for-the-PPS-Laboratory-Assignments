#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int choice, n;
    char str1[100], str2[100], ch, sub[50];
    char *ptr, *token;

    while (1) {
        printf("\n String Operations Menu \n");
        printf("1. Find length (strlen)\n");
        printf("2. Copy string (strcpy)\n");
        printf("3. Concatenate strings (strcat)\n");
        printf("4. Compare strings (strcmp)\n");
        printf("5. Find character (strchr)\n");
        printf("6. Find substring (strstr)\n");
        printf("7. Tokenize string (strtok)\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2); 
                break;

            case 3: // Concatenation 
                printf("Enter first string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter second string: "); 
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0'; 
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1); 
                break;

            case 4: // Comparison
                printf("Enter first string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter second string: "); 
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                {
                    int res = strcmp(str1, str2);
                    if (res == 0) {
                        printf("Strings are equal.\n");
                    } else if (res < 0) {
                        printf("String 1 is lexicographically smaller than String 2.\n");
                    } else {
                        printf("String 1 is lexicographically greater than String 2.\n");
                    }
                }
                break;

            case 5: // Find character (strchr)
                printf("Enter string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter character to find: ");
                scanf("%c", &ch);
                getchar(); 
                ptr = strchr(str1, ch);
                if (ptr != NULL) {
                    printf("Character '%c' found at position %ld (index %ld).\n", 
                           ch, (ptr - str1) + 1, ptr - str1);
                } else {
                    printf("Character '%c' not found in string.\n", ch);
                }
                break;

            case 6: // Find substring (strstr)
                printf("Enter main string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter substring to search: "); 
                fgets(sub, 50, stdin);
                sub[strcspn(sub, "\n")] = '\0';
                ptr = strstr(str1, sub);
                if (ptr != NULL) {
                    printf("Substring \"%s\" found at position %ld (index %ld).\n", 
                           sub, (ptr - str1) + 1, ptr - str1);
                } else {
                    printf("Substring \"%s\" not found.\n", sub);
                }
                break;

            case 7: // Tokenize string (strtok)
                printf("Enter string to tokenize: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter delimiter characters: "); 
                fgets(sub, 50, stdin);
                sub[strcspn(sub, "\n")] = '\0';
                token = strtok(str1, sub);
                n = 1;
                while (token != NULL) {
                    printf("Token %d: %s\n", n++, token);
                    token = strtok(NULL, sub);
                }
                break;

            case 8: // Convert to uppercase
                printf("Enter string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                for (int i = 0; str1[i] != '\0'; i++) {
                    str1[i] = (char)toupper((unsigned char)str1[i]);
                }
                printf("Uppercase string: %s\n", str1);
                break;

            case 9: // Convert to lowercase
                printf("Enter string: "); 
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                for (int i = 0; str1[i] != '\0'; i++) {
                    str1[i] = (char)tolower((unsigned char)str1[i]);
                }
                printf("Lowercase string: %s\n", str1);
                break;

            case 10: 
                printf("Exiting\n"); 
                return 0;

            default: 
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}