#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    
    string line;
    string word;
    unordered_map<string,int> mp;

    while(getline(cin, line)){
        if(line == "END") break;
        // now parse each word from the line
        for(int i = 0; i < line.size(); i++){
            // build word character by character
            if(line[i] == ' ' || i == line.size()-1){
                if(i == line.size()-1 && line[i] != ' ')
                    word += line[i];
                if(!word.empty()){
                    mp[word]++;
                    word = "";
                }
            } else {
                word += tolower(line[i]);
            }
        }
    }

    cout<<"Enter the number of queries: ";
    int k;
    cin>>k;
    unordered_map<string,int> mp1 = mp;
    
    for(int i=1;i<=5;i++){
        int maxFreq = 0;
        string maxWord = "";
        for(auto it : mp){
            string element = it.first;
            int count = it.second;
            if(count>maxFreq){
                maxFreq = count;
                maxWord = element;
            }
        }
        cout<<maxWord<<"->"<<maxFreq<<endl;
        mp.erase(maxWord);
    }

    while(k--){
        string word;
        cout<<"Enter the query: ";
        cin>>word;
        cout<<mp1[word]<<endl;
    }

    return 0;
}