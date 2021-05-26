//Completed on June 7th, 2019
//Note that this submission has a main function is not surrounded
//be a solution class as I ran some personal tests on it

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void printVector(vector<int> & nums) {

  for(int i=0; i<nums.size(); i++) {
    cout<<nums.at(i);
    cout<< " ";

  }

  cout<<""<<endl;

}

void wiggleSort(vector<int> & nums) {
  vector<int> set1;
  vector<int> set2;
  sort(nums.begin(), nums.end());

  if(nums.size()%2==0) {
    set1.assign(nums.begin(), nums.begin()+nums.size()/2);
    set2.assign(nums.begin()+nums.size()/2, nums.end());
  }
  else {
    set1.assign(nums.begin(), nums.begin()+nums.size()/2+1);
    set2.assign(nums.begin()+nums.size()/2+1, nums.end());
  }
  nums.clear();
  printVector(set1);
  printVector(set2);

  int it1=set1.size()-1;
  int it2=set2.size()-1;

  while(it1!=-1 || it2!=-1) {
    if(it1==-1) {
      void(0);
    }
    else {
      nums.push_back(set1.at(it1));
      it1--;
    }

    if(it2==-1) {
      void(0);
    }
    else {
      nums.push_back(set2.at(it2));
      it2--;
    }

  }
}

int main (void) {

  vector<int> testArray;
  testArray.clear();
  testArray.push_back(1);
  testArray.push_back(3);
  testArray.push_back(2);
  testArray.push_back(2);
  testArray.push_back(3);
  testArray.push_back(1);
  printVector(testArray);
  wiggleSort(testArray);
  printVector(testArray);
}


           