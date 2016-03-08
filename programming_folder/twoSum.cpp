//Problem: 2-Sum

#include <iostream>
#include <algorithm>
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
        
        void merge_sorting(vector<int>& nums) {
            
        }
        */

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
            std::sort(nums->begin(), nums->end());
            for (int i=0; i<SIZE; i++) {
                this->found = false;
                int integer_to_find = target-nums->at(i);
                int answer_element = find_binary_search(nums, integer_to_find, i, SIZE);
                if (this->found) {
                    answer->push_back(i);
                    answer->push_back(answer_element);
                    
                    return answer;
                }
            }
            
            return answer; //answer is an empty vector in this case
        }
};

int main(int argc, char* argv[]) {
    cout << "Program Begin\n" << endl;
    vector<int>* testing_vector = new vector<int>();
    testing_vector->push_back(5);
    testing_vector->push_back(2);
    testing_vector->push_back(1);
    int target = 3;

    Solution* sol = new Solution();

    vector<int>* answer = sol->twoSum(testing_vector, target);
    for(int i=0; i<answer->size(); i++) {
        cout << answer->at(i) << " ";
    }
    
    free(testing_vector);
    free(answer);
    free(sol);


    cout << "\nProgram Terminate" << endl;

    return 0;
}