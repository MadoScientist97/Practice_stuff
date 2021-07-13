#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace::std;


map<char,string> initransform(){
    string s="never used";
    std::map<char,string> hmap;
    for (int i=0 ; i<=25 ; i++) {
        char alpha = (char)(i+97);
        hmap.insert(std::pair<char, string>(alpha,s));
    }
    return hmap;
}

char gethash (string s){
    char last = *(s.end());
    return last;
}

int main(int argc, char* argv[]){
    
    return 0;
    }
