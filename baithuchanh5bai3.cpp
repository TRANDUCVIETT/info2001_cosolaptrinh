#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Employee {
    int id; 
    char name[50]; 
    char position[50]; 
    double salary; 
} Employee;


Employee *employees = NULL; 
int size = 0;
int capacity = 0; 


void addEmployee(int id, char *name, char *position, double salary) {
    
    if (size == capacity) {
       
        capacity = capacity == 0 ? 1 : capacity * 2;
      
        employees = (Employee *)realloc(employees, capacity * sizeof(Employee));
    }
    
    employees[size].id = id;
    strcpy(employees[size].name, name);
    strcpy(employees[size].position, position);
    employees[size].salary = salary;
    
    size++;
}


void deleteEmployee(int id) {
   
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (employees[i].id == id) {
            index = i;
            break;
        }
    }
   
    if (index == -1) {
        printf("Khong tim thay nhan vien co ma %d\n", id);
        return;
    }
    
    for (int i = index; i < size - 1; i++) {
        employees[i] = employees[i + 1];
    }
   
    size--;
}

void displayEmployees() {
  
    printf("%-10s%-20s%-20s%-10s\n", "Ma NV", "Ten", "Chuc vu", "Luong");
   
    for (int i = 0; i < size; i++) {
        printf("%-10d%-20s%-20s%-10.2f\n", employees[i].id, employees[i].name, employees[i].position, employees[i].salary);
    }
}


void sortEmployeesBySalary() {
   
    for (int i = 0; i < size - 1; i++) {
      
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (employees[j].salary > employees[maxIndex].salary) {
                maxIndex = j;
            }
        }

        Employee temp = employees[i];
        employees[i] = employees[maxIndex];
        employees[maxIndex] = temp;
    }
}


int main() {
    
    addEmployee(1, " Tran Duc Viet ", "Giam doc", 5000);
    addEmployee(2, " Nguyen Dinh Ha Vy ", "Pho giam doc", 4000);
    addEmployee(3, " Le Thanh Dat ", "Nhan vien", 2000);
    addEmployee(4, " Pham Thi Trang ", "Nhan vien", 2500);
    addEmployee(5, " Que Hai Duc ", "Nhan vien", 3000);

    
    printf("Danh sach nhan vien:\n");
    displayEmployees();

  
    printf("Xoa nhan vien co ma 3:\n");
    deleteEmployee(3);


    printf("Danh sach nhan vien sau khi xoa:\n");
    displayEmployees();

 
    printf("Sap xep nhan vien theo luong giam dan:\n");
    sortEmployeesBySalary();


    printf("Danh sach nhan vien sau khi sap xep:\n");
    displayEmployees();

   
    free(employees);

    return 0;
}

