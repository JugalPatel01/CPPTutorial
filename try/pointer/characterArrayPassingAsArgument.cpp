#include<iostream>
using namespace std;
void print(char* c){
    while (*c != '\0'){
        printf("%c",*c);
        c++;
    }
}
int main() {
char c[20] = "hello"; // string gets stored in the space for array. here we can change it's value by indexing
// char *c = "hello"; // string gets stored as compile time constant. so here we can't change it's value by indexing.
print(c);

return 0;
}