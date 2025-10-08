#include <iostream>

using namespace std;

int n, m;

int max_depth = 0;

int a[15], b[15];

int result[16] = {0};
int new_result[16] = {0};

int min_value = 15*15;


void ladder_game(int ladder[][16], int height, int width, int type){

	// cout << "------------\n";

	if(type == 1){

		for(int i = width; i<=n; i++){
			ladder[height][i] = 0;
		}
	
		for(int i=height+1; i<=max_depth; i++){
			for(int j=1; j<=n; j++){
	
				ladder[i][j] = 0;
			}
		}

	}

	// for(int i=1; i<=n;i++){
	// 	for(int j=1; j<=max_depth; j++){

	// 		if(ladder[j][i] == 1){
	// 			cout << i << ", " << j << "\n";
	// 		}
	// 	}
	// }

    
    for(int i=1; i<=n; i++){

        int currLine = i;

        for(int step = 1; step <= max_depth; step++){

            for(int dir = currLine -1; dir<= currLine; dir++){

                if(dir < 1 || dir >= n) continue;

                if (ladder[step][dir] == 1){

                    if (dir == currLine) currLine++;
                    else currLine--;

                    break;
                }

            }
        }
		new_result[i] = currLine;
        // cout << currLine << " ";
    }


	// cout << "\n";
	// cout << "------------\n";
}

void find_new_ladder(int ladder_info[][16], int line, int depth){


    int width = depth % (n-1);
    int height = depth / (n-1);
	width++;
	height++;


	ladder_game(ladder_info, height, width, 1);

	int cnt = 0;
	for(int i=1; i<=n; i++){

		if(result[i] == new_result[i]) {

			cnt++;
		}
	}

	if(cnt == n){


		// for(int i=1; i<=n;i++){
		// 	for(int j=1; j<=max_depth; j++){

		// 		if(ladder_info[j][i] == 1){
		// 			cout << i << ", " << j << "\n";
		// 		}
		// 	}
		// }

		// cout <<"found !! : " << line << "\n";
		min_value = min(min_value, line);

		// return;
	}


	if(depth > (n-1)* max_depth){ // 마지막 ladder
		return;
	}

	int previous_width = width - 1;

	if(previous_width == 0){

		ladder_info[height][width] = 0;
		find_new_ladder(ladder_info, line, depth + 1);

		ladder_info[height][width] = 1;
		find_new_ladder(ladder_info, line + 1, depth + 1);

	}
	else{

		if (ladder_info[height][width - 1] == 1) { // 

			ladder_info[height][width] = 0;
			find_new_ladder(ladder_info, line, depth + 1);

		}
		else{ 

			ladder_info[height][width] = 1;
			find_new_ladder(ladder_info, line + 1, depth + 1);
	
		}

	}

}


int main() {
    cin >> n >> m;

    int ladder_info[16][16] = {0};

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];

        ladder_info[b[i]][a[i]] = 1;

		max_depth = max(max_depth,  b[i]);
    }

    ladder_game(ladder_info, 0, 0, 0);

	for(int i=1; i<=n; i++){
		result[i] = new_result[i];
	}

	min_value = m;

	int new_ladder_info[16][16] = {0};

	find_new_ladder(new_ladder_info, 0, 0);

	cout << min_value << "\n";

    return 0;
}
