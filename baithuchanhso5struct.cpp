#include<stdio.h>
#include<string.h>

// Khai b�o c?u tr�c Student
typedef struct {
  char name[50]; // T�n sinh vi�n
  int id; // M? s? sinh vi�n
  float gpa; // �i?m trung b?nh
} Student;

// H�m nh?p th�ng tin sinh vi�n t? b�n ph�m
void inputStudent(Student *s) {
  printf("Nhap ten sinh vien: ");
  scanf("%s", s->name);
  printf("Nhap ma so sinh vien: ");
  scanf("%d", &s->id);
  printf("Nhap diem trung binh: ");
  scanf("%f", &s->gpa);
}

// H�m hi?n th? th�ng tin sinh vi�n ra m�n h?nh
void displayStudent(Student s) {
  printf("Ten sinh vien: %s\n", s.name);
  printf("Ma so sinh vien: %d\n", s.id);
  printf("Diem trung binh: %.2f\n", s.gpa);
}

// H�m c?p nh?t th�ng tin sinh vi�n theo m? s?
void updateStudent(Student *arr, int n, int id) {
  // T?m ki?m sinh vi�n c� m? s? tr�ng v?i id
  for (int i = 0; i < n; i++) {
    if (arr[i].id == id) {
      // Nh?p th�ng tin m?i cho sinh vi�n
      printf("Nhap thong tin moi cho sinh vien co ma so %d\n", id);
      inputStudent(&arr[i]);
      return;
    }
  }
  // N?u kh�ng t?m th?y sinh vi�n c� m? s? tr�ng v?i id
  printf("Khong tim thay sinh vien co ma so %d\n", id);
}

// H�m kh?i t?o danh s�ch sinh vi�n
void initStudent(Student *arr, int n) {
  // Nh?p th�ng tin cho t?ng sinh vi�n
  for (int i = 0; i < n; i++) {
    printf("Nhap thong tin cho sinh vien thu %d\n", i + 1);
    inputStudent(&arr[i]);
  }
}

// H�m th�m m?t sinh vi�n v�o danh s�ch
void addStudent(Student *arr, int *n) {
  // Ki?m tra xem danh s�ch c� �?y kh�ng
  if (*n == 50) {
    printf("Danh sach da day, khong the them moi\n");
    return;
  }
  // Nh?p th�ng tin cho sinh vi�n m?i
  printf("Nhap thong tin cho sinh vien moi\n");
  inputStudent(&arr[*n]);
  // T�ng s? l�?ng sinh vi�n l�n 1
  (*n)++;
}

// H�m s?p x?p danh s�ch sinh vi�n theo �i?m trung b?nh gi?m d?n
void sortStudent(Student *arr, int n) {
  // S? d?ng thu?t to�n s?p x?p ch?n
  for (int i = 0; i < n - 1; i++) {
    // T?m v? tr� c?a sinh vi�n c� �i?m trung b?nh cao nh?t t? i �?n n - 1
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j].gpa > arr[max].gpa) {
        max = j;
      }
    }
    // �?i ch? sinh vi�n t?i v? tr� i v� v? tr� max
    Student temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
  }
}

// H�m t?m ki?m sinh vi�n theo t�n
void searchStudent(Student *arr, int n, char *name) {
  // Duy?t qua danh s�ch sinh vi�n
  for (int i = 0; i < n; i++) {
    // So s�nh t�n c?a sinh vi�n v?i t�n c?n t?m
    if (strcmp(arr[i].name, name) == 0) {
      // Hi?n th? th�ng tin c?a sinh vi�n t?m th?y
      displayStudent(arr[i]);
      return;
    }
  }
  // N?u kh�ng t?m th?y sinh vi�n c� t�n tr�ng v?i name
  printf("Khong tim thay sinh vien co ten %s\n", name);
}

// H�m ch�nh
int main() {
  // T?o m?t m?ng c�c c?u tr�c Student
  Student students[50];
  // Khai b�o bi?n l?a ch?n v� s? l�?ng sinh vi�n
  int choice = 0;
  int n = 0;
  do {
    // Hi?n th? menu ch?c n�ng
    printf("CHUONG TRINH QUAN LI SINH VIEN\n");
    printf("1.Khoi tao danh sach:\n");
    printf("2.Them moi 1 sinh vien:\n");
    printf("3.Sua thong tin sinh vien:\n");
    printf("4.Sap xep danh sach\n");
    printf("5.Tim kiem thong tin sinh vien\n");
    printf("0.Thoat chuong trinh\n");
    printf("Lua chon cua ban la :");
    // Nh?p l?a ch?n t? b�n ph�m
    scanf("%d", &choice);
    // X? l? theo l?a ch?n
    switch (choice) {
      case 1:
        // Nh?p s? l�?ng sinh vi�n
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
        // Kh?i t?o danh s�ch sinh vi�n
        initStudent(students, n);
        break;
      case 2:
        // Th�m m?t sinh vi�n v�o danh s�ch
        addStudent(students, &n);
        break;
      case 3:
        // Nh?p m? s? sinh vi�n c?n c?p nh?t
        int id;
        printf("Nhap ma so sinh vien can cap nhat: ");
        scanf("%d", &id);
        // C?p nh?t th�ng tin sinh vi�n theo m? s?
        updateStudent(students, n, id);
        break;
      case 4:
        // S?p x?p danh s�ch sinh vi�n theo �i?m trung b?nh gi?m d?n
        sortStudent(students, n);
        // Hi?n th? danh s�ch sinh vi�n sau khi s?p x?p
        printf("Danh sach sinh vien sau khi sap xep:\n");
        for (int i = 0; i < n; i++) {
          displayStudent(students[i]);
        }
        break;
      case 5:
        // Nh?p t�n sinh vi�n c?n t?m ki?m
        char name[50];
        printf("Nhap ten sinh vien can tim kiem: ");
        scanf("%s", name);
        // T?m ki?m sinh vi�n theo t�n
        searchStudent(students, n, name);
        break;
      case 0:
        // Tho�t ch��ng tr?nh
        printf("Cam on ban da su dung chuong trinh\n");
        break;
      default:
        // L?a ch?n kh�ng h?p l?
        printf("Lua chon khong hop le, vui long nhap lai\n");
        break;
    }
  } while (choice != 0);

  return 0;
}
 
 

