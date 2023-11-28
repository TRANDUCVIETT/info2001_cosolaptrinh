#include <stdio.h>
#include <string.h>


typedef struct {
    int id; 
    char name[50]; 
    float score; 
} Student;


void input(Student sv[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Nhap ma sinh vien: ");
        scanf("%d", &sv[i].id);
        printf("Nhap ten sinh vien: ");
        scanf("%s", sv[i].name);
        printf("Nhap diem so: ");
        scanf("%f", &sv[i].score);
    }
}


void output(Student sv[], int n) {
    printf("Danh sach sinh vien:\n");
    printf("%-10s%-20s%-10s\n", "Ma SV", "Ten SV", "Diem so");
    for (int i = 0; i < n; i++) {
        printf("%-10d%-20s%-10.2f\n", sv[i].id, sv[i].name, sv[i].score);
    }
}


void sortByName(Student sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
          
            if (strcmp(sv[i].name, sv[j].name) > 0) {
                
                Student temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}


void sortByScore(Student sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (sv[i].score > sv[j].score) {
                
                Student temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}


void searchByName(Student sv[], int n, char name[]) {
    int found = 0; // Bi?n ðánh d?u có t?m th?y sinh viên hay không
    printf("Danh sach sinh vien co ten %s:\n", name);
    printf("%-10s%-20s%-10s\n", "Ma SV", "Ten SV", "Diem so");
    for (int i = 0; i < n; i++) {
       
        if (strcmp(sv[i].name, name) == 0) {
           
            printf("%-10d%-20s%-10.2f\n", sv[i].id, sv[i].name, sv[i].score);
            found = 1; // Ðánh d?u ð? t?m th?y sinh viên
        }
    }
    if (found == 0) {
        
        printf("Khong co sinh vien nao co ten %s.\n", name);
    }
}


void searchById(Student sv[], int n, int id) {
    int found = 0;
    printf("Danh sach sinh vien co ma %d:\n", id);
    printf("%-10s%-20s%-10s\n", "Ma SV", "Ten SV", "Diem so");
    for (int i = 0; i < n; i++) {
        
        if (sv[i].id == id) {
           
            printf("%-10d%-20s%-10.2f\n", sv[i].id, sv[i].name, sv[i].score);
            found = 1;
        }
    }
    if (found == 0) {
        
        printf("Khong co sinh vien nao co ma %d.\n", id);
    }
}


void menu() {
    printf("Chuong trinh quan ly sinh vien\n");
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Sap xep sinh vien theo ten\n");
    printf("4. Sap xep sinh vien theo diem so\n");
    printf("5. Tim kiem sinh vien theo ten\n");
    printf("6. Tim kiem sinh vien theo ma\n");
    printf("0. Thoat chuong trinh\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    Student sv[100];
    int n = 0;
    int choice; 
    char name[50]; 
    int id; 
    do {
       
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                
                input(sv, n);
                break;
            case 2:
               
                output(sv, n);
                break;
            case 3:
               
                sortByName(sv, n);
                printf("Da sap xep sinh vien theo ten.\n");
                break;
            case 4:
               
                sortByScore(sv, n);
                printf("Da sap xep sinh vien theo diem so.\n");
                break;
            case 5:
              
                printf("Nhap ten can tim: ");
                scanf("%s", name);
               
                searchByName(sv, n, name);
                break;
            case 6:
               
                printf("Nhap ma can tim: ");
                scanf("%d", &id);
                
                searchById(sv, n, id);
                break;
            case 0:
               
                printf("Cam on ban da su dung chuong trinh.\n");
                break;
            default:
               
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 0); 
    return 0;
}

