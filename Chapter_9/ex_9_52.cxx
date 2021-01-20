#include <iostream>
#include <string>
#include <vector>
#include <stack>

//print a deque of char
std::ostream &print_deque(std::ostream &os, const std::deque<char> &deq){
    for(auto iter = deq.begin(); iter != deq.end(); ++iter)
	os << *iter;
    return os;
}

// simplify expressions in terms of parentheses [this version is very limited]
// exit immediately if it sees an unmatched ')'
// returning boolean means if all ')' have matched '(', not otherwise..
bool simplify_expression(const std::string &expr, std::stack<char, std::string> &simple_expr, std::vector<std::deque<char>> &vec_expr){
    // process each char in the expression, save it to the stack
    for(const auto &ch : expr){

	if(ch == ')'){ 
	    if(simple_expr.empty()){
		std::cerr << "Find an unmatched parenthesis, please try with correct expression " << std::endl;
		return false;
	    }

	    std::deque<char> local_expr{ch};
	    char local_ch;
	    do{
		local_ch = simple_expr.top();
		local_expr.push_front(local_ch);
		simple_expr.pop();	
 	    } while( !simple_expr.empty() && local_ch != '(');
	   
  	    if( simple_expr.empty() && local_ch != '('){
		std::cerr << "Find an unmatched parenthesis, please try with correct expression " << std::endl;
		return false;
	    }
	    simple_expr.push( 'A' + vec_expr.size());
	    vec_expr.push_back(local_expr);
        }else{
	     simple_expr.push(ch);
	}
    }

    return true;   
}

// second version of simplify_expression function
// wouldn't get interrupted even if it sees an unmatched ')'
// returning boolean means if the format of expression is right in terms of parenthesis matching.
bool simplify_expression_v2(const std::string &expr, std::stack<char, std::string> &simple_expr, std::vector<std::deque<char>> &vec_expr){

    unsigned num_left_parenthesis = 0;  //record the number of remaining left parentheses during the process
    bool is_correct_format = true;
 
    //loop over each character
    for(const auto &ch : expr){
	if( ch != ')'){
	    simple_expr.push(ch);
	    if(ch == '(') ++num_left_parenthesis;
        }
	else{  // if ch is ")"
	    if(num_left_parenthesis){  //if there is unmatched left parenthesis
		--num_left_parenthesis;

		// push everything before ')' in the stack into a local expr, until it sees an matched '('
		// local_expr will be the expression inside parentheses
		std::deque<char> local_expr{ch};
		do{
		    local_expr.push_front(simple_expr.top());
		    simple_expr.pop();
		} while( local_expr.front() != '(');

		// push a value into stack to represente that local_expr		
		simple_expr.push('A' + vec_expr.size());
		vec_expr.push_back(local_expr);  // push local_expr into a vector of parenthesized expressions
	    }
	    else{ // if there is no left parenthesis before it
		  // then we found an ummatched ')'
		simple_expr.push(ch);
		is_correct_format = false;
	    }
	} // end of big else
    } // end of for loop

    return is_correct_format && !num_left_parenthesis;
}


int main(){
   
    std::string expr; // a string to hold expression
    std::vector<std::deque<char>> vec_expr; // a vector to hold expressions inside parentheses
    std::stack<char, std::string> simplified_expr; // a stack to hold simplified expression
   
    std::cout << "Please enter an expression" << std::endl;
    std::cin >> expr;
    std::cout << expr << std::endl;

    //if(simplify_expression(expr, simplified_expr, vec_expr)){;
    if(simplify_expression_v2(expr, simplified_expr, vec_expr)){

	    std::cout << "Simplified expression is " << std::endl;
	  
    }
    else{
	std::cerr << "Invalid expression" << expr << std::endl;
	std::cout << "Best simplified expression is " << std::endl;
    }
	    
    //print out the sorted expression
    std::deque<char> simple_deq; 
    while( !simplified_expr.empty()){
	simple_deq.push_front(simplified_expr.top());
	simplified_expr.pop();
    }
    print_deque(std::cout, simple_deq) << std::endl;

    for(decltype(vec_expr.size()) i =0; i != vec_expr.size(); ++i){
	char name = 'A' + i;
	std::cout << name << ": ";
	print_deque(std::cout, vec_expr[i]) << std::endl;
    }
    return 0;
}
