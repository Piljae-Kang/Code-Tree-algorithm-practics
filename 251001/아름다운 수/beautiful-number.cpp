#include <iostream>
#include <vector>

using namespace std;

int n;

int beauty_num_cnt = 0;

bool is_beauy_num(vector<int> arr){

    int count[4] = {0, 0, 0, 0};

    int p_v = arr[0];

    int dup_cnt = 1;

    for(int i=1; i<arr.size(); i++){

        if(p_v == arr[i]){

            dup_cnt++;
        }
        else{

            if(dup_cnt % p_v != 0) return false;

            p_v = arr[i];
            dup_cnt = 1;
        }
    }

    if(dup_cnt % p_v != 0) return false;

    return true;

}

void seq_func(vector<int>& num_seq, int depth){


    if(depth == n){

        if(is_beauy_num(num_seq)) beauty_num_cnt++;

        return;

    }

    for(int i=1; i<=4; i++){

        num_seq.push_back(i);
        seq_func(num_seq, depth + 1);

        num_seq.pop_back();
    }




}


int main() {
    cin >> n;

    // Please write your code here.

    vector<int> num_seq;

    seq_func(num_seq, 0);


    cout << beauty_num_cnt << "\n";

    return 0;
}
