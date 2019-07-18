#include <iostream>
#include <queue>

int main(){
	std::queue<int> queue;
	queue.push(0);
	queue.push(99);

	// FIFO
	while(!queue.empty()){
		std::cout << queue.front() << std::endl;
		queue.pop();
	}
}

