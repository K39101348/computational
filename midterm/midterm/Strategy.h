#ifndef Strategy_h
#define Strategy_h

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include<cmath>

/// Add Code Here --> 

/// <-- Add Code Here

using namespace std;
///              user  to  item tabel               RecomdList            At most K Proposed Items           user size      item size
void Algorithm(vector<vector<double> > Table, vector<vector<int> > &RecomdList, const int K, const int user_size, const int item_size)
{
    int count = 0;
    int countt = 0;
    vector<double>total(item_size);
    vector<double>average(item_size);
    vector<vector<double> >list(user_size);
    vector<double>averagee(user_size);
    vector<double>sum(user_size);
    vector<double>std1(user_size);
    for (int i = 0; i < user_size; i++) {
        list[i].resize(item_size);
    }
    int maximum=0;
    int maximum2=0;
     /**
     TABLE
     
     Index           Content
     int User        double Rating
     int Item
     
     
     Format
     Table[User][Item]=Rating
     
     
     STRUCTURE
     
     Table
     | User1
     |        --- Item1   Item2   Item4   ...
     |             R1      R2      R3
     |
     | User2
     |        --- Item2   Item5   Item7   ...
     |             R4      R5      R6
     |
     | User3
     |        --- Item3   Item4   Item6   ...
     |             R4      R5      R6
     :
     :
     
     
     */

     /**
     RECOMDLIST
     
     Index          Content
     int User       int Item
     int Idx
     
     
     Format
     Table[User][Idx]=Item
     
     STRUCTURE
     
     RecomdList
     | User1
     |        ---    0      1       2     ...    K-1
     |            Item3   Item8   Item9   ...   Item?
     |
     | User2
     |        ---    0      1       2     ...    K-1
     |            Item4   Item1   Item3   ...   Item?
     |
     | User3
     |        ---    0      1       2     ...    K-1
     |            Item5   Item7   Item1   ...   Item?
     :
     :
     
     */
    
    for (int i = 0; i < user_size; i++) {
        sum[i] =  0 ;
        countt = 0;
        for (int j=0; j < item_size; j++) {
            if (Table[i][j] >=0)
            {
                sum[i] += Table[i][j];
                countt++;
            }
        }
        averagee[i] = sum[i] / countt;
    }
   
    for (int i = 0; i < user_size; i++) {
        std1[i] = 0 ;
        countt = 0;
        for (int j=0; j < item_size; j++) {
            if (Table[i][j]>=0) {
                std1[i] += (Table[i][j]- averagee[i]) * (Table[i][j]- averagee[i]);
                countt++;
            }
        }
        std1[i] /= countt;
        std1[i] = sqrt(std1[i]);  
    }
    for (int i = 0; i < user_size; i++) {
        for (int j=0; j < item_size; j++) {
            if (Table[i][j] >=0) {
                Table[i][j] = 50+10*((Table[i][j] - averagee[i]) / std1[i]);
            }
            
        }
    }
    
    
    
    /* for (int x = 0; x < item_size ; x++) {
        count = 0;
        average[x] = 0;
        for (int y = 0; y < user_size ; y++) {
            if (Table[y][x] >= 0) {
                average[x] += Table[y][x];
                count++;
            }
        }
        if (count != 0) {
            average[x] = average[x] / count;
        }
    }
    for (int x = 0; x < item_size; x++) {
        for (int y = 0; y < user_size; y++) {
            list[y][x] = average[x];
        }
    }
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < user_size; i++) {
                maximum = 0;
                for (int j = 0; j < item_size; j++) {
                    if ((list[i][j] >= maximum) && (Table[i][j] < 0)) {
                        maximum = list[i][j];
                        maximum2 = j;
                    }
                }
                list[i][maximum2] = -2;
                RecomdList[i][k] = maximum2;
            }
        
    }*/
   
    
    for (int i=0; i < item_size; i++) {
        total[i] = 0;
        for (int j = 0; j < user_size; j++) {
            if (Table[j][i] > 0) {
                total[i] += Table[j][i];
            }
        }
        //cout << total[i] << endl; 
    }
    for (int x = 0; x < item_size; x++) {
        for (int y = 0; y < user_size; y++) {
            list[y][x] = total[x];
        }
    }
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < user_size; i++) {
            maximum = 0;
            for (int j = 0; j < item_size; j++) {
                if ((list[i][j] >= maximum) && (Table[i][j] < 0)) {
                    maximum = list[i][j];
                    maximum2 = j;
                }
            }
            list[i][maximum2] = -2;
            RecomdList[i][k] = maximum2;
        }
                //cout << RecomdList[i][k] << endl;

    }
    
    
    /*
    for (int i = 0; i < user_size; i++) {
        cout << "User_" << i << ": " << endl;
        for (int j = 0; j < K; i++) {
            cout << "Item_" << j << ": " << RecomdList[i][j] << endl;
        }
    }
    */

}

#endif /* Strategy_h */
