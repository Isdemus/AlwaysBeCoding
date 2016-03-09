//Problem: 2-Sum

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        bool found;

        Solution() {
            this->found = false;
        }
        
        /*
        void sort_helper() {
            if(nums.size() == 1) {
                
            }
        }
        
        void merge_sorting(vector<int>& nutms) {
            
        }
        */

        void print_vector(vector<int>* nums) {
            if(nums != NULL) {


            cout << "\nBegin Priting Vector" << endl;


            /*
            for (int i=0; i<nums->size(); i++) {
                cout << nums->at(i) << endl;
            }
            */
            //using iterator version
            for (vector<int>::iterator it=nums->begin(); it != nums->end(); ++it) {
                cout << *it << endl;
            }

            
            cout << "Finished Printing Vector\n" << endl;
            }
        }

        int find_linear_search(vector<int>* nums, int target, int start_position, int size) {
            for (int i=start_position; i<size; i++) {
                if (nums->at(i) == target) {
                    return i;
                }
            }

            return -1; // this shouldn't happen
        }

        int find_binary_search(vector<int>* nums, int target, int min_position, int max_position) {
            int middle = (min_position+max_position)/2;
            int result = nums->at(middle);

            if (min_position >= max_position) {
                return 0;
            } else if (result == target) {
                this->found = true;
                return middle;
            } else if (result > target) {
                return find_binary_search(nums, target, min_position, middle);
            } else {
                return find_binary_search(nums, target, middle, max_position);
            }
        }
        
        vector<int>* twoSum(vector<int>* nums, int target) {
            vector<int>* answer = new vector<int>();
            
            //brute force way:
            const int SIZE = nums->size();
            /*
            for (int i=0; i<SIZE; i++) {
                for (int j=i+1; j<SIZE; j++) {
                    if (nums[i]+nums[j] == target) {
                        answer->push_back(i);
                        answer->push_back(j);
                        return answer;
                    }
                }
            }
            */
            
            //better way: sort the array (n log n) + using binary search to find if there is a desired pair
            //merge_sorting(nums);
            vector<int>* copied_nums = new vector<int>(*nums);
            std::sort(copied_nums->begin(), copied_nums->end());
            for (int i=0; i<SIZE; i++) {
                this->found = false;
                int integer_to_find = target-nums->at(i);
                int answer_element_entity = find_binary_search(copied_nums, integer_to_find, i, SIZE);
                
                if (this->found) {
                    int answer_to_find = copied_nums->at(answer_element_entity);
                    int answer_element = find_linear_search(nums, answer_to_find, i, SIZE);

                    answer->push_back(i);
                    answer->push_back(answer_element);
                    
                    return answer;
                }
            }
            
            return answer; //answer is an empty vector in this case (this shouldn't happen)
        }

        //using hashmap (unordered set), it now has O(n) time complexity
        vector<int>* twoSumSecond (vector<int>* nums, int target) {
            vector<int>* answer = new vector<int>();
            unordered_map <int, int> our_hash; //key, value, index

            int SIZE = nums->size();
            for (int i=0; i<SIZE; i++) {
                int value = nums->at(i);
                if (our_hash.count(value) > 0) {
                    answer->push_back(our_hash[value]);
                    answer->push_back(i);

                    return answer;
                } else {
                    our_hash.insert (std::make_pair(value, i));
                    our_hash.insert (std::make_pair(target-value, i));
                }
            }

            return answer;
        }
};

int main(int argc, char* argv[]) {
    cout << "Program Begin\n" << endl;
    int input_list [] = {1, 5, 2};
    vector<int>* testing_vector = new vector<int>(input_list, input_list + sizeof(input_list) / sizeof(int));

    int target = 3;

    Solution* sol = new Solution();

    //vector<int>* answer = sol->twoSum(testing_vector, target);
    vector<int>* answer = sol->twoSumSecond(testing_vector, target);
    //sol->print_vector(testing_vector);
    cout << "Answer: ";
    sol->print_vector(answer);

    free(testing_vector);
    free(answer);
    free(sol);


    cout << "\nProgram Terminate" << endl;

    return 0;
}