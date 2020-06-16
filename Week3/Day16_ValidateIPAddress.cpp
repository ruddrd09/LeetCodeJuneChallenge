class Solution {
public:
    bool isv4(string ip) {
        stringstream ss(ip);
        string s;
        vector<string> x;
        while(getline(ss, s, '.')) {
            x.push_back(s);
        }
        string validString = "0123456789";
        if(x.size() == 4) {
            for(int i=0;i<4;i++) {
                if(x[i] == "" || x[i].size() > 1 && x[i][0] == '0' || x[i].size() > 3) {
                    return 0;
                } else {
                    for(int j=0;j<x[i].size();j++) {
                        if(validString.find(x[i][j]) == string::npos) {
                            return 0;
                        }
                    }
                    int z = stoi(x[i]);
                    if(z > 255 || z < 0) {
                        return 0;
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    
    bool isv6(string ip) {
        stringstream ss(ip);
        string s;
        vector<string> x;
        while(getline(ss, s, ':')) {
            x.push_back(s);
        }
        string validString = "0123456789abcdefABCDEF";
        if(x.size() == 8) {
            for(int i=0;i<8;i++) {
                if(x[i] == "" || x[i].size() > 4) {
                    return 0;
                }
                for(int j=0;j<x[i].size();j++) {
                    if(validString.find(x[i][j]) == string::npos) {
                        return 0;
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    
    string validIPAddress(string IP) {
        if(IP.size() == 0 || IP[IP.size()-1] == '.' || IP[IP.size()-1] == ':') {
            return "Neither";
        }
        bool x = isv4(IP);
        bool y = isv6(IP);
        if(x) {
            return "IPv4";
        } else if(y) {
            return "IPv6";
        }
        return "Neither";
    }
};