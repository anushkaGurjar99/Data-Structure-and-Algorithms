
### Setting priorities 

greater would cause the smallest element to appear as the top().  <br>
less would cause the largest element to appear as the top().  <br>
Beside greater and less, we can create our custom comparator with function or custom class or struct. <br>
	declare a class "same as named in 3rd parameter" and overload operator() for it
		
	
### Custom sort comparator (for heap and inbuild sort())
	struct comparator{
        bool operator()(const string& one, const string& two){
            for(int i = 0; i < one.size() && i < two.size(); i++){
                if(one[i] != two[i])
                    return one[i] < two[i];
            }
            return one.size() < two.size();
        }
    }comp;
    
for sort() you need to call comp but for PQ/heap you can directly call the struct
