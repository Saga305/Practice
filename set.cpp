#include<iostream>
#include<set>
using namespace std;


int main()
{
//Create a simple set with < sorting.
	set<int> s;

//Insert values in set.
	for (int i = 0; i < 10; i++)
	{
		s.insert(2*i);
	}

//Iterate over a set and print values to the console.
	set<int>::iterator it;
	for(it = s.begin(); it!=s.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

//Insert duplicate values and print the set.
	s.insert(1);
	
	for(it = s.begin(); it!=s.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

//Create a set with > sorting.
	set<int,greater<int> > st;

//Insert values in > sort set from < sort set.
	for(it = s.begin(); it!=s.end(); it++)
	{
		st.insert(*it);
	}

//Iterate over > sort set and print the values to the console.
	set <int, greater <int> > :: iterator itr;
	for(itr = st.begin(); itr!=st.end(); itr++)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;

	cout<<*s.lower_bound(1)<<endl;
	cout<<*s.lower_bound(9)<<endl;

	cout<<*s.upper_bound(1)<<endl;
	cout<<*s.upper_bound(11)<<endl;
	
	cout<<*st.lower_bound(1)<<endl;
	cout<<*st.lower_bound(9)<<endl;

	cout<<*st.upper_bound(1)<<endl;
	cout<<*st.upper_bound(11)<<endl;


}
