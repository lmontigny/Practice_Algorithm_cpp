#include <iostream>
#include <stack>

int main(){
	std::stack<int> my_stack;
	my_stack.push(12);
	my_stack.push(19);
	my_stack.push(11);

	// LIFO
	while(!my_stack.empty()){
		std::cout << my_stack.top() << std::endl;
		my_stack.pop();
	}
}

