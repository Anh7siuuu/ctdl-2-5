
#include "LinkedList.h"
int main(){
    List* ListSV = new List;
    List_init(ListSV);
    List_Input(ListSV);
    List_Add(ListSV);
    Display_List(ListSV);
    Same_Birthday(ListSV);
    Delete_Same_Birthday(ListSV);
    Display_List(ListSV);
    List_Delete(ListSV);
}