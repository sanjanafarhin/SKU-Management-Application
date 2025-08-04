#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define SIZE 30

typedef struct {
    char name[30];
    char category[30];
    float price;
    int quantity;
} Product;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void trimNewline(char* str) {
    str[strcspn(str, "\n")] = '\0';
}

void Title() {
    system("COLOR 0F");
    printf("\t\t SKU Management System\n");
}

void addProduct() {
    system("cls");
    Title();

    Product p;
    printf("\nName : ");
    fgets(p.name, sizeof(p.name), stdin);
    trimNewline(p.name);

    printf("Category : ");
    fgets(p.category, sizeof(p.category), stdin);
    trimNewline(p.category);

    printf("Price : ");
    scanf("%f", &p.price);
    printf("Stock Count : ");
    scanf("%d", &p.quantity);
    clearInputBuffer();

    FILE *file = fopen("ProductList.txt", "a");
    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    fprintf(file, "%s-%s-%.2f-%d\n", p.name, p.category, p.price, p.quantity);
    fclose(file);

    printf("\nInformation added successfully");
    for (int i = 0; i < 5; i++) {
        printf(".");
        Sleep(300);
    }
}

void display() {
    system("cls");
    Title();

    char name[30], category[30];
    float price;
    int quantity;

    FILE *file = fopen("ProductList.txt", "r");
    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    printf("\n%-20s %-20s %-10s %-10s\n", "Product Name", "Category", "Price", "Stock");
    printf("---------------------------------------------------------------\n");

    while (fscanf(file, "%[^-]-%[^-]-%f-%d\n", name, category, &price, &quantity) == 4) {
        printf("%-20s %-20s %-10.2f %-10d\n", name, category, price, quantity);
        Sleep(200);
    }

    fclose(file);
    Sleep(3000);
}

void searchProduct() {
    system("cls");
    Title();

    char search[30], name[30], category[30];
    float price;
    int quantity, found = 0;

    printf("Enter product name: ");
    fgets(search, sizeof(search), stdin);
    trimNewline(search);

    FILE *file = fopen("ProductList.txt", "r");
    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    while (fscanf(file, "%[^-]-%[^-]-%f-%d\n", name, category, &price, &quantity) == 4) {
        if (strcmp(search, name) == 0) {
            printf("\nName: %s\nCategory: %s\nPrice: %.2f\nStock: %d\n", name, category, price, quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.");
    }

    fclose(file);
    Sleep(3000);
}

void editProduct() {
    system("cls");
    Title();

    char search[30], name[30], category[30];
    float price, uprice;
    int quantity, uquantity, found = 0;

    printf("Enter product name to edit: ");
    fgets(search, sizeof(search), stdin);
    trimNewline(search);

    FILE *file = fopen("ProductList.txt", "r");
    FILE *temp = fopen("Temp.txt", "w");

    if (file == NULL || temp == NULL) {
        perror("File opening failed");
        return;
    }

    while (fscanf(file, "%[^-]-%[^-]-%f-%d\n", name, category, &price, &quantity) == 4) {
        if (strcmp(search, name) == 0) {
            printf("New Price: ");
            scanf("%f", &uprice);
            printf("New Quantity: ");
            scanf("%d", &uquantity);
            clearInputBuffer();

            fprintf(temp, "%s-%s-%.2f-%d\n", name, category, uprice, uquantity);
            found = 1;
        } else {
            fprintf(temp, "%s-%s-%.2f-%d\n", name, category, price, quantity);
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("ProductList.txt");
        rename("Temp.txt", "ProductList.txt");
        printf("\nProduct updated successfully.");
    } else {
        remove("Temp.txt");
        printf("\nProduct not found.");
    }

    Sleep(3000);
}

void deleteProduct() {
    system("cls");
    Title();

    char search[30], name[30], category[30];
    float price;
    int quantity, found = 0;

    printf("Enter product name to delete: ");
    fgets(search, sizeof(search), stdin);
    trimNewline(search);

    FILE *file = fopen("ProductList.txt", "r");
    FILE *temp = fopen("Temp.txt", "w");

    if (file == NULL || temp == NULL) {
        perror("File opening failed");
        return;
    }

    while (fscanf(file, "%[^-]-%[^-]-%f-%d\n", name, category, &price, &quantity) == 4) {
        if (strcmp(search, name) == 0) {
            found = 1;
            continue;
        } else {
            fprintf(temp, "%s-%s-%.2f-%d\n", name, category, price, quantity);
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("ProductList.txt");
        rename("Temp.txt", "ProductList.txt");
        printf("\nProduct deleted successfully.");
    } else {
        remove("Temp.txt");
        printf("\nProduct not found.");
    }

    Sleep(3000);
}

void menu() {
    while (1) {
        system("cls");
        Title();
        printf("1. Add Product\n2. Delete Product\n3. Search Product\n4. Edit Product\n5. Display Stock\n6. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: addProduct(); break;
            case 2: deleteProduct(); break;
            case 3: searchProduct(); break;
            case 4: editProduct(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n"); Sleep(1000);
        }
    }
}

void login() {
    system("cls");
    Title();
    printf("\n\tLogin Page\n");

    char username[30], inputUser[30];
    char password[30], inputPass[30];
    int attempts = 3, found;

    FILE *file = fopen("Register.txt", "r");
    if (file == NULL) {
        perror("Error opening Register.txt");
        return;
    }

    while (attempts--) {
        found = 0;
        printf("\nUsername: ");
        fgets(inputUser, sizeof(inputUser), stdin);
        trimNewline(inputUser);

        printf("Password: ");
        fgets(inputPass, sizeof(inputPass), stdin);
        trimNewline(inputPass);

        rewind(file);
        while (fscanf(file, "%[^-]-%[^\n]\n", username, password) == 2) {
            if (strcmp(username, inputUser) == 0 && strcmp(password, inputPass) == 0) {
                printf("\nLogin successful");
                Sleep(1000);
                fclose(file);
                menu();
                return;
            }
        }

        printf("Invalid credentials! %d attempts left.\n", attempts);
    }

    printf("\nLogin Failed!\n");
    fclose(file);
    Sleep(2000);
}

void signUp() {
    system("cls");
    Title();
    printf("\n\tSign Up Page\n");

    char username[30], password[30];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    trimNewline(username);

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    trimNewline(password);

    FILE *file = fopen("Register.txt", "a");
    if (file == NULL) {
        perror("Error opening Register.txt");
        return;
    }

    fprintf(file, "%s-%s\n", username, password);
    fclose(file);

    printf("\nSign up successful!\n");
    Sleep(1000);
}

int main() {
    while (1) {
        system("cls");
        Title();
        printf("1. Login\n2. Sign Up\n3. Exit\n");
        int choice;

        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: login(); break;
            case 2: signUp(); break;
            case 3: exit(0);
            default: printf("Invalid option\n"); Sleep(1000);
        }
    }
}
