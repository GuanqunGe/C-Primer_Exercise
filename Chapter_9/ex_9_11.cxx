#include <vector>

int main(){
 
    std::vector<int> vec1; //default constructor, vec1 is empty
    std::vector<int> vec2(10); //vec2 has 10 int elements, each initialized to 0
    std::vector<int> vec3(10, 1); //vec3 has 10 int elements, each initialized to 1
    std::vector<int> vec4 = {1, 2, 3, 4}; //vec4 has 4 int elements, each initialized to  1,2,3,4 respectively
    std::vector<int> vec5 = vec2; //vec5 is initialized to hold the same number and elements as vec2
    std::vector<int> vec6 =( vec4.begin(), vec4.end() ); //vec6 is initialized as a copy of vec4
   
    return 0;
}
