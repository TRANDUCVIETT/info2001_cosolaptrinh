#include<stdio.h>
#include<string.h>

// Khai báo c?u trúc Student
typedef struct {
  char name[50]; // Tên sinh viên
  int id; // M? s? sinh viên
  float gpa; // Ði?m trung b?nh
} Student;

// Hàm nh?p thông tin sinh viên t? bàn phím
void inputStudent(Student *s) {
  printf("Nhap ten sinh vien: ");
  scanf("%s", s->name);
  printf("Nhap ma so sinh vien: ");
  scanf("%d", &s->id);
  printf("Nhap diem trung binh: ");
  scanf("%f", &s->gpa);
}

// Hàm hi?n th? thông tin sinh viên ra màn h?nh
void displayStudent(Student s) {
  printf("Ten sinh vien: %s\n", s.name);
  printf("Ma so sinh vien: %d\n", s.id);
  printf("Diem trung binh: %.2f\n", s.gpa);
}

// Hàm c?p nh?t thông tin sinh viên theo m? s?
void updateStudent(Student *arr, int n, int id) {
  // T?m ki?m sinh viên có m? s? trùng v?i id
  for (int i = 0; i < n; i++) {
    if (arr[i].id == id) {
      // Nh?p thông tin m?i cho sinh viên
      printf("Nhap thong tin moi cho sinh vien co ma so %d\n", id);
      inputStudent(&arr[i]);
      return;
    }
  }
  // N?u không t?m th?y sinh viên có m? s? trùng v?i id
  printf("Khong tim thay sinh vien co ma so %d\n", id);
}

// Hàm kh?i t?o danh sách sinh viên
void initStudent(Student *arr, int n) {
  // Nh?p thông tin cho t?ng sinh viên
  for (int i = 0; i < n; i++) {
    printf("Nhap thong tin cho sinh vien thu %d\n", i + 1);
    inputStudent(&arr[i]);
  }
}

// Hàm thêm m?t sinh viên vào danh sách
void addStudent(Student *arr, int *n) {
  // Ki?m tra xem danh sách có ð?y không
  if (*n == 50) {
    printf("Danh sach da day, khong the them moi\n");
    return;
  }
  // Nh?p thông tin cho sinh viên m?i
  printf("Nhap thong tin cho sinh vien moi\n");
  inputStudent(&arr[*n]);
  // Tãng s? lý?ng sinh viên lên 1
  (*n)++;
}

// Hàm s?p x?p danh sách sinh viên theo ði?m trung b?nh gi?m d?n
void sortStudent(Student *arr, int n) {
  // S? d?ng thu?t toán s?p x?p ch?n
  for (int i = 0; i < n - 1; i++) {
    // T?m v? trí c?a sinh viên có ði?m trung b?nh cao nh?t t? i ð?n n - 1
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j].gpa > arr[max].gpa) {
        max = j;
      }
    }
    // Ð?i ch? sinh viên t?i v? trí i và v? trí max
    Student temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
  }
}

// Hàm t?m ki?m sinh viên theo tên
void searchStudent(Student *arr, int n, char *name) {
  // Duy?t qua danh sách sinh viên
  for (int i = 0; i < n; i++) {
    // So sánh tên c?a sinh viên v?i tên c?n t?m
    if (strcmp(arr[i].name, name) == 0) {
      // Hi?n th? thông tin c?a sinh viên t?m th?y
      displayStudent(arr[i]);
      return;
    }
  }
  // N?u không t?m th?y sinh viên có tên trùng v?i name
  printf("Khong tim thay sinh vien co ten %s\n", name);
}

// Hàm chính
int main() {
  // T?o m?t m?ng các c?u trúc Student
  Student students[50];
  // Khai báo bi?n l?a ch?n và s? lý?ng sinh viên
  int choice = 0;
  int n = 0;
  do {
    // Hi?n th? menu ch?c nãng
    printf("CHUONG TRINH QUAN LI SINH VIEN\n");
    printf("1.Khoi tao danh sach:\n");
    printf("2.Them moi 1 sinh vien:\n");
    printf("3.Sua thong tin sinh vien:\n");
    printf("4.Sap xep danh sach\n");
    printf("5.Tim kiem thong tin sinh vien\n");
    printf("0.Thoat chuong trinh\n");
    printf("Lua chon cua ban la :");
    // Nh?p l?a ch?n t? bàn phím
    scanf("%d", &choice);
    // X? l? theo l?a ch?n
    switch (choice) {
      case 1:
        // Nh?p s? lý?ng sinh viên
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
        // Kh?i t?o danh sách sinh viên
        initStudent(students, n);
        break;
      case 2:
        // Thêm m?t sinh viên vào danh sách
        addStudent(students, &n);
        break;
      case 3:
        // Nh?p m? s? sinh viên c?n c?p nh?t
        int id;
        printf("Nhap ma so sinh vien can cap nhat: ");
        scanf("%d", &id);
        // C?p nh?t thông tin sinh viên theo m? s?
        updateStudent(students, n, id);
        break;
      case 4:
        // S?p x?p danh sách sinh viên theo ði?m trung b?nh gi?m d?n
        sortStudent(students, n);
        // Hi?n th? danh sách sinh viên sau khi s?p x?p
        printf("Danh sach sinh vien sau khi sap xep:\n");
        for (int i = 0; i < n; i++) {
          displayStudent(students[i]);
        }
        break;
      case 5:
        // Nh?p tên sinh viên c?n t?m ki?m
        char name[50];
        printf("Nhap ten sinh vien can tim kiem: ");
        scanf("%s", name);
        // T?m ki?m sinh viên theo tên
        searchStudent(students, n, name);
        break;
      case 0:
        // Thoát chýõng tr?nh
        printf("Cam on ban da su dung chuong trinh\n");
        break;
      default:
        // L?a ch?n không h?p l?
        printf("Lua chon khong hop le, vui long nhap lai\n");
        break;
    }
  } while (choice != 0);

  return 0;
}
 
 

