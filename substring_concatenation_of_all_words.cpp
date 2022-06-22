#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<vector>

#include "utils.h"

using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &v) {
    os <<"[";
    for (auto it= v.begin(); it != v.end();it++){
        os<<*it;
        if (it!=v.end()-1) os << ",";
    }
    os<<"]\n";
    return os;
}

template <typename T,typename V>
ostream& operator<<(ostream& os, const multimap<T,V> &v) {
    os <<"the hash multi map is : {";
    for (const auto &[key,value]:v){
        os<<"("<<key<<","<<value<<")";
        
    }
    os<<"}\n";
    return os;
}

template <typename T,typename V>
ostream& operator<<(ostream& os, const unordered_map<T,V> &v) {
    os <<"the unordered_map is : {";
    for (const auto &[key,value]:v){
        os<<"("<<key<<","<<value<<")";
        
    }
    os<<"}\n";
    return os;
}
auto print_key_value = [](const auto &key, const auto &value){
        std::cout<< "Key:["<<key<<"] Value: ["<<value<<"]\n";
    };

class Solution {
public:
    void searching(std::multimap<string,string> &hash,std::multimap<string,int> &hash2, std::multimap<string,int> hash_words ,string &word,vector<int> &resultIndices){ 
                int count=0;
                int sizeOfWords = hash_words.size();
                std::cout<<"countin 0st loop: "<<sizeOfWords<<"--"<<count<<std::endl;
                auto search = hash.find(word);
                auto searchInHash2 = hash2.find(word);
                int Number = hash.count(word);
                for (int repeat=0;repeat<Number;repeat++)
                {
                    count++;
                    print_key_value(search->first,search->second);
                    std::cout<<"countin 1st loop: "<<word<<"--"<<count<<std::endl;
                    auto hash_words_temp = hash_words;
                    auto deleteInHashWords = hash_words.find(search->first);
                    if (deleteInHashWords!= hash_words.end()) hash_words.erase(deleteInHashWords);
                    auto searchVector = hash_words.find(search->second);
                     int NumberWords = hash_words.count(search->second);
                for (int repeatWords=0;repeatWords<NumberWords;repeatWords++)
                    {
                        count++;
                        std::cout<<"countin 2nd loop: "<<count<<std::endl;
                        searching(hash,hash2,hash_words,search->second,resultIndices);
                        ++searchVector;
                    }
                    
                 ++search;   
                }
        std::cout<<"size of words: "<<sizeOfWords<<"--"<<count-1<<"--"<<word<<"--"<<std::endl;
                if (count-1==sizeOfWords){
                    auto searchHashIndex = hash2.find(word);
                    if (searchHashIndex!= hash2.end())
                    resultIndices.push_back(searchHashIndex->second);
                }
                
                
    }
   
  

    vector<int> findSubstringcheck(string s, vector<string>& words) {
        vector<int> resultIndices;
        
        int length = words[0].size();
        int substrLength = length*words[0].size();
        std::multimap<string,int> hash_words ;
        for ( int i=0;i<words.size() ; i++){
            hash_words.insert(std::pair<string,int>(words[i],i ));
        }
        int i=0;
        if (words[0].size()>s.size()) return resultIndices;
        while(i<length)
        {   
            std::unordered_map<string,int> hash_count;
            auto hash_words_temp = hash_words;
            int j =i;
            int index =i;
            int count = 0;
            while( j<s.size()-length+1){    
                std::cout<<hash_count;
                auto searchHashIndex = hash_words_temp.find(s.substr(j,length));
                auto number  = hash_words_temp.count(s.substr(j,length));
                
                std::cout<<"-----------######################################################--------------"<<index<<"-"<<i<<"-"<<j<<"--"<<s.substr(i+j,words[0].size())<<std::endl;
                //auto searchHashNext = hash_words_temp.find(s.substr(words[0].size()+i,words[0].size()));
                if (searchHashIndex!= hash_words_temp.end() ){
                    hash_count[s.substr(j,length)]++;
                    count++;
                    while(hash_count[s.substr(j,length)]> hash_words_temp.count(s.substr(j,length))){
                        hash_count[s.substr(index,length)]--;
                        index +=length;
                        count--;
                    }
                    // hash_words_temp.erase(searchHashIndex);
                    
                    
                    std::cout<<"count is :"<<count<<"-------------------------"<<s.substr(i+j,words[0].size())<<std::endl;
                    if (count==words.size()) resultIndices.push_back(index);
                     }
                // else if (count==pre_count)
                else{
                    std::cout<<"--------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!--------------"<<std::endl;
                    
                        hash_count.clear();
                        index =j+length;
                        count=0;
                    }
                    // if (count==1) index = i+j;
                    j=j+length;
                }
        i = i+1;
            //print_key_value(s.substr(i,words[0].size()),i);
        }
        

        
        return resultIndices;
    }
};

int main() {
    Solution solution;
    string s ="barfoothefoobarman";
    std::cout<< s<<std::endl;
    vector<string> words{"bar","foo"};
    vector<int> resultIndices = solution.findSubstringcheck(s,words);
    std::cout<<resultIndices;
}