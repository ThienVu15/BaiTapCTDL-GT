#include<iostream>
using namespace std;

// Khai bao cau truc cua danh sach lien ket
struct file {
    long long size;
    string addr;
    string name;
    long long time; // Bieu thi thoi gian tao file theo kieu long long 
    file* next;
};

// Khai bao o nho D chua danh sach file, dung dau la head
struct listD {
    file* head;
};

// Khoi tao gia tri cua nut dau tien = NULL
void D_document(listD* list) {
    list->head = NULL;
}

// Copy va chen file
void insertFile(listD* list, long long size, string addr, string name, long long time) {
    // Con tro *head dai dien cho file dau tien trong thu muc
    // Tao mot nut moi de chen du lieu cua file cu sang
    file* newfile = new file;
    newfile->size = size;
    newfile->addr = addr;
    newfile->name = name;
    newfile->time = time;
    newfile->next = NULL;

    // Tao ban sao cua con tro head
    file* head1 = list->head;

    // Truong hop thu muc ban dau rong
    if (list->head == NULL) {
        list->head = newfile;
        return;
    }

    // Truong hop thoi gian cua file chen som hon file dau tien trong thu muc
    // Chen vao dau thu muc
    if (newfile->time < list->head->time) {
        newfile->next = list->head;
        list->head = newfile;
        return;
    }

    // Truong hop con lai, chen vao giua hoac cuoi
    else {
        // Chen o giua
        while (head1->next != NULL) {
            if (newfile->time >= head1->time && newfile->time <= head1->next->time) {
                newfile->next = head1->next;
                head1->next = newfile;
                return;
            }
            head1 = head1->next;
        }
        // Neu khong thoa man o giua thi chen o cuoi
        if (head1->next == NULL) {
            head1->next = newfile;
            newfile->next = NULL;
            return;
        }
    }
}

// Thuc hien tinh toan kich thuoc cac file trong thu muc
long long sum_size(listD* list) {
    long long sum = 0;
    file* tmp = list->head;
    if (tmp == NULL) sum = 0;
    while (tmp != NULL) {
        sum += tmp->size;
        tmp = tmp->next;
    }
    return sum;
}

// Thuc hien loai bo cac file co dung luong tu be den lon den khi bo nho <= 32GB
// Dau tien tao ham swap de doi du lieu giua cac nut
void swap(file* a, file* b) {
    if (a == NULL || b == NULL) return;

    // Hoan doi kich thuoc
    int tempSize = a->size;
    a->size = b->size;
    b->size = tempSize;

    // Hoan doi dia chi
    string tempAddr = a->addr;
    a->addr = b->addr;
    b->addr = tempAddr;

    // Hoan doi ten file
    string tempName = a->name;
    a->name = b->name;
    b->name = tempName;

    // Hoan doi thoi gian
    long long tempTime = a->time;
    a->time = b->time;
    b->time = tempTime;
}

void deletefile(listD* list) {
    const long long size_32GB = 32000; // Bieu thi 32GB bang 32000KB
    // Kiem tra xem o nho co rong khong
    if (list->head == NULL) return;

    // Tien hanh tim cac file co size nho nhat roi loai bo dan
    // Sap xep cac file theo thu tu co size tu nho den lon bang thuat toan selection sort
    for (file* i = list->head; i != NULL; i = i->next) {
        file* min = i;
        for (file* j = i->next; j != NULL; j = j->next) {
            if (min->size > j->size) {
                min = j;
            }
        }
        swap(i, min);
    }

    // Tinh tong dung luong ban dau
    long long sum = sum_size(list);

    // Xoa dan cac file tu dau danh sach den khi tong dung luong <= 32GB
    while (sum > size_32GB && list->head != NULL) {
        file* tmp = list->head;        // Lay file dau tien (dung luong nho nhat sau khi sap xep)
        list->head = list->head->next; // Di chuyen con tro head sang file tiep theo
        sum -= tmp->size;              // Tru dung luong cua file vua xoa khoi tong
        delete tmp;                    // Giai phong bo nho
    }
}

// In danh sach file trong bo nho
void in(listD* list) {
    file* temp = list->head;
    if (temp == NULL) {
        cout << "Khong co file nao ton tai" << endl;
        return;
    }
    cout << "Danh sach file trong bo nho la :" << endl;
    while (temp != NULL) {
        cout << "size : " << temp->size << " | Dia chi : " << temp->addr 
             << " | Ten : " << temp->name << " | Thoi gian : " << temp->time << endl;
        temp = temp->next;
    }
}

int main() {
    listD list;
    D_document(&list);
    insertFile(&list, 100, "D", "Vu", 371);
    insertFile(&list, 200, "D", "Viet", 350);
    insertFile(&list, 300, "D", "Thien", 350);
    insertFile(&list, 400, "D", "ET1", 382);
    insertFile(&list, 600, "D", "06", 399);

    in(&list);
    cout << "Tong dung luong cua o nho la: " << sum_size(&list) << endl;

    deletefile(&list);
    in(&list);
    return 0;
}

