#include <iostream>  // For input and output
using namespace std;

void pattern1(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern4(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern5(){
    int n;
    cin >> n;
    for(int i = n; i > 0; i--){
        for(int j = i; j > 0; j--){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern7(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            cout << " ";
        }
        for(int j = 1; j <= 2*i-1; j++){
            cout << "*";
        } 
        for(int j = 1; j <= n-i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int j = 0; j < 2*n - 2*i - 1 ; j++){
            cout << "*";
        } 
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern9(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            cout << " ";
        }
        for(int j = 1; j <= 2*i-1; j++){
            cout << "*";
        } 
        for(int j = 1; j <= n-i; j++){
            cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int j = 0; j < 2*n - 2*i - 1 ; j++){
            cout << "*";
        } 
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern10(){
    int n;
    cin >> n;
    for(int i = 1; i <= 2*n - 1; i++){
        int stars = i;
        if(i > n) stars = 2*n - i;
        for(int j = 1; j <= stars; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern11(){
    int n; 
    cin >> n;
    int start;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j <= i; j++){
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

void pattern12(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        for(int j = 1; j <= 2*n - 2*i; j++){
            cout << " ";
        }
        for(int j = i; j >= 1; j--){
            cout << j;
        }
        cout << endl;
    }
}

void pattern13(){
    int n;
    cin >> n;
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern14(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char ch = 'A';
        for(int j = 1; j <= i; j++){
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void pattern15(){
    int n;
    cin >> n;
    for(int i = n; i > 0; i--){
        char ch = 'A';
        for(int j = i; j > 0; j--){
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void pattern16(){
    int n;
    cin >> n;
    char ch = 'A';
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
}

void pattern17(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2*i+1) / 2;
        for(int j = 1; j <= 2*i + 1; j++){
            cout << ch;
            if(j <= breakpoint) ch++;
            else ch--;
        }
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern18(){
    int n;
    cin >> n;
    // char ch = 'E';
    // for(int i = 0; i < n; i++){
    //     char ch = 'A' + n - 1 - i;
    //     for(int j = 0; j <= i; j++){
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n; i++){
        for(char ch = 'A'+n-1-i; ch <= 'A'+n-1; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern19(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        for(int j = 0; j < 2*i; j++){
            cout << " ";
        }
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        for(int j = 1; j <= 2*(n-i); j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }    
}

void pattern20(){
    int n;
    cin >> n;
    for(int i = 1; i <= 2*n-1; i++){
        int star = i;
        int space = 2*(n-i);
        if(i > n){
            star = 2*n-i;
            space = i-star;
        }

        for(int j = 1; j <= star; j++){
            cout << "*";
        }
        for(int j = 1; j <= space; j++){
            cout << " ";
        }
        for(int j = 1; j <= star; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern21(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

void pattern22(){
    int n;
    cin >> n;
    for(int i = 0; i < 2*n-1; i++){
        for(int j = 0; j < 2*n-1; j++){
            int top = i;
            int left = j;
            int bottom = (2*n-2)-i;
            int right = (2*n-2)-j;
            cout << n - min(min(top, left), min(bottom, right)) << " ";
        }
        cout << endl;
    }
}

int main() {
    // Your code here
    pattern22();
    
    return 0;
}

