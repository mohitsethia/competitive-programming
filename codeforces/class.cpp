#include<iostream>
#include<algorithm>
using namespace std;
class car{
public:
    int price;
    string name;
    string model_no;
};
int main(){
    car a;
    
    cin >> a.name >> a.price >> a.model_no;
    car b(a);
    b.price = 1700;
    b.name = "Verna";
    cout << a.name << " " << a.price << " " << a.model_no << endl;
    cout << b.name << " " << b.price << " " << b.model_no << endl;
    return 0;
}
