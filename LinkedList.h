#include<iostream>
#include<string>
using namespace std;
struct Ngay
{
	int ngay, thang, nam;
};
struct SinhVien
{
	int maSV;
	string hoTen;
	string gioiTinh;
	Ngay ngaySinh;
	string diaChi;
	string lop;
	string khoa;
};

struct Node
{
	SinhVien data;
	Node *link;
};
struct List
{
 	Node *first;
	Node *last;
};
typedef Node* listNode;
listNode Create_Node(SinhVien sv){
    Node* node = new Node;
    node->data.diaChi = sv.diaChi;
    node->data.gioiTinh = sv.gioiTinh;
    node->data.hoTen = sv.hoTen;
    node->data.khoa = sv.khoa;
    node->data.lop = sv.lop;
    node->data.maSV = sv.maSV;
    node->data.ngaySinh.nam = sv.ngaySinh.nam;
    node->data.ngaySinh.ngay = sv.ngaySinh.ngay;
    node->data.ngaySinh.thang = sv.ngaySinh.thang;
    node->link = nullptr;
    return node;
}
void OverCin(SinhVien &sv){
    cout << "Dia chi: ";
    getline(cin, sv.diaChi);
    cout << "Gioi tinh: ";
    getline(cin, sv.gioiTinh);
    cout << "Ho Ten: ";
    getline(cin, sv.hoTen);
    cout << "Khoa: ";
    getline(cin, sv.khoa);
    cout << "Lop: ";
    getline(cin, sv.lop);
    cout << "MSSV: ";
    cin >> sv.maSV;
    cout << "Ngay sinh: ";
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
}
void List_init(List* list){
    list->first = nullptr;
}
void Insert_Resp(List* list, listNode node){
       if(list->first == nullptr || list->first->data.maSV > node->data.maSV){
          node->link = list->first;
          list->first = node;
          return;
       }
       listNode q = list->first;
       while(q->link != nullptr && q->link->data.maSV <= node->data.maSV ){
        q = q->link;
       }
       node->link = q->link;
       q->link = node;
}
void OverCout(SinhVien &sv){
    cout << "Dia chi: "<< sv.diaChi << '\n';
    cout << "Gioi Tinh: " << sv.gioiTinh << '\n';
    cout << "Ho Ten: " << sv.hoTen << '\n';
    cout << "Khoa: " << sv.khoa << '\n';
    cout << "Lop: " << sv.lop << '\n';
    cout << "MSSV: " << sv.maSV << '\n';
    cout << "Nam sinh: " << sv.ngaySinh.nam << '\n';
}
void Display_List(List* list){
    int i=1;
    listNode p = list->first;
    while(p != nullptr){
        cout << "Sinh vien " << i << ": " <<'\n'; 
        OverCout(p->data);
        p=p->link;
        i=i+1;
    }
}
void List_Add(List* list){
    while(true){
        char c;
        cout << "Ban muon nhap them sinh vien khong Y/N: ";
        cin >> c;
        cin.ignore();
        if(c == 'n' || c == 'N'){break;}
        SinhVien sv;
        OverCin (sv);
        listNode p = Create_Node(sv);
        Insert_Resp(list, p);
    }
}
void Delete_Node(List* list, listNode node){
    listNode p = list->first;
    while(p->link != node){
        p = p->link;
    }
    p->link = node->link;
    delete node;
}
void Same_Birthday(List* list){
    while(true){
    char c;
    cout << "Ban muon tim sinh vien trung ngay sinh khong Y/N: ";
    cin >> c;
    cin.ignore();
    if(c == 'n' || c == 'N'){break;}
    int n;
    cout << "Hay chon ngay sinh 1-31: ";
    cin >> n;
    listNode p = list->first;
    while(p!= nullptr){
        if(p->data.ngaySinh.ngay != n){
            p = p->link;
        } 
        else{
            OverCout(p->data);
        }
    }
    }   
}
void Delete_Same_Birthday(List* list){
    while(true){
    char c;
    cout << "Ban muon xoa sinh vien cung ngay sinh khong Y/N: ";
    cin >> c;
    cin.ignore();
    if(c == 'n' || c == 'N'){break;}
    int n;
    cout << "Hay chon ngay sinh 1-31: ";
    cin >> n;
    listNode p = list->first;
    while(p!= nullptr){
        if(p->data.ngaySinh.ngay == n){
            Delete_Node(list, p);
    }
    }   
}
}
void List_Input(List* list){
    while(true){
        char c;
        cout << "Ban muon nhap tiep danh sach khong Y/N: ";
        cin >> c;
        cin.ignore();
        if(c == 'N' || c== 'n') {break;}
        SinhVien sv;
        OverCin(sv);
        listNode p = Create_Node(sv);                                                                                                                                                                                  Create_Node(sv);
        Insert_Resp(list, p);
    }
}
void List_Delete(List* list){
    Node* current = list->first;
    while(current != nullptr){
        Node* next = current->link;
        delete current;
        current = next;
    }
    delete list;
}