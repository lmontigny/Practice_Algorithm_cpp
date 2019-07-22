#include <iostream>

int htable_size = 16;

// Class with key,value pair for each entry
class HashEntry{
	public:
		int key;
		double value;

		HashEntry(int key, double value){
			this->key = key;
			this->value = value;
		}
};

// Class for the hash table with N HashEntry()
class HashTable{
	private:
		HashEntry **htable; //array of pointer, each pointer will point to a HashEntry
	public:
		HashTable(); 
		~HashTable();
		void insert(int key, double value);
		void get(int key);
		void remove(int key);
		void print();
};

// Init the htable to NULL for each HashEntry
HashTable::HashTable(){
	htable = new HashEntry * [htable_size];
	for(int i=0; i<htable_size; i++){
		htable[i] = NULL;
	}
}

// Destructor
HashTable::~HashTable(){
	for(int i=0; i<htable_size; i++){
		delete htable[i];
	}
	delete[] htable;
}

// Insert by checking if the table is key is already taken
void HashTable::insert(int key, double value){
	int idx = key%htable_size;
	while(htable[idx] !=NULL && htable[idx]->key != key){
		idx = (idx+1) % htable_size;
	}
	htable[idx] = new HashEntry(key, value);
	if(idx == htable_size-1) std::cout << "Htable full" << std::endl;
}

// Same as insert
void HashTable::get(int key){
	int idx = key%htable_size;
	while(htable[idx] !=NULL && htable[idx]->key != key){
		idx = (idx+1) % htable_size;
	}
	if(idx == htable_size-1) std::cout << "Key not found" << std::endl;
	else std::cout << "Key found, value = " << htable[idx]->value << std::endl;
}

// Difference here, searching for the specific key
void HashTable::remove(int key){
	int idx = key%htable_size;
	while(htable[idx] !=NULL){
		if(htable[idx]->key = key) {
			break;
		}
		idx = (idx+1) % htable_size;
	}
	if(idx == htable_size-1) std::cout << "Key not found" << std::endl;
	else{
		htable[idx] = NULL;
	}
}

void HashTable::print(){
	std::cout << "Htable size " << htable_size << std::endl;
	for(int i=0; i<htable_size; i++){
		if(htable[i])
		std::cout << "key " <<htable[i]->value 
			<< " value " << htable[i]->key << std::endl;
	}
}

int main(){
	HashTable my_table;
	my_table.insert(3,99);
	my_table.insert(18,99);
	my_table.get(18);
	my_table.remove(18);
	my_table.print();
}
