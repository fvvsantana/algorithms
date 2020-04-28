#include <iostream>
#include <stack>
#include <chrono>

using namespace std;

// factorial: recursive decrescent
int factRD(int n){
    if(n == 0){
        return 1;
    }
    return n * factRD(n-1);

}

// factorial: iterative decrescent
int factID(int n){
    int out = 1;
    // foo (int n) -> (int out)
    while(n != 0){
        out *= n;
        n--;
    }

    return out;
}

// factorial: iterative ascendent
int factIA(int n){
    int out = 1;
    int count = 1;
    // foo (int n) (int count) -> (int out)
    while(count <= n){
        out *= count;
        count++;
    }

    return out;
}

// factorial: iterative decrescent with Stack
// This method imitates the recursive decrescent method factRD.
int factIDS(int n){
    // foo  (int n) -> (stack<int> s)
    stack<int> s;
    while(n != 0){
        s.push(n);
        n--;
    }

    // foo (stack<int> s) -> (int out)
    int out = 1;
    while(!s.empty()){
        out *= s.top();
        s.pop();
    }
    return out;
}

int main(){
    int n = 100000;

    auto start = chrono::high_resolution_clock::now();
    factRD(n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    printf("factRD: %ld\n", duration.count());
    //std::chrono::duration<double> diff = stop-start;
    //printf("%lf\n", diff.count());


    start = chrono::high_resolution_clock::now();
    factID(n);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    printf("factID: %ld\n", duration.count());

    start = chrono::high_resolution_clock::now();
    factIA(n);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    printf("factAI: %ld\n", duration.count());

    start = chrono::high_resolution_clock::now();
    factIDS(n);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    printf("factIDS: %ld\n", duration.count());

    /*
    printf("%d\n", factRD(n));
    printf("%d\n", factID(n));
    printf("%d\n", factIA(n));
    printf("%d\n", factIDS(n));
    */
    return 0;
}
