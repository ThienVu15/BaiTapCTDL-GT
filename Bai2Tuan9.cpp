#include<iostream>
using namespace std;
// Khai bao cau truc danh sach lien ket tu
struct tu {
    string vol;  // Tu vung
    tu* next;
};
// Khai bao cau truc danh sach lien ket cau la 1 danh sach gom nhieu node tu
struct cau {
    tu* head;
};
// Khoi tao danh sach cau
void khoitaocau(cau* cau) {
    cau->head = NULL;
}
// Them tu vao danh sach lien ket
void them_tu(cau* cau, string vol) {
    tu* newtu = new tu;
    newtu->vol = vol;
    newtu->next = NULL;
    // Neu cau rong thi them vao dau
    if (cau->head == NULL) {
        cau->head = newtu;
    }
    // Them vao sau tu co truoc
	else {
        tu* temp = cau->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newtu;
    }
}
// Tao mot cau truc luu du lieu tu va so lan tu do xuat hien trong cau
struct infor {
    string vol;
    int solan;
    infor* next;
};
// Tao 1 danh sach luu thong tin cua cac tu
struct listinfor {
    infor* head;
};
// Khoi tao danh sach lien ket chua thong tin ve tu
void list_infor(listinfor* listinfor) {
    listinfor->head = NULL;
}
// Kiem tra xem tu da co trong danh sach chua
bool kiemtra_tu(listinfor* list, string vol) {
    infor* temp = list->head;
    while (temp != NULL) {
        if (temp->vol == vol) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Xac dinh tu xuat hien nhieu nhat trong cau
void Tim_tu_xuat_hien_nhieu_nhat(cau* cau, listinfor* listinfor) {
    tu* tu1 = cau->head;
    if (tu1 == NULL) return;
    // Su dung mang de dem so lan xuat hien moi tu
    int cnt[100] = {0}; // Khoi tao mang dem luu duoc 100 tu
    int index = 0; // Khoi tao bien dem
    // Dem tan suat xuat hien cua cac tu
    // Thuat toan:
    // Tao 2 ban sao cua danh sach cau do, duyet tung tu cua danh sach 1 xem co trung voi tung tu cua danh sach 2 
    // Sau khi duyet het danh sach 2, lai chuyen sang node ke tiep cua danh sach 1 roi lai lam tuong tu
    // Moi lan nhu vay thu duoc so lan xuat hien cua moi tu
    while (tu1 != NULL) {
        tu* tu2 = cau->head;
        while (tu2 != NULL) {
            if (tu2->vol == tu1->vol) {
                cnt[index]++;
            }
            tu2 = tu2->next;
        }
        // Kiem tra neu tu chua co trong danh sach
        if (!kiemtra_tu(listinfor, tu1->vol)) {
            // Them tu vao danh sach infor neu chua co
            infor* newinfor = new infor;
            newinfor->vol = tu1->vol;
            newinfor->solan = cnt[index];
            newinfor->next = listinfor->head;
            listinfor->head = newinfor;
        }
        index++;
        tu1 = tu1->next;
    }
    // Tim tu co so lan xuat hien lon nhat
    infor* temp = listinfor->head;
    int max_count = 0;
    while (temp != NULL) {
        if (temp->solan > max_count) {
            max_count = temp->solan;
        }
        temp = temp->next;
    }

    // In ra cac tu co so lan xuat hien nhieu nhat
    temp = listinfor->head;
    cout << "Tu duoc xuat hien nhieu nhat la: ";
    while (temp != NULL) {
        if (temp->solan == max_count) {
            cout << "'" << temp->vol << "'" << " voi so lan la : " << temp->solan << endl;
        }
        temp = temp->next;
    }
}
// Loai bo tu neu xuat hien tu lay
void loai_bo_tu_lay(cau* cau) {
    if (cau->head == NULL || cau->head->next == NULL) return;
    tu* tu1 = cau->head;
    while (tu1 != NULL && tu1->next != NULL) {
        // Kiem tra neu node hien tai tro toi chinh no
        if (tu1->next->vol == tu1->vol) {
            tu* temp = tu1->next;
            tu1->next = temp->next;  // Bo qua node lap
            delete temp;
        } else {
            tu1 = tu1->next;  // Chuyen sang node tiep theo
        }
    }

    // In danh sach sau khi xu ly
    tu* temp = cau->head;
    cout<<"Cau sau khi loai bo tu lay la :";
    while (temp != NULL) {
        cout <<temp->vol << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Dem so tu xuat hien trong cau
void dem_so_tu_xuat_hien_trong_cau(cau* cau){
	int sotu = 0;
	tu* temp = cau->head;
	while(temp != NULL){
		sotu++;
		temp = temp->next;
	}
	cout<<"So tu xuat hien trong cau la : "<<sotu<<endl;
}
int main() {
    cau cau1;
    khoitaocau(&cau1);
    // Them cac tu vao danh sach cau
    them_tu(&cau1, "Vu");
    them_tu(&cau1, "Viet");
    them_tu(&cau1, "Thien");
    them_tu(&cau1, "ET1");
    them_tu(&cau1, "trai");
    them_tu(&cau1, "trai");
    them_tu(&cau1, "try");
    // Tao danh sach chua thong tin ve so lan xuat hien cua moi tu
    listinfor infor;
    list_infor(&infor);
    // Xac dinh tu xuat hien nhieu nhat
    Tim_tu_xuat_hien_nhieu_nhat(&cau1, &infor);
    loai_bo_tu_lay(&cau1);
    dem_so_tu_xuat_hien_trong_cau(&cau1);
    return 0;
}

