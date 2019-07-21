#include <iostream>
#include <unordered_map>

int main()
{
        std::unordered_map<int, int> hash_table;

        // Key-value pair
        hash_table.insert({ 10,1});
        hash_table.insert({ 1299,2});
        hash_table.insert({ 82938,3});

        // Change value
        hash_table[133] = 99999;

        // Loop
        std::unordered_map<int,int>::iterator itr;
        for(itr=hash_table.begin(); itr!=hash_table.end(); itr++){
                std::cout << itr->first << std::endl;
        }
}

/*
                  | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |

search time     | log(n)              | O(1) -> Average
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search

Deletion time   | log(n) + Rebalance  | Same as search

*/
