#include <iostream> 
#include <map> 
#include <string> 
#include <utility> 
 
using namespace std; 
 
int main() 
{ 
 typedef map<string,int> mapType; 
 mapType populationMap; 
  
 populationMap.insert(pair<string, float>("Maharashtra", 125)); 
 populationMap.insert(pair<string, float>("Uttar Pradesh", 225)); 
 populationMap.insert(mapType::value_type("Bihar", 120));  
 populationMap.insert(mapType::value_type("West Bengal", 100));  
 populationMap.insert(make_pair("Madhya Pradesh", 90));  
 populationMap.insert(make_pair("Tamil Nadu", 80));  
 populationMap.insert(make_pair("Rajasthan", 78)); 
 populationMap.insert(make_pair("Andhra Pradesh", 53)); 
 
 
  
 mapType::iterator iter = --populationMap.end(); 
 populationMap.erase(iter); 
   
 cout << "Total state and UT of India with Size of populationMap: " << populationMap.size() 
<< '\n'; 
  
 for (iter = populationMap.begin(); iter != populationMap.end(); ++iter)  
 { 
  cout << iter->first <<":" << iter->second << " million\n"; 
 } 
  
 char c; 
 do 
 { 
  string state; 
  cout<<"\nEnter that state you want to know the population of: "; 
  cin>>state; 
  iter = populationMap.find(state); 
  if( iter != populationMap.end() )  
      cout << state <<"'s populations is " 
          << iter->second << " million\n"; 
  else 
      cout << "State is not in populationMap" << '\n'; 
       
  cout<<"Do you wish to continue?(y/n):"; 
  cin>>c; 
 }while(c=='y'||c=='Y'); 
   
 populationMap.clear(); 
  
 return 0; 
}
