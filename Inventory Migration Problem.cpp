Amazon has decided to migrate the inventory data to Amazon.com cloud from other platform. It has the following feature : The cheapest item will be displayed first ,

1st View returns the first cheapest item, similarly kth view returns the kth item in the list so far.
It is ensured that items already exist before the view query;
We have 2 kinds of operations "INSERT", "VIEW". "INSERT" inserts the item into the list, "VIEW" returns the cheapest element ( kth view returns k th cheapest element).

Input : we have each string with 3 entires [ "operation" , "item-name","cost"]
Return: result should be a vector of items when "View" Query comes up;

Eg : [["INSERT", "burger","4"],
["INSERT", "gum","1"],
["VIEW", "-" ,"-" ],
["INSERT", "chocolate","3"],
["INSERT", "PORK", "2"],
["VIEW","-","-"]]
Expected Result : ["GUM","PORK"]

//code

vector<string> ShoppingList(vector<vector<string>> entries){
	set<pair<int,string>> s;
	int views = 0;
	vector<string> ans;
	for(auto entry : entries){
		if(entry[0] == "INSERT")
			s.insert(make_pair(stoi(entry[2]),entry[1]));
		else{
			auto it = s.begin();
			advance(it,views);
			ans.push_back(it->second);
			views++;
		}
	}
	return ans;
}


//optimization

static String HI = String.valueOf((char)(127)); // STRING MAX
    static String LO = "";  // STRING MIN
    static int kthPrice;
    static String cur; // it is always the answer to the pending view query
    static TreeMap<Integer, TreeSet<String>> map = new TreeMap<>(Map.of(Integer.MAX_VALUE, new TreeSet<>(Set.of(LO))));

    static private void insert(String name, int price){
        if (map.size() == 1){ // initialization
            kthPrice = price;
            cur = HI;
        }
        map.computeIfAbsent(price, o -> new TreeSet<>()).add(name);

        if (price == kthPrice && name.compareTo(cur) < 0 || price < kthPrice){
            cur = map.get(kthPrice).lower(cur); // get the lower string when a lower item is inserted.
        }
        if (cur == null){ // if it reaches the bottom, get the lower string from the end of the lower price.
            kthPrice = map.lowerKey(kthPrice);
            cur = map.get(kthPrice).last();
        }
    }

    static private String view(){
        String ans = cur;
        cur = map.get(kthPrice).higher(cur); // go to higher string
        if (cur == null){ // if none, then go to the lowest string of next price
            kthPrice = map.higherKey(kthPrice);
            cur = map.get(kthPrice).first();
        }
        return ans;
    }
