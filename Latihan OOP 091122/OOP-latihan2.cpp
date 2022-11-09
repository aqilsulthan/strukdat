#include <iostream>
using namespace std;

class MHS {
    private:
    string MHS1name = "Rahmat Budi";
    string MHS2name = "M Ali";
    
//     public:
//     string getNama1() {
//      return MHS1name;
//   };
   
//   string getNama2() {
//      return MHS2name;
//   }

    public:
    void getName(){
    cout << "MHS Name is: " << endl;
    cout << MHS1name << endl;
    cout << MHS2name;
    }
};

int main (){
    MHS mhs;
    mhs.getName();
    return 0;
}
