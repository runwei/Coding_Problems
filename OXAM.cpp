#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<cmath>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class orderbook{
public:
	orderbook(){}
	void insert(int id, double price){
		id_map[id] = price;
		price_set.insert(price);
	}
	void erase(int id){
		double price = id_map[id];
		id_map.erase(id);
		price_set.erase(price_set.find(price));
	}
	double get_highest(){
		if (!price_set.empty()) return *price_set.begin();
		else return std::numeric_limits<double>::quiet_NaN();
	}
private:
	unordered_map<int,double> id_map;
	multiset<double,std::greater<double> > price_set;
};

vector<string> split(const string &txt, char ch){
	vector<string> strs;
    int pos = txt.find(ch),initialPos = 0;
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
        pos = txt.find(ch, initialPos);
    }
    strs.push_back(txt.substr( initialPos));
    return strs;
}

int main() {
	orderbook ob = orderbook();
	ifstream infile("input.txt");
	if (infile.is_open()){
		string line; // the string on each line
		int lasttime=-1; // the last timestamp of the previous time period
		double lastprice = std::numeric_limits<double>::quiet_NaN(); // the price in the last time period
		int sumtime = 0;
		double sumweighttime = 0.0;
		while (getline (infile,line)){
			vector<string> vec_s = split(line,' ');
			if (!vec_s[1].compare("I")) {
				ob.insert(stoi(vec_s[2]),stod(vec_s[3])); 
			} else if (!vec_s[1].compare("E")){
				ob.erase(stoi(vec_s[2]));
			}
			int curtime = stoi(vec_s[0]);
			double curprice = ob.get_highest();
			if (!isnan(lastprice)) {
				if (isnan(curprice) || curprice!=lastprice) {
						sumtime += curtime- lasttime;
						sumweighttime += (curtime- lasttime)*lastprice;
						cout<< lasttime<<" "<<curtime<<" "<<lastprice<<endl;
						lastprice = curprice;
						lasttime = curtime;
				}
			} else {
				lastprice = curprice;
				lasttime = curtime;
			}
	    }
		cout<< sumweighttime/sumtime<<endl;
	    infile.close();
	}
	return 0;
}