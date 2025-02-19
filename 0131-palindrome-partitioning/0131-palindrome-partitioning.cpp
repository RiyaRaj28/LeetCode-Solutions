class Solution {
public:
bool isPalindrome(int start, int end, string &s)
{
	if(start == end) return true; 

	while(start <= end) 
	{
		if(s[start++] != s[end--]) return false; 
    }
    return true; 
}  




void recursion(int start, vector<vector<string>>&ans, vector<string>&path, string &s) 
{
	//base case 
	if(start == s.size()) 
	{
		ans.push_back(path); 
		return; 
	} 

	//pick 
	for(int end = start; end <s.size(); end++)
	{
		string sub = s.substr(start, end-start+1); 
		if(isPalindrome(start, end, s))
		{
			path.push_back(sub); 
			recursion(end+1, ans, path, s); 
			path.pop_back(); 
		} 
	} 
} 

vector<vector<string>> partition(string s)
{
	vector<vector<string>>ans; 

	vector<string>path; 

	recursion(0, ans, path, s); 

	return ans; 
} 

};