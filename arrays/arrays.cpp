#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    cout << "Enter size of array:\n";
    int n;
    cin >> n;
    vector<int> v(n);
    cout<<"Enter "<<n<<" int array elements:";
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << "Integer array:";
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout<<"Enter "<<n<<" char array elements:";
    vector<char> c(n);
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    cout << "Char array:";
    for(int i=0;i<n;i++){
        cout << c[i] << " ";
    }
    cout<<"Enter "<<n<<" float array elements:";
    vector<float> f(n);
    for(int i=0;i<n;i++){
        cin >> f[i];
    }
    cout << "Float array:";
    for(int i=0;i<n;i++){
        cout << f[i] << " ";
    }
}