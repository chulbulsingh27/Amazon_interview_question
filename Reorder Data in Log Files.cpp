Problem statement had some list of boxes and we need to sort those boxes based on old generation and new generation boxes
Some conditions were given similar to the one in reorder data in log files problem.
This was a very straightforward and easy problem.
  
  vector<string> reorderLogFiles(vector<string>& logs) {
     vector<pair<string,string>>dig;
     vector<pair<string,string>>log;
        for(auto i:logs)
        {
            string s = "";
            string t = "";
            bool flag = false;
            
                for(int j = 0;j < (int)i.size(); j++)
                {
                        if(i[j] == ' ' && flag == false)
                        {
                                flag = true;
                                continue;
                        }
                        if(flag == false)  s+=(char)(i[j]);
                        else t+=(char)(i[j]);
                }
                
                if(t[0]>= 'a' && t[0] <= 'z')
                        log.push_back({t,s});
                else
                        dig.push_back({t,s});
    }
            sort(log.begin(), log.end());
            vector<string>ans;
            for(auto i : log)
            {
                    ans.push_back((string)i.second + " " + i.first);
            }
            for(auto i : dig)
            {
                    ans.push_back((string)i.second + " " + i.first);
            }
            return ans;
    }
