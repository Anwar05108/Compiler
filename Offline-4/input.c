int f(int e){
    return 2*e;
}

int g(int c, int d){
    int x;
    x=f(c)+c+d;
    return x;
}

int main(){
    int a,b;
    a=1;
    b=2;
    a=g(a,b);
    println(a);
    return 0;
}
