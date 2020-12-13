int main(){

    int null = 0, *p = null;   //wrong
    int null = 0, *p = &null;  // p points to variable null
    int null = 0, *p = nullptr;  // p is initialized as a null pointer
    return 0;
}
