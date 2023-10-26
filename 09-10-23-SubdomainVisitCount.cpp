/*
    Time O(m*n) m ==  cpdomains.size() | n == fullDomain.size() -> size biggestDomain
    Space = O(k) == cpdomains.size()

*/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
      
      unordered_map<string, int> subDomains;

      for(int i = 0 ; i < cpdomains.size(); i++){ //O(m) m ==  cpdomains.size()

        int spacePosition = cpdomains[i].find(" ");
        // get number
        string visitCount = cpdomains[i].substr(0, spacePosition);
        int visitCountInt = stoi(visitCount); // O(1)
        string fullDomain = cpdomains[i].substr(spacePosition+1, cpdomains[i].size());         
          
          
        // find all sub domains
          

        subDomains[fullDomain] += visitCountInt;
        vector<string> tokens =  getTokens(fullDomain);

        for(int i = 0; i < tokens.size(); i++) {
            subDomains[tokens[i]] += visitCountInt;
        }

      }  
        vector<string> ans;
        for(auto domain :subDomains) {
            ans.push_back(to_string(domain.second)+ " " + domain.first );
        }
         
        return ans;
    }

    vector<string> getTokens(string fullDomain){ //O(n) n == fullDomain.size()
        int start = 0;
        int dotPosition = fullDomain.find('.');

        vector<string> ans;

        while(dotPosition != -1){
            

            string subDomain = fullDomain.substr(dotPosition+1, fullDomain.size());
             ans.push_back(subDomain);
             start = dotPosition+1;
            dotPosition = fullDomain.find('.', start);


        }

        return ans;

    }
};