class Solution {
public:
void recursion(vector<int>&candidates, int target, vector<int>ds, set<vector<int>>&st, int index) 
{
	//base case 
    int n = candidates.size(); 
	if(index == n) 
	{
		if(target == 0) 
		{
			sort(ds.begin(), ds.end()); 
			st.insert(ds); 
		} 
		return; 
	} 

	//pick 
	if(candidates[index] <= target)
	{
		ds.push_back(candidates[index]); 
		recursion(candidates, target-candidates[index], ds, st, index);

		ds.pop_back(); 
	} 

	recursion(candidates, target, ds, st, index+1); 
} 
		
		


vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	//pick -> dont do ind+1
	// store ans in a set 
	// from st-> ans array 
	// if ind = n, place ds in the set if target = 0 
	// set, target, index, ds

	set<vector<int>>st; 
	vector<int>ds; 

	vector<vector<int>>ans; 
	recursion(candidates, target, ds, st, 0); 

	for(auto it : st)
	{
		ans.push_back(it); 
	} 

	return ans; 
}

};