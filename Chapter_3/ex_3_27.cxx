int fix(int i){
    return 4+i;
}

int main(){
    int ia[fix(3)];  //correct; why to determine if a function is constexpr function???
    return 0;
}
